<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Pagination links
 */
class :axe:pagination extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children empty;
    attribute :ol,
        string href = "",
        ConstMap<string,mixed> queryParams = ImmMap{},
        string parameter = "page",
        int current = 1,
        int total = 1,
        bool short = false;

    protected function render(): XHPRoot
    {
        $pagination = <ul class="pagination"/>;
        $current = max(1, $this->:current);
        $total = max(1, $this->:total);
        if ($total === 1) {
            return $pagination;
        }
        $params = $this->:queryParams->toMap();
        $href = $this->:href;
        $param = $this->:parameter;

        $plabel = $this->:short ? <x:frag><span aria-hidden="true">&laquo;</span><span class="sr-only">Previous</span></x:frag> : "Previous";
        if ($current === 1) {
            $pagination->appendChild(
                <li class="page-item disabled">
                    <span class="page-link">{$plabel}</span>
                </li>
            );
        } else {
            $params[$param] = $current - 1;
            $query = http_build_query($params);
            $pagination->appendChild(
                <li class="page-item">
                    <a href={"$href?$query"} class="page-link" rel="prev">{$plabel}</a>
                </li>
            );
        }

        if ($total < 10) {
            for ($i = 1; $i <= $total; $i++) {
                $pagination->appendChild(
                    $this->numberedLink($i, $current, $total, $href, $params, $param)
                );
            }
        } else {
            $pagination->appendChild(
                $this->numberedLink(1, $current, $total, $href, $params, $param)
            );
            $pagination->appendChild(
                $this->numberedLink(2, $current, $total, $href, $params, $param)
            );

            $lstart = $total - $current >= 4 ? max(3, $current - 2) : $total - 6;
            $lend = $lstart + 4;

            if ($lstart > 3) {
                $pagination->appendChild(
                    <li class="page-item disabled"><span class="page-link page-gap">{"…"}</span></li>
                );
            }

            for ($i = $lstart; $i <= $lend; $i++) {
                $pagination->appendChild(
                    $this->numberedLink($i, $current, $total, $href, $params, $param)
                );
            }

            if ($lend < $total - 2) {
                $pagination->appendChild(
                    <li class="page-item disabled"><span class="page-link page-gap">{"…"}</span></li>
                );
            }

            $pagination->appendChild(
                $this->numberedLink($total - 1, $current, $total, $href, $params, $param)
            );
            $pagination->appendChild(
                $this->numberedLink($total, $current, $total, $href, $params, $param)
            );
        }

        $nlabel = $this->:short ? <x:frag><span aria-hidden="true">&raquo;</span><span class="sr-only">Next</span></x:frag> : "Next";
        if ($current === $total) {
            $pagination->appendChild(
                <li class="page-item disabled">
                    <span class="page-link">{$nlabel}</span>
                </li>
            );
        } else {
            $params[$param] = min($current + 1, $total);
            $query = http_build_query($params);
            $pagination->appendChild(
                <li class="page-item">
                    <a href={"$href?$query"} class="page-link" rel="next">{$nlabel}</a>
                </li>
            );
        }
        return $pagination;
    }

    private function numberedLink(int $page, int $current, int $total, string $href, Map<string,mixed> $params, string $param): :li
    {
        if ($current === $page) {
            return <li class="page-item active">
                <span class="page-link">{$page}</span>
            </li>;
        } else {
            $params[$param] = $page;
            $query = http_build_query($params);
            $link = <a href={"$href?$query"} class="page-link">{$page}</a>;
            if ($page === $total) {
                $link->setAttribute('rel', 'last');
            } elseif ($page === 1) {
                $link->setAttribute('rel', 'first');
            }
            return <li class="page-item">{$link}</li>;
        }
    }
}
