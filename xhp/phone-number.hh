<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Phone Number Link
 */
class :axe:phone-number extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %phrase;
    children (pcdata | %flow)*;
    attribute :xhp:html-element,
        ?Stringish phone = '';

    protected function render(): XHPRoot
    {
        $text = trim((string) $this->:phone);
        $kids = $this->getChildren();
        if ($kids->isEmpty()) {
            $kids = $text;
        }
        if (strlen($text) > 0) {
            return <a href={"tel:$text"}>{$kids}</a>;
        } else {
            return <x:frag>{$kids}</x:frag>;
        }
    }
}
