// useful functions in vanilla JavaScript

// reduce() --> can be used on JavaScript arrays
numbers = [2, 3, 4, 5];

numbersReducedSum = numbers.reduce(function(prev, current, i, array) {
    return prev + current;
});
console.log(numbersReducedSum);

// forEach() --> can be used on JavaScript arrays
numbers.forEach(function (number) {
    console.log(number);
});



// lodash useful functions
var _ = require('lodash');

console.log(_.map([1, 2, 3], function (n) {
    return n * 2;
}));

