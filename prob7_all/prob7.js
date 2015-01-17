// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10,001st prime number?  104743
// Note:  Using recursion is possible, but causes Firefox to hang.  Using for loops is a more simplistic and structured solution.

var prime_choice = parseInt(prompt("Which number prime are you looking for?"));

var primes = [2];
var primes_length = 1;
var primesIter = 0;
var prime_cand = 3;
var prime_test = 3;

for (; primes_length !== prime_choice;)
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
		primesReset();
	} else {
		primesReset();
	}
}

function primesReset()
{
	primesIter = 0;
	prime_cand += 2;
	prime_test = prime_cand;
}

alert(primes[prime_choice - 1]);