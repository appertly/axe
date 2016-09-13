<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * A group of checkboxes
 */
class :axe:radios extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %phrase;
    children empty;
    attribute :div,
        Stringish name,
        mixed value,
        KeyedTraversable<string,mixed> options = [],
        bool inline = false;

    protected function render(): XHPRoot
    {
        $name = $this->:name;
        $id = $this->getID();
        $inputs = <div id={$id}/>;
        $this->transferAllAttributes($inputs);
        $value = (string) $this->:value;
        if ($this->:inline) {
            foreach ($this->:options as $k => $v) {
                $inputs->appendChild(
                    <span class="form-check-inline">
                        <input type="radio" id={"$id-$k"} class="form-check-input" name={$name} value={$k} checked={$value === $k}/>
                        <label for={"$id-$k"} class="form-check-label">{(string) $v}</label>
                    </span>
                );
            }
        } else {
            foreach ($this->:options as $k => $v) {
                $inputs->appendChild(
                    <div class="form-check">
                        <input type="radio" id={"$id-$k"} class="form-check-input" name={$name} value={$k} checked={$value === $k}/>
                        <label for={"$id-$k"} class="form-check-label">{(string) $v}</label>
                    </div>
                );
            }
        }
        return $inputs;
    }
}
