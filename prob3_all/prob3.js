// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?  6857

var theNUMBER = parseInt(prompt("Which number do you what to find the largest prime factor of?"));
var prime = 3;

breakDown();

alert(prime - 2);  // Subtract two because of second for loop's increment

function breakDown ()
{
	// Get rid of all evens
	for (; theNUMBER !== 2 && !(theNUMBER % 2);)
	{
		theNUMBER /= 2;
	}
	if (theNUMBER === 2)
	{
		prime = 2;
		return;
	}
	
	// Look for primes
	for (; theNUMBER !== 1; prime += 2)
	{
		for (; theNUMBER % prime === 0;)
		{
			theNUMBER /= prime;
		}
	}
}