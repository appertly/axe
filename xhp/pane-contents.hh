<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Pane Contents
 */
class :axe:pane-contents extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (:axe:toolbar?, %flow+);
    attribute :div;

    protected function render(): XHPRoot
    {
        $buttons = <x:frag />;
        $inner = <div class="pane-contents-inner"></div>;
        foreach ($this->getChildren() as $kid) {
            if ($kid instanceof :axe:toolbar) {
                $buttons = $kid;
                $kid->addClass('pane-toolbar');
            } else {
                $inner->appendChild($kid);
            }
        }
        return <div class="pane-contents-outer">
            {$buttons}
            {$inner}
        </div>;
    }
}
