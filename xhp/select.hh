<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * A select box and options
 */
class :axe:select extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow, %phrase, %interactive;
    children empty;
    attribute :select,
        ?Stringish value = null,
        bool blank = false,
        ConstMap<string,string> options = ImmMap{};

    protected function render(): XHPRoot
    {
        $s = <select/>;
        $this->transferAllAttributes($s);
        if ($this->:blank) {
            $s->appendChild(
                <option></option>
            );
        }
        $value = (string) $this->:value;
        foreach ($this->:options as $k => $v) {
            $s->appendChild(
                <option value={$k} selected={$k === $value}>{$v}</option>
            );
        }
        return $s;
    }
}
