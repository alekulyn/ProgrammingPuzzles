// Problem:
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
// TODO: Make the code easier to read.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int number;
	int occurrences;
} Counter;

struct {
	Counter *counters;
	int size;
} CounterList;

int end_nmbr;
long start_nmbr;

void breakDown (int);
void update_counter(int []);

int main ()
{
	scanf("%d", &end_nmbr);
	start_nmbr = floor( (float) end_nmbr / 2 + 1);

	for (; start_nmbr <= end_nmbr; start_nmbr++) {
		printf("Breaking down the number %ld\n", start_nmbr); //DEBUG
		breakDown(start_nmbr);
	}

	unsigned long long product = 1;
	for (int i = 0; i < CounterList.size; i++) {
		printf("Number: %d\tOccurences: %d\n", CounterList.counters[i].number, CounterList.counters[i].occurrences);
		product *= pow(CounterList.counters[i].number, CounterList.counters[i].occurrences);
	}

	printf("The smallest number divisible by all numbers 1 through %d is: %lld\n", end_nmbr, product);
	
	free(CounterList.counters);
	return 0;
}

void breakDown (int number)  // function to break down numbers
{
	int *prime_factors = NULL; int pf_size = 2;
	prime_factors = realloc(prime_factors, sizeof(int) * pf_size);
	prime_factors[0] = number;

	for (int i = 0, prime = 2;; i++) {
		if (number % prime != 0) {
			prime++;  i--;
			continue;
		}
		number /= prime;
		if (number == 1) {
			break;
		}
		prime_factors[i] = prime;
		prime_factors[i+1] = number;
		prime_factors = realloc(prime_factors, sizeof(int) * ++pf_size);
		prime_factors[pf_size-1] = 0;
	}

	//DEBUG
	printf("\tnumber %ld broken down to: ", start_nmbr);
	for (int i = 0; i < pf_size; i++) {
		printf("%d ", prime_factors[i]);
	} printf("\n");

	update_counter(prime_factors);
	free(prime_factors);
}

void update_counter(int prime_factors[])
{
	for (int i = 0; prime_factors[i] != 0;) {
		int local_counter = 0;

		//Find element in CounterList that contains the relevant prime
		int counter_idxOf = -1;
		for (int j = 0; j < CounterList.size; j++) {
			if (CounterList.counters[j].number == prime_factors[i]) {
				counter_idxOf = j;
				break;		
			}
		}
		//If the counter containing the prime doesn't exist, make a new counter
		if (counter_idxOf < 0) {
			CounterList.size++;
			CounterList.counters = realloc(CounterList.counters, CounterList.size * sizeof(Counter));
			counter_idxOf = CounterList.size - 1;
			CounterList.counters[counter_idxOf].number = prime_factors[i];
		}

		//Count the occurrences of the prime in the entire array
		int j = i;
		for (; j < start_nmbr; j++) {
			if (prime_factors[j] != prime_factors[i]) {
				local_counter = j - i;
				break;
			}
		}
		i = j;
		
		CounterList.counters[counter_idxOf].occurrences = (local_counter > CounterList.counters[counter_idxOf].occurrences) ? local_counter : CounterList.counters[counter_idxOf].occurrences;
	}
}

