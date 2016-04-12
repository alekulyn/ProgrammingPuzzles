#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#if   defined(PRIMES_GMP)
	#include <gmp.h>
	#define primes_T mpz_t
#elif defined(PRIMES_8)
	#define primes_T uint8_t
#elif defined(PRIMES_16)
	#define primes_T uint16_t
#elif defined(PRIMES_32)
	#define primes_T uint32_t
#else
	#define primes_T uint64_t
#endif

typedef struct {
	primes_T *array;
	unsigned int size;
} intArray;

void addPrime(primes_T, intArray *);
bool isPrime(primes_T, primes_T *, unsigned int);
intArray initIntArray();

intArray generatePrimes(primes_T start, primes_T end, unsigned int *numOfPrimes, intArray *currArray) {
	if (start < 2) {
		start = 2;
	} else if ( (void *) start == NULL) {
		printf("generatePrimes.start cannot be NULL.  Quitting...\n");
		exit(1);
	} else if ( (void *) end == NULL && (void *) numOfPrimes == NULL) {
		printf("generatePrimes.end and generatePrimes.numOfPrimes cannot both be NULL. Quitting...\n");
		exit(1);
	}

	intArray primesArray;
	if (currArray != NULL) {
		primesArray = *currArray;
	} else {
		primesArray.size = 0;
	}

	for (int i = start; i <= end; i++) {
		if (isPrime(i, primesArray.array, primesArray.size)) {
			addPrime(i, &primesArray);
		}
	}

	return primesArray;
}

void addPrime(primes_T prime, intArray *primesArray) {
	primesArray->array = realloc(primesArray->array, sizeof(primes_T)*(++primesArray->size));

	if (primesArray->array == NULL) {
		printf("Out of virtual memory.  Cannot add a new prime.  Quitting...\n");
		exit(1);
	}

	primesArray->array[primesArray->size - 1] = prime;
}

bool isPrime(primes_T prime, primes_T *primesArray, unsigned int primesArraySize) {
	for (int i = 0; i < primesArraySize; i++) {
		if (prime % primesArray[i] == 0) {
			return false;
		}
		if ((double) primesArray[i] > sqrt(prime)) {
			break;
		}
	}

	return true;
}

