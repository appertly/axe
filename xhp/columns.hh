<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Columns
 */
class :axe:columns extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (pcdata | %flow)*;
    attribute :div;

    protected function render(): XHPRoot
    {
        $cols = <div class="columns clearfix"/>;
        foreach ($this->getChildren() as $child) {
            $cols->appendChild(
                <div class="column">
                    {$child}
                </div>
            );
        }
        return $cols;
    }
}
