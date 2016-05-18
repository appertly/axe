<?hh // strict
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   http://opensource.org/licenses/MIT MIT License
 */

/**
 * The base layout
 */
class :axe:layout extends :x:element
{
    children (pcdata | %flow)*;
    attribute Axe\Page page @required;

    protected function render() : XHPRoot
    {
        $page = $this->:page;

        $body = <body>
            {$this->getChildren()}
            <axe:scripts page={$page}/>
        </body>;

        foreach ($page->getBodyClasses() as $class) {
            $body->addClass($class);
        }
        if ($page->getBodyId()) {
            $body->setAttribute('id', $page->getBodyId());
        }

        return <x:doctype>
            <html lang={$page->getLang()}>
                <head>
                    <meta charset={$page->getEncoding()} />
                    <title>{$page->getTitle()}</title>
                    {$page->getMeta()}
                    <axe:scripts location="head" page={$page}/>
                    {$page->getLinks()}
                </head>
                {$body}
            </html>
        </x:doctype>;
    }
}
