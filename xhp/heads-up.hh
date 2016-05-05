<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * A message display.
 */
class :axe:heads-up extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (pcdata | %flow)*;
    attribute :xhp:html-element,
        enum {'emergency', 'alert', 'critical', 'error', 'warning', 'notice', 'info', 'debug'} status = 'info';

    protected function render(): XHPRoot
    {
        $kids = $this->getChildren();
        if ($kids->isEmpty()) {
            return <x:frag/>;
        }
        return <div class="heads-up">
            <div class={"alert alert-{$this->:status}"} role="alert">
                {$kids}
            </div>
        </div>;
    }
}
