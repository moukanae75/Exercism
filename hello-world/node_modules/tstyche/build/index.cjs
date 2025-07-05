'use strict';

function doNothing() {
}
const noopChain = new Proxy(doNothing, {
    apply() {
        return noopChain;
    },
    get() {
        return noopChain;
    },
});

exports.describe = noopChain;
exports.expect = noopChain;
exports.it = noopChain;
exports.test = noopChain;
