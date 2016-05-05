<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * A fieldset intended to be used inline
 */
class :axe:fieldset-inline extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children (pcdata | %flow)*;
    attribute :fieldset,
        Stringish legend @required;

    protected function render(): XHPRoot
    {
        return <fieldset class="inline-fieldset">
            <legend><span class="legend-text">{$this->:legend}</span></legend>
            <div class="form-groups">
                {$this->getChildren()}
            </div>
        </fieldset>;
    }
}
