/* WARNING */
/* THE CODE BELOW IS FUNCTIONAL AND RUNS CORRECTLY WITH ALL KNOWN TEST CASES.  HOWEVER, IT DOES NEED REFACTORING, TOO MANY VARIABLES AND LOOPS.  PLUS, RENAME VARIABLES TO ENHANCE READABILITY. */

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?  232792560

// STEPS:
// 1. Find all primes [2, LIMIT/2]
// 2. Make hashmap {prime:occurrences, prime:occurrences}
// 3. Count down from LIMIT to (LIMIT/2)+1
// 		3a. For each, break down by iterating from first prime in primes array.  Store occurrences in internal prime/occurrences hashmap.
// 		3b. If primes array is exhausted, add prime:1 entry to hashmap.
//		3c. globalHashmap = max(globalHashmap, localHashmap)

var limit = parseInt(prompt("Which number should I use as the upper limit when trying to find the smallest common multiple?"));
var half = Math.floor(limit/2);

var primes_count = {};
var primes = [2];
var primesIter = 0;
var primes_length = 1;

var result = 1;

// Use functions to reduce clutter, enhance readability, and promote modularity.  Function definitions are at the bottom.
findPrimes();
breakDown();
multiPrimes();

alert(result);

function findPrimes ()
{
	var prime_cand = 3;
	var prime_test = 3;
	
	for (; prime_cand <= half; primesReset())
	{
		while (prime_test > 1 && primesIter < primes_length)
		{
			if (!(prime_test % primes[primesIter])) {prime_test = 1; break};
			primesIter++;
		}
		if (prime_test > 1)
		{
			primes.push(prime_cand);
			primes_length++;
		} else {}
	}
	
	for (i = 0; i < primes_length; i++)
	{
		primes_count[primes[i]] = 0;
	}
	
	function primesReset()
	{
		primesIter = 0;
		prime_cand += 2;
		prime_test = prime_cand;
	}
}

function breakDown ()
{
	loc_limit = limit; loc_half = half + 1; loc_primes_count = {};
	
	for (; loc_limit >= loc_half; loc_limit--, primesIter = 0)
	{
		for (key in primes_count)
		{
			loc_primes_count[key] = 0;
		}
		var loc_test = loc_limit;
		for (; primesIter < primes_length; primesIter++)
		{
			var cond_cache = loc_test % primes[primesIter];
			while (cond_cache === 0 && cond_cache !== 1)  // If divisible, break down
			{
				loc_test /= primes[primesIter];
				loc_primes_count[primes[primesIter]]++;
				cond_cache = loc_test % primes[primesIter];
			}
		}
		if (cond_cache !== 1)
		{
			primes.push(loc_test);
			loc_primes_count[loc_test] = 1;
			primes_count[loc_test] = 1;
		}
		for (key in primes_count)  // Update global table with local values
		{
			primes_count[key] = Math.max(primes_count[key], loc_primes_count[key]);
		}
	}
}

function multiPrimes () 
{
	for (key in primes_count)
	{
		for (i = 1; i <= primes_count[key]; i++)
		{
			result *= key;
		}
	}
}