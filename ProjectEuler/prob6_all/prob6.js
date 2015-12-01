// The sum of the squares of the first ten natural numbers is 1^2 + 2^2 + ... + 10^2 = 385
// The square of the sum of the first ten natural numbers is (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.  25164150

var square_of_sum, sum_of_squares;
var limit = parseInt(prompt("How high do you want to count?"));

// Square of sum
var sum = 0;
for (i = 1; i <= limit; i++)
{
	sum += i;
}
square_of_sum = Math.pow(sum, 2);

// Sum of squares
var sum_of_squares = 0;
for (i = 1; i <= limit; i++)
{
	sum_of_squares += Math.pow(i, 2);
}

alert(square_of_sum - sum_of_squares);