<?hh

namespace Axe;

use HackPack\HackUnit\Contract\Assert;

class PrettyCurrencyTest
{
    <<Test>>
    public async function testRender(Assert $assert): Awaitable<void>
    {
        $out = [
            '<abbr class="pretty" title="$0.00"><span class="value">$0.00</span><span class="multiplier"></span></abbr>' => <axe:pretty-currency locale="en_US"/>,
            '<abbr class="pretty" title="$1.00"><span class="value">$1.00</span><span class="multiplier"></span></abbr>' => <axe:pretty-currency value={1} locale="en_US"/>,
            '<abbr class="pretty" title="$1,000.00"><span class="value">$1.00</span><span class="multiplier">K</span></abbr>' => <axe:pretty-currency value={1000} locale="en_US"/>,
            '<abbr class="pretty" title="$123,456.00"><span class="value">$123.46</span><span class="multiplier">K</span></abbr>' => <axe:pretty-currency value={123456} locale="en_US"/>,
            '<abbr class="pretty" title="$123,456,789.00"><span class="value">$123.46</span><span class="multiplier">M</span></abbr>' => <axe:pretty-currency value={123456789} locale="en_US"/>,
            '<abbr class="pretty" title="$123,456,789,123.00"><span class="value">$123.46</span><span class="multiplier">B</span></abbr>' => <axe:pretty-currency value={123456789123} locale="en_US"/>,
            '<abbr class="pretty" title="$123,456,789,123,456.00"><span class="value">$123.46</span><span class="multiplier">T</span></abbr>' => <axe:pretty-currency value={123456789123456} locale="en_US"/>,
            '<abbr class="pretty" title="$123,456,789,123,457,000.00"><span class="value">$123,456.79</span><span class="multiplier">T</span></abbr>' => <axe:pretty-currency value={123456789123456789} locale="en_US"/>,
        ];
        foreach ($out as $k => $v) {
            $assert->string((string) $v)->is($k);
        }
    }
}
