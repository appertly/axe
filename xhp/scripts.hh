<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   MIT
 */

/**
 * Delays the render of scripts.
 */
class :axe:scripts extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %phrase, %metadata;
    children empty;
    attribute Axe\Page page @required,
        enum {"head", "body"} location = "body";

    protected function render(): XHPRoot
    {
        $frag = <x:frag/>;
        $scripts = $this->:location === "body" ?
            $this->:page->getBodyScripts() : $this->:page->getHeadScripts();
        foreach ($scripts as $script) {
            $frag->appendChild($script);
        }
        return $frag;
    }
}
