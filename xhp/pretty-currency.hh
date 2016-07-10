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
class :axe:pretty-currency extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    private static array<string> $units = ['', 'K', 'M', 'B', 'T'];

    category %flow, %phrase;
    children empty;
    attribute :xhp:html-element,
        ?num value,
        ?string currency,
        ?NumberFormatter formatter,
        string locale;

    protected function render(): XHPRoot
    {
        $money = (float) $this->:value ?? 0.0;
        $formatter = $this->:formatter;
        if ($formatter === null) {
            $formatter = new NumberFormatter($this->:locale ?? Locale::getDefault(), NumberFormatter::CURRENCY);
        }
        $currency = $this->:currency ?? $formatter->getSymbol(NumberFormatter::INTL_CURRENCY_SYMBOL);
        $factor = $money < 1 ? 0 : min(floor(log10($money) / 3), 4);
        return <abbr class="pretty" title={$formatter->formatCurrency($money, $currency)}>
            <span class="value">{$formatter->formatCurrency($money / 1000 ** $factor, $currency)}</span>
            <span class="multiplier">{self::$units[$factor]}</span>
        </abbr>;
    }
}
