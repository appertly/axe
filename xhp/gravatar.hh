<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Displays a Gravatar user image
 */
class :axe:gravatar extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    const URL = "https://secure.gravatar.com/avatar/";

    category %flow, %phrase;
    children empty;
    attribute :xhp:html-element,
        Stringish email @required,
        Stringish url = self::URL,
        Stringish default = 'identicon',
        enum {'g', 'pg', 'r', 'x'} rating = 'g',
        int size = 0;

    protected function render(): XHPRoot
    {
        $hash = md5(strtolower(trim((string) $this->:email)));
        $qs = Map{
            'd' => $this->:default,
            'r' => $this->:rating
        };
        $size = $this->:size;
        if ($size > 0) {
            $qs['s'] = $size;
        }
        $url = $this->:url . $hash . '?' . http_build_query($qs);
        $img = <img src={$url} alt="User avatar" />;
        if ($size > 0) {
            $img->setAttribute('width', $size);
            $img->setAttribute('height', $size);
        }
        return <span class="gravatar" role="presentation">
            {$img}
        </span>;
    }
}
