# node-fixedentropy

[![Greenkeeper badge](https://badges.greenkeeper.io/tmcw/node-fixedentropy.svg)](https://greenkeeper.io/)

```js
// V8 supports custom sources of entropy.
// by default, entropy is fairly entropic; in node.js, it's sourced
// from some primo OpenSSL functions

Math.random(); // 0.6986953148152679
Math.random(); // 0.700820395257324
Math.random(); // 0.2057398131582886

// Looking good.

// But, of course, node supports C++ modules, and V8 supports
// runtime entropy configuration, so

require('fixedentropy');

Math.random(); // 0.06971457065083086
Math.random(); // 0.06971457065083086
Math.random(); // 0.06971457065083086
```
