# Introduction To Web Development

---

The front end is the stuff you see on the website in your browser.

- HTML, CSS, JavaScript, and their relevant frameworks

The back-end refers to the guys of the applications, which are live on the server. 

- Java, Python, Ruby, and JavaScript

Full-stack developers are comfortable working with both the front and back ends. 

- This is what the Odin Project will be covering
## Tool of the Trade:

- command line interface
- stack overflow
- Git
- GitHub

>📌 Start working on some open source projects like the Odin project itself. Remember to look up some popular open source.

---


# Motivation and Mindset

### **Comparing Yourself to Others**

Students often compare themselves to others who are farther along in their coding journey or have more experience. This is a recipe for depression and frustration.

**Solution:** Only compare yourself to your past self. Have your abilities and knowledge improved from where you were last week, last month, or last year? Be proud of the progress that you’ve made!

---

# Computer Basics

Since the Odin Project only natively supports Linux based OS, we can use a VM to start the course

### Virtual Machine (VM)

- it has been setup

---

# Git

- git has been setup on the virtual machine

### Cheat sheet for Git Commands:

Commands that related to a remote repo:

- `git clone git@github.com:USER-NAME/REPOSITORY-NAME.git`
- `git push` or `git push origin main` (Both accomplish the same goal in this context)
- Commands related to the workflow:
    - `git add .`
    - `git commit -m "A message describing what you have done to make this snapshot different"`
- Commands related to checking status or log history
    - `git status`
    - `git log`

The basic Git syntax is `program | action | destination`.

### Git Best Practices

An atomic commit is a commit that includes changes related to only one feature or task of your program. There are two main reasons for doing this:

1. if something you change turns out to cause some problems, it is easy to revert the change without losing other work
2. and it enables you to write better commit messages

---

# Introduction to HTML and CSS

### HTML and CSS

They are two languages that work together to create viewable objects on the internet. HTML is the raw data that a webpage is built out of. All the text, links, cards, lists, and buttons are created in HTML.

While CSS is what adds the style to the elements. 

- HTML puts information on a webpage and CSS positions that information, gives it color, changes the font, and makes it look great

In general:

- HTML is for the content and layout
- CSS is for the look and feel
- JavaScript is for the interactive elements

---

# Elements and Tags

HTML defines the structure and content of webpages. We use HTML elements to create all of the paragraphs, headings, lists, images, and links that make up a typical webpage. 

### Element and Tags

Almost all elements on an HTML page are just pieces of content wrapped in opening and closing HTML tags. Opening tags tell the browser that this is the start of an HTML element. They are comprised of a keyword in angle brackets that look like `<p>`, while the closing tag looks like `</p>`.

```html
<p> some text content </p>
```

You can think of elements as containers for content. The opening and closing tags tell the browser what content the element contains. 

There are some HTML elements that do not have closing tags and often look like: `<br />` or `<img>`. They are known as self-closing tags or empty elements because they do not wrap any content. 

---

# HTML Boilerplate

DOCTYPE: used for telling the browser what version of HTML that is being used.

`<html lang=”eng”>`

This is the root element of the document, meaning every other element is a child of this one. 

`</html>`

- `lang` specifies the language of the text content in the element. It is mainly an accessibility
- The <head> element is where we put important meta-information about our webpages, and stuff required for them to render correctly in the browser.
    - Inside <head> we should not use any element that displays content on the webpage

**Charset Meta Element**:

It looks like `<meta charset=”utf-8>`

- it is important for correctly displaying special symbols

##### Title Element

It looks like `<title>` My First Webpage `</title>` 

- it is used to give a large text title which is displaced in the webpage’s browser tab

The body element is need to complete the content that will be displayed to the users. 

The most common boiler plate is:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <title>My First Webpage</title>
  </head>

  <body>
  </body>
</html>
```

### Viewing the HTML Files in the Browser

The HTML boilerplate in the index.html file is complete, but to view it in the browser there are a couple of options.

1. drag and drop it into the browser
2. find the html file in the file browser and double click it 
3. call for it in the terminal through google-chrome index.html

---

## Working with Text

### Paragraphs

If we want to create paragraphs in HTML, we need to use the paragraph element which will add a newline after each of our paragraphs. A paragraph element is defined by wrapping text content with a `<p>` tag.

### Headings

There are 6 different levels of headings each with different sizes. They are defined like paragraphs. 

### Strong Element

The `<strong>` element makes text bold. It also marks text as important which effects tools like screen readers that users with visual impairment will rely on when using the website. 

- You can also use it inside of other elements

### Em Element

The `<em>` element makes text italic and also affects screen readers. 

### Nesting and Indentation

We indent any elements that are within other elements. This is known as nesting elements, which allows us to indicate which elements are child or parent to each other. 

- in vscode to auto format html code use the command `cntrl+shift+I`

### HTML Comments

```html
<!-- I am an html comment -->
```

---

# Lists

### Unordered Lists

If you want to have a list of items where the order does not matter, then you can use an unordered list. 

They are created using the `<ul>` element and each item within the list is created using the list item element `<li>`.

- item 1
- item 2
- item 3

### Ordered Lists

If you instead want to create a list of items where the order does matter. You would use the `<ol>` element and the `<li>` element as well.

1. item 1
2. item 2
3. item 3

---

# Links and Images

### Anchor Elements

To create an anchor element we use the anchor tag `<a>`. You would then need to add an href tag to make the link work to a specific website. 

```html
<a href="https://www.theodinproject.com/about">click me</a>
```

By default any text under the anchor tag would look like plain text but once you add the href attribute to the link it creates the blue outline and underline.

There are also generally two kinds of links:

- links to other websites
- links to other pages in the current website

### Absolute Links

Links to pages on other websites are called absolute links are absolute links as they contain the structure: 

### Relative Links

Links to other pages within our own website are called relative links. They do not include the domain name. 

### Images:

To display an image in HTML, we use the `<img>` tag which embeds an image into the page

```html
<img src="https://www.theodinproject.com/mstile-310x310.png">
```

### Parent Directories

If we want to use the dog image in another page that is in a sub-folder, you would have to use the double dot path:

```html
<img src="../images/dog.jpg">
```

### Alt Attribute:

Beside the src attribute, every image element should also have an alt attribute. It is used to describe an image. It will be used in place of the image if it cannot be loaded. It is also used with screen readers to describe what the image is to visually impaired users.

```html
<img src="https://www.theodinproject.com/mstile-310x310.png" alt="The Odin Project Logo">
```

---

# Commit Messages

- when you are applying for jobs, employers will look through your projects on GitHub and they will look through your commit history.
- useful for other developers that are looking through your code
- helpful for you when you are looking back at your code

### When to Commit

When writing code, it’s considered best practice to commit every time you have a meaningful change in the code. This will create a timeline of your progress and show that your finished code didn’t appear out of nowhere.

- spell check
- use an active voice “Fix card generator”
- avoid using vague commit messages such as “saved” or “updated”
- commit early and often

---

# Recipe Website

Some website have a very simple design, as they are called brutalist since they seem simple and rugged. Part of the minimalist movement.

### Viewing Your Website in GitHub:

- does not seem to work?

---

# CSS Foundations

### Basic Syntax

The rules of CSS are made up of a selector and a semi-colon separated list of declarations, with each of those declarations being made up of a property:value pair.

> A `<div>` is a basic HTML element. It is an empty container. It is an empty container, but in CSS you will find that you need a container for other elements. The Odin Project excursuses will just use plain `<div>`s for simplicity
> 

## Selectors:

They are what is actually being “selected” for each rule. 

### Universal Selector

The universal selector will select elements of any type and the syntax for it is a simple asterisk. In the example below, every element would have the color purple.

```css
* {
  color: purple;
}
```

### Type Selectors

A type selector will select all elements of the given element type and the syntax is just the name of the element. In the code below, all three `<div>` element would be selected, while the `<p>` would not.

```html
<!-- index.html -->

<div>Hello, World!</div>
<div>Hello again!</div>
<p>Hi...</p>
<div>Okay, bye.</div>
```

```css
/* styles.css */

div {
  color: white;
}
```

### Class Selectors

Class selectors will select all elements with the given class, which is just an attribute you place on an HTML element. Here is how you add a class to an HTML tag and select it in CSS:

```html
<!-- index.html -->

<div class="alert-text">
  Please agree to our terms of service.
</div>
```

```css
/* styles.css */

.alert-text {
  color: red;
}
```

> Note that for the syntax for class selectors: a period immediately followed by the case sensitive value of the class attribute. Since whitespace is used to separate class names like this, you should never use spaces for multi-worded names and should use a hyphen instead.


### ID Selectors

ID selectors are similar to class selectors. They select an element with the given ID, which is another attribute you can place on an HTML element:

```html
<!-- index.html -->

<div id="title">My Awesome 90's Page</div>
```

```css
/* styles.css */

#title {
  background-color: red;
}
```

Instead of a period, we use a hashtag immediately followed by the case-sensitive value of the ID attribute. 

> The common pitfall is people overusing the ID attribute when they do not really need to and classes will suffice. You should use IDs sparingly.
> 

The major difference between classes and IDs is that an element can only have one ID. An ID cannot be repeated in a single page, and the ID attribute should not contain any whitespace at all

### Grouping Selector

If two group of elements have the same style declarations, they can be grouped and have their declarations be the same:

```css
.read,
.unread {
  color: white;
  background-color: black;
}

.read {
  /* several unique declarations */
}

.unread {
  /* several unique declarations */
}
```

This reduces the repetition of declarations and makes it easier to edit either to color or background-color for both classes at once. 

### Chaining Selectors:

Another way to use selectors is to chain them as a list without any separation. 

```html
<div>
	<div class="subsection header">Latest Posts</div>
	<p class="subsection preview">This is where a preview for a post might go.</p>
</div>
```

Here with have two elements with the subsection class, but if we want to add a separate rule only for “subsection header” this can be achieved through chaining:

```css
.subsection.header {
  color: red;
}
```

What this piece of code above does is that it selects any element that has both the section and header classes. It can be also used to chain a class an ID, as shown below: 

 

```html
<div>
  <div class="subsection header">Latest Posts</div>
  <p class="subsection" id="preview">This is where a preview for a post might go.</p>
</div>
```

Which can be chained as follows:

```css
.subsection.header {
  color: red;
}
.subsection#preview {
  color: blue;
}
```

### Descendant Combinator

Combinators allow us to combine multiple selectors differently than either grouping or chaining them. There are four types of combinators in total but one of them is the descendant combinator. This is represented in CSS by a single space between selectors. 

A descendant combinator will only cause elements that match the last selector to be selected if they also have an ancestor (parent and child) that matches the previous selectors. 

- so something like .ancestor.child would select an element with the class child if it has an ancestor with the class ancestor, no matter how deep it is.

```html
<!-- index.html -->

<div class="ancestor"> <!-- A -->
  <div class="contents"> <!-- B -->
    <div class="contents"> <!-- C -->
    </div>
	</div>
</div>
<div class="contents"></div> <!-- D -->

```

```css
/* styles.css */

.ancestor .contents {
  /* some declarations */
}
```

In the above example, the first two elements with the contents class (B and C) but D would not since it is not as it is not nested. 

There is no limit to how many combinators you can add to a rule so .one.two.three.four would be valid. 

## Properties to Get Started With

### Color and Background-Color

The color property sets an elements color, while background color sets the background color of the element.

- Both of these properties can accept several kinds of color values such as HEX, RGB, and HSL values.
- You can also change the opacity through adding an alpha value

### Typography Basics and Text-Align

font-family can be a single value or comma-separated list of values that determine what font an element uses. Each font will fall into one of two categories:

- a font family name like `"Times New Roman"`
- or a generic family name like `sans-serif`

If a browser cannot find or does not support the first font in a list, it will just use the next one in the list until it can.

`font-size` sets the size of the font and looks like font-size: 22px
`font-weight` affects the boldness of the font if the font supports it. 

`text-align` will align text horizontally within an element, and you can use the common keywords you may have for this property like center, left, right, and etc.

### Image Height and Width

By default, an `<img>` elements height and width values are the same as the actual image file’s height and width. If you wanted to adjust the size of the image without causing it to lose its proportions, you would use a value of auto for the height property and just adjust width. 

```css
img {
  height: auto;
  width: 500px;
}
```

It is best to include both of these properties for `<img>` elements even if you do not plan to adjust the values, as it causes images to load up faster and create a nicer user experience.

---