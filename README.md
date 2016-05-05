# appertly/axe

**A** ppertly **X** HP **E** xtras: Some useful XHP tags and utilities for Hack/HHVM.

## Installation

You can install this library using Composer:

```console
$ composer require appertly/axe
```

* The master branch (version 0.x) of this project requires HHVM 3.12 and depends on [XHP](https://github.com/facebook/xhp-lib) 2.2+.

## Compliance

Releases of this library will conform to [Semantic Versioning](http://semver.org).

Our code is intended to comply with [PSR-1](http://www.php-fig.org/psr/psr-1/) and [PSR-2](http://www.php-fig.org/psr/psr-2/). If you find any issues related to standards compliance, please send a pull request!

## Features

### Page + Layout

The class `Axe\Page` allows collaborating classes to influence the tags that appear on a rendered page.

`:axe:layout` takes a `Axe\Page` object and renders a correct HTML document complete with DOCTYPE, `html`, `head`, and `body` tags. Any settings in the `Axe\Page` object will appear in the rendered `:axe:layout`.

```hack
$page = new Axe\Page();
$page->setTitle('My example title')
    ->addBodyScript('/script.js')
    ->addBodyClasses(['foo', 'bar'])
    ->addStylesheet('/styles.css')
    ->addHeadScriptInline('console.log("Hello world!");');
$html = <axe:layout page={$page}><p>Hello world!</p></axe:layout>;
echo (string)$html;
```
```html
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf8">
        <title>My example title</title>
        <script>console.log("Hello world!");</script>
        <link rel="stylesheet" href="/styles.css">
    </head>
    <body class="foo bar">
        <p>Hello world!</p>
        <script src="/script.js"></script>
    </body>
</html>
```

### Helper Tags

We've included several helper tags for common stuff.

* Gravatar image
* Columns (and golden ratio columns)
* Bootstrap-compatible breadcrumbs, form groups, and fieldsets
* Nearly Bootstrap-compatible alerts
* Email and Phone Number links
* Convert text with line endings to multiple `<p>`s
* `<select>` and `<option>`s generated from a `Map` of values
* …and _more!_
