<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Breadcrumbs
 */
class :axe:breadcrumbs extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (:a)*;
    attribute :ul;

    protected function render(): XHPRoot
    {
        $frag = <x:frag/>;
        foreach ($this->getChildren() as $child) {
            $frag->appendChild(
                <li class="breadcrumb-item">
                    {$child}
                </li>
            );
        }
        return <ul class="breadcrumb">
            {$frag}
        </ul>;
    }
}
