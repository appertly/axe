<?hh
/**
 * Axe
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   MIT
 */
namespace Axe;

/**
 * Stores page information to pass along to rendering functions.
 *
 * @copyright 2015-2016 Appertly contributors
 * @license   MIT
 */
class Page
{
    private string $title = '';
    private string $id = '';
    private string $lang = 'en';
    private string $encoding = 'utf8';
    private Vector<string> $classes = Vector{};
    private Vector<:meta> $metas = Vector{};
    private Vector<:link> $links = Vector{};
    private Vector<:script> $headScripts = Vector{};
    private Vector<:script> $bodyScripts = Vector{};

    /**
     * Gets the classes for the <body> tag.
     */
    public function getBodyClasses() : ImmVector<string>
    {
        return $this->classes->toImmVector();
    }

    /**
     * Adds classes to those for the <body> tag.
     */
    public function addBodyClasses(Traversable<string> $classes) : this
    {
        $this->classes->addAll($classes);
        return $this;
    }

    /**
     * Sets the page language.
     *
     * @param $lang - The new language
     * @return provides a fluent interface
     */
    public function setLang(string $lang) : this
    {
        $this->lang = $lang;
        return $this;
    }

    /**
     * Gets the page language, by default en.
     */
    public function getLang() : string
    {
        return $this->lang;
    }

    /**
     * Gets the page encoding, by default utf8.
     */
    public function getEncoding() : string
    {
        return $this->encoding;
    }

    /**
     * Sets the page encoding (e.g. utf8)
     *
     * @param $encoding - The page encoding
     * @return provides a fluent interface
     */
    public function setEncoding(string $encoding) : this
    {
        $this->encoding = $encoding;
        return $this;
    }

    /**
     * Gets the page title
     */
    public function getTitle() : string
    {
        return $this->title;
    }

    /**
     * Gets the page <meta/> tags.
     */
    public function getMeta() : ImmVector<:meta>
    {
        return $this->metas->toImmVector();
    }

    /**
     * Gets the page <link/> tags.
     */
    public function getLinks() : ImmVector<:link>
    {
        return $this->links->toImmVector();
    }

    /**
     * Gets the <script> tags in the page head.
     */
    public function getHeadScripts() : ImmVector<:script>
    {
        return $this->headScripts->toImmVector();
    }

    /**
     * Gets the <script> tags in the page body.
     */
    public function getBodyScripts() : ImmVector<:script>
    {
        return $this->bodyScripts->toImmVector();
    }

    /**
     * Sets the page title.
     *
     * @param $title - The new page title
     * @return provides a fluent interface
     */
    public function setTitle(string $title) : this
    {
        $this->title = $title;
        return $this;
    }

    /**
     * Gets the page id.
     */
    public function getBodyId() : string
    {
        return $this->id;
    }

    /**
     * Sets the page id.
     *
     * @param $id - The new id
     * @return provides a fluent interface
     */
    public function setBodyId(string $id) : this
    {
        $this->id = $id;
        return $this;
    }

    /**
     * Adds a <meta> tag.
     *
     * @param $name - The tag name attribute
     * @param $content - The tag content attribute
     * @return provides a fluent interface
     */
    public function addMeta(string $name, string $content) : this
    {
        $this->metas->add(<meta name={$name} content={$content} />);
        return $this;
    }

    /**
     * Adds a stylesheet.
     *
     * @param $src - The file location
     * @param $mime - Optional MIME type
     * @param $media - Optional list of media types
     * @return provides a fluent interface
     */
    public function addStylesheet(string $src, string $mime = '', ?Traversable<string> $media = null) : this
    {
        $link = <link rel="stylesheet" href={$src} />;
        if (strlen($mime) > 0) {
            $link->setAttribute('type', $mime);
        }
        if ($media !== null) {
            $link->setAttribute('media', implode(',', $media));
        }
        $this->links[] = $link;
        return $this;
    }

    /**
     * Adds a <link> tag.
     *
     * @param $rel - The relationship
     * @param $href - The resource HREF
     * @param $sizes - Optional sizes
     * @param $crossorigin - Optional crossorigin
     * @param $integrity - Optional integrity
     * @return provides a fluent interface
     */
    public function addLink(string $rel, string $href, string $sizes = '', string $crossorigin = '', string $integrity = ''): this
    {
        $link = <link rel={$rel} href={$href} />;
        if (strlen($sizes) > 0) {
            $link->setAttribute('sizes', $sizes);
        }
        if (strlen($crossorigin) > 0) {
            $link->setAttribute('crossorigin', $crossorigin);
        }
        if (strlen($integrity) > 0) {
            $link->setAttribute('integrity', $integrity);
        }
        $this->links[] = $link;
        return $this;
    }

    /**
     * Adds an external script to the head.
     *
     * @param $src - The script location
     * @param $mime - Optional MIME type
     * @return provides a fluent interface
     */
    public function addHeadScript(string $src, string $mime = '') : this
    {
        $script = <script src={$src}></script>;
        if (strlen($mime) > 0) {
            $script->setAttribute('type', $mime);
        }
        $this->headScripts[] = $script;
        return $this;
    }

    /**
     * Adds an inline script to the head.
     *
     * @param $script - The inline JavaScript
     * @param $mime - Optional MIME type
     * @return provides a fluent interface
     */
    public function addHeadScriptInline(string $script, string $mime = '') : this
    {
        $script = <script>{$script}</script>;
        if (strlen($mime) > 0) {
            $script->setAttribute('type', $mime);
        }
        $this->headScripts[] = $script;
        return $this;
    }

    /**
     * Adds an external script to the body.
     *
     * @param $src - The script location
     * @param $mime - Optional MIME type
     * @return provides a fluent interface
     */
    public function addBodyScript(string $src, string $mime = '') : this
    {
        $script = <script src={$src}></script>;
        if (strlen($mime) > 0) {
            $script->setAttribute('type', $mime);
        }
        $this->bodyScripts[] = $script;
        return $this;
    }

    /**
     * Adds an inline script to the mody.
     *
     * @param $script - The inline JavaScript
     * @param $mime - Optional MIME type
     * @return provides a fluent interface
     */
    public function addBodyScriptInline(string $script, string $mime = '') : this
    {
        $script = <script>{$script}</script>;
        if (strlen($mime) > 0) {
            $script->setAttribute('type', $mime);
        }
        $this->bodyScripts[] = $script;
        return $this;
    }
}
