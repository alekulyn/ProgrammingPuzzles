// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.  233168

// NOTICE!  This version of the code was not initially used to solve the problem.
// Originally, there was a continue statement in the second for loop to skip past any iterations that were divisible by 15.
// The third for loop is entirely new, inspired by the problem explanation offered by ProjectEuler.

// TODO: Offer to choose factors, instead of default 3 and 5.

var userInput = prompt("What is the limit?");
var sum = 0;

for (var i = 3; i < userInput; i += 3)
{
	sum += i;
}

for (var i = 5; i < userInput; i += 5)
{
	sum += i;
}

for (var i = 15; i < userInput; i += 15)
{
	sum -= i;
}

alert(sum);