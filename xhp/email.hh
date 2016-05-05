<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Email Link
 */
class :axe:email extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %phrase;
    children (pcdata | %flow)*;
    attribute :xhp:html-element,
        ?Stringish email = '';

    protected function render(): XHPRoot
    {
        $text = trim((string) $this->:email);
        $kids = $this->getChildren();
        if ($kids->isEmpty()) {
            $kids = $text;
        }
        if (strlen($text) > 0) {
            return <a href={"mailto:$text"}>{$kids}</a>;
        } else {
            return <x:frag>{$kids}</x:frag>;
        }
    }
}
