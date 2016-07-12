<?hh

namespace Axe;

use HackPack\HackUnit\Contract\Assert;

class SideBoxTest
{
    <<Test>>
    public async function testRender(Assert $assert): Awaitable<void>
    {
        $out = [
            '<section class="side-box"><header class="side-box-header"><h1>Hello</h1><div role="toolbar" aria-label="" class="side-box-toolbar"><button>Yup</button></div></header><div class="side-box-contents"><p>Stuff</p></div></section>'
                => <axe:side-box label="Hello"><axe:toolbar><button>Yup</button></axe:toolbar><p>Stuff</p></axe:side-box>,
            '<section class="side-box"><header class="side-box-header"><h1>Hello</h1></header><div class="side-box-contents"><p>Stuff</p></div></section>'
                => <axe:side-box label="Hello"><p>Stuff</p></axe:side-box>,
            '<section class="side-box"><header class="side-box-header"><h1>Hello</h1></header><div class="side-box-contents"></div></section>'
                => <axe:side-box label="Hello"></axe:side-box>,
            '<section class="side-box"><header class="side-box-header"><h1>Hello</h1><div role="toolbar" aria-label="" class="side-box-toolbar"><button>Nope</button></div></header><div class="side-box-contents"></div></section>'
                => <axe:side-box label="Hello"><axe:toolbar><button>Nope</button></axe:toolbar></axe:side-box>,
            '<section class="side-box"><header class="side-box-header"><h1>Hello</h1><div role="toolbar" aria-label="" class="side-box-toolbar"><button>Nope</button></div></header><div class="side-box-contents"><p>Stuff</p>Hello</div></section>'
                => <axe:side-box label="Hello"><axe:toolbar><button>Nope</button></axe:toolbar><p>Stuff</p>{"Hello"}</axe:side-box>,
        ];
        foreach ($out as $k => $v) {
            $assert->string((string) $v)->is($k);
        }
    }
}
