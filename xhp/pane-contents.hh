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
        $buttons = null;
        $inner = <div class="pane-contents-inner"/>;
        foreach ($this->getChildren() as $kid) {
            if ($kid instanceof :axe:toolbar) {
                $buttons = $kid;
                $kid->addClass('pane-toolbar');
                $this->addClass(($kid->getChildren()->isEmpty() ? 'empty' : 'with') . '-toolbar');
            } else {
                $inner->appendChild($kid);
            }
        }
        if ($buttons === null) {
            $this->addClass('no-toolbar');
        }
        return <div class="pane-contents-outer">
            {$buttons}
            {$inner}
        </div>;
    }
}
