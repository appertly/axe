<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Replaces newlines with paragraph tags.
 */
class :axe:paragraphs extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children empty;
    attribute :xhp:html-element,
        ?Stringish text = '';

    protected function render(): XHPRoot
    {
        $text = trim((string) $this->:text);
        $container = <div class="paragraph-text"/>;
        foreach (preg_split("/[\r\n]+/m", $text) as $line) {
            $container->appendChild(<p>{$line}</p>);
        }
        return $container;
    }
}
