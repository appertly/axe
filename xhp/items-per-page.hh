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
class :axe:items-per-page extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children empty;
    attribute :ul,
        Stringish href = "",
        ConstMap<string,mixed> queryParams = ImmMap{},
        Stringish parameter = "count",
        int current = 10,
        ConstSet<int> items = ImmSet{10, 25, 50},
        Stringish prefix = '',
        Stringish suffix = 'items per page';

    protected function render(): XHPRoot
    {
        $pagination = <ul class="pagination"/>;
        $current = max(1, $this->:current);
        $params = $this->:queryParams->toMap();
        $href = $this->:href;
        $param = $this->:parameter;

        $prefix = (string) $this->:prefix;
        if ($prefix) {
            $pagination->appendChild(
                <li class="page-item disabled">
                    <span class="page-link">{$prefix}</span>
                </li>
            );
        }

        foreach ($this->:items as $item) {
            $pagination->appendChild(
                $this->numberedLink($item, $current, $href, $params, $param)
            );
        }

        $suffix = (string) $this->:suffix;
        if ($suffix) {
            $pagination->appendChild(
                <li class="page-item disabled">
                    <span class="page-link">{$suffix}</span>
                </li>
            );
        }
        return $pagination;
    }

    private function numberedLink(int $item, int $current, Stringish $href, Map<string,mixed> $params, Stringish $param): :li
    {
        if ($current === $item) {
            return <li class="page-item active">
                <span class="page-link">{$item}</span>
            </li>;
        } else {
            $params[(string) $param] = $item;
            $query = http_build_query($params);
            return <li class="page-item">
                <a href={"$href?$query"} class="page-link">{$item}</a>
            </li>;
        }
    }
}
