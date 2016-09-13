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
class :axe:checkboxes extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %phrase;
    children empty;
    attribute :div,
        Stringish name,
        ?Traversable<mixed> value,
        KeyedTraversable<string,mixed> options = [],
        bool inline = false;

    protected function render(): XHPRoot
    {
        $name = $this->:name;
        $id = $this->getID();
        $inputs = <div id={$id}/>;
        $this->transferAllAttributes($inputs);
        $values = Vector::fromItems($this->:value)->map($a ==> (string) $a)->toSet();
        if ($this->:inline) {
            foreach ($this->:options as $k => $v) {
                $inputs->appendChild(
                    <span class="form-check-inline">
                        <input type="checkbox" id={"$id-$k"} class="form-check-input" name={$name} value={$k} checked={$values->contains($k)}/>
                        <label for={"$id-$k"} class="form-check-label">{(string) $v}</label>
                    </span>
                );
            }
        } else {
            foreach ($this->:options as $k => $v) {
                $inputs->appendChild(
                    <div class="form-check">
                        <input type="checkbox" id={"$id-$k"} class="form-check-input" name={$name} value={$k} checked={$values->contains($k)}/>
                        <label for={"$id-$k"} class="form-check-label">{(string) $v}</label>
                    </div>
                );
            }
        }
        return $inputs;
    }
}
