<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Columns with a golden ratio class.
 */
class :axe:columns-golden extends :axe:columns
{
    children (%flow, %flow);
    attribute :div,
        enum {'left', 'right'} big = 'right';

    protected function render(): XHPRoot
    {
        $cols = <div class="columns columns-golden clearfix"/>;
        foreach ($this->getChildren() as $child) {
            $cols->appendChild(
                <div class="column">
                    {$child}
                </div>
            );
        }
        $this->addClass("big-{$this->:big}");
        return $cols;
    }
}
