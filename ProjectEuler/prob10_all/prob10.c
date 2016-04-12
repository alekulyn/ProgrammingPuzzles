// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

#include <inttypes.h>
#include "../primes.h"

int main (int argc, char *argv[]) {
	uint64_t primesLimit, sum = 0;
	if (argc > 1) {
		sscanf(argv[1], "%"SCNu64, &primesLimit);
	} else {
		scanf("%"SCNu64, &primesLimit);
	}
	fflush(stdout);

	intArray primesArray = generatePrimes(0, primesLimit, NULL, NULL);

	for (int i = 0; i < primesArray.size; i++) {
		sum += primesArray.array[i];
	}

	printf("The sum of all primes below %"PRIu64" is %"PRIu64, primesLimit, sum);
}
