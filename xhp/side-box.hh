<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * A box that might appear in a sidebar.
 *
 * ```xml
 * <axe:side-box label="Hello World">
 *     <p>Anything</p>
 * </axe:side-box>
 * ```
 */
class :axe:side-box extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %sectioning;
    children (:axe:toolbar?, (pcdata | %flow)*);
    attribute :section,
        Stringish label @required;

    protected function render(): XHPRoot
    {
        $buttons = null;
        $inner = <div class="side-box-contents"/>;
        foreach ($this->getChildren() as $kid) {
            if ($kid instanceof :axe:toolbar) {
                $buttons = $kid;
                $kid->addClass('side-box-toolbar');
            } else {
                $inner->appendChild($kid);
            }
        }
        return <section class="side-box">
            <header class="side-box-header">
                <h1>{$this->:label}</h1>
                {$buttons}
            </header>
            {$inner}
        </section>;
    }
}
