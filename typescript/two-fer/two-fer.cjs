"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.twoFer = twoFer;
function twoFer(str) {
    if (!str) {
        return 'One for you, one for me.';
    }
    return 'One for ' + str + ', one for me.';
}
// Add these lines to see the output
console.log(twoFer()); // Should output: "One for you, one for me."
console.log(twoFer('Alice')); // Should output: "One for Alice, one for me."
console.log(twoFer('Bob')); // Should output: "One for Bob, one for me."
