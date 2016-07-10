<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * Human-readable file size.
 */
class :axe:pretty-bytes extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    private static array<string> $units = ['B', 'KiB', 'MiB', 'GiB', 'TiB', 'PiB', 'EiB', 'ZiB', 'YiB'];

    category %flow, %phrase;
    children empty;
    attribute :xhp:html-element,
        ?num value,
        ?NumberFormatter formatter,
        ?string locale;

    protected function render(): XHPRoot
    {
        $bytes = $this->:value ?? 0;
        $formatter = $this->:formatter;
        if ($formatter === null) {
            $formatter = new NumberFormatter($this->:locale ?? Locale::getDefault(), NumberFormatter::DECIMAL);
            $formatter->setAttribute(NumberFormatter::MAX_FRACTION_DIGITS, 2);
        }
        $factor = $bytes < 1 ? 0 : min(floor(log10($bytes) / 3), 8);
        return <abbr class="pretty" title={(is_float($bytes) ? '~' : '') . $formatter->format($bytes) . ' bytes'}>
            <span class="value">{$formatter->format($bytes / 1024 ** $factor)}</span>
            <span class="unit">{self::$units[$factor]}</span>
        </abbr>;
    }
}
