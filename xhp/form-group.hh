<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * A field label and input pair.
 */
class :axe:form-group extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (pcdata | %flow)*;
    attribute :div,
        bool required = false,
        bool inline = false,
        Stringish label @required,
        Stringish for @required;

    protected function render(): XHPRoot
    {
        $this->addClass('form-group');
        if ($this->:required) {
            $this->addClass('required');
        }
        if ($this->:inline) {
            $this->addClass('form-inline');
        }
        $for = $this->:for;
        return <div id={"form-group-$for"}>
            <div class="form-control-label">
                <label for={$for}>{$this->:label}</label>
            </div>
            <div class="form-control-input">
                {$this->getChildren()}
            </div>
        </div>;
    }
}
