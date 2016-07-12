<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Toolbar control
 */
class :axe:toolbar extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (:button)*;
    attribute :div,
        Stringish label = "";

    protected function render(): XHPRoot
    {
        return <div role="toolbar" aria-label={$this->:label}>
            {$this->getChildren()}
        </div>;
    }
}
