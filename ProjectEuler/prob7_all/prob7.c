// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10,001st prime number?

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(unsigned long long);

struct {
	unsigned long long *primes;
	int size;
} PrimesList;

int main() {
	scanf("%d", &PrimesList.size);
	PrimesList.primes = realloc(PrimesList.primes, sizeof(long long) * PrimesList.size);

	PrimesList.primes[0] = 2;
	for (int i = 1; i < PrimesList.size; i++) {
		unsigned long long mostRecentNum = PrimesList.primes[i-1] + 1;
		for (;; mostRecentNum++) {
			if (isPrime(mostRecentNum)) {
				break;
			}
		}
		PrimesList.primes[i] = mostRecentNum;
	}

	printf("The number %d prime is: %lld\n", PrimesList.size, PrimesList.primes[PrimesList.size-1]);

	return 0;
}

bool isPrime(unsigned long long candidate) {
	for (int i = 0; i < PrimesList.size && PrimesList.primes[i] != 0; i++) {
		if (candidate % PrimesList.primes[i] == 0) {
			return false;
		}
	}
	return true;
}
