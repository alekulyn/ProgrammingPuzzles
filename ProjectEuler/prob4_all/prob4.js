// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers. 906609

// WARNING!  Needs refactoring.

var digits = parseInt(prompt("How many digits do you want the factors to be?"));
var factor = fillDigits(digits) - 1; var factor_backup = factor;
var palindrome = 0;
var factor_range = [[factor, factor]];

findPalindrome();
alert(palindrome);

function fillDigits (quantity)
{
	var factor = 1;
	for (var i = 0; i < quantity; i++)
	{
		factor += 9 * Math.pow(10, i);
	}
	return factor;
}

function findPalindrome()
{
	var range_inc = (factor + 1) * 5;  // Maybe add a * 10
	var limit = Math.pow(factor + 1, 2) - range_inc;
	var product;
	var factor_range_len = factor_range.length;  // CACHE
	for (; !palindrome; limit -= range_inc)
	{
		var i = 0; factor = factor_backup;
		for (recalcProduct(); product > limit; factor--, i++, recalcProduct(true))  // Revise condition step so that it doesn't break at third for loop's break
		{
			for (recalcProduct(); product > limit; factor_range[i][1]--, recalcProduct())  // THIS LOOP IS DONE!!!
			{
				// if (product < limit)  // Can't put in condition step
				// {
					// break;
				// }
				if (isPali(product))
				{
					palindrome = Math.max(palindrome, product);
				}
			}
		}
	}
	
	function recalcProduct(forCondition)
	{
		if (forCondition)
		{
			if (i === factor_range_len)  // Add a new factor
			{
				factor_range.push([factor, factor]);
				factor_range_len++;
			}
		}
		product = factor_range[i][0] * factor_range[i][1];
	}
}

function isPali (candidate)
{
	candidate = candidate.toString();
	var i = 0, j = candidate.length - 1;
	var decision = true;
	for (; j - i > 0; i++, j--)
	{
		if (candidate[i] !== candidate[j])
		{
			decision = false;
			return decision;
		}
	}
	return decision;
}