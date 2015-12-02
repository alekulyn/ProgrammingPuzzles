#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

void chopDown (long long unsigned int *, long *, int *, long int);

//Find prime factors of 600851475143
int main()
{

	long long unsigned int userin;  // Number to find prime factors of
	scanf("%llu", &userin);
	long long unsigned int original = userin;  // Save original
	
	long *primesArray = malloc(50 * sizeof(long)); // Array to hold primes, initialize all to zero
	int arrayPosi = 0; // Current array position
	
	// Eliminate all factors of 2 from number
	chopDown(&userin, primesArray, &arrayPosi, 2);
	for (int i = 3; i <= userin; i = i + 2) {
		chopDown(&userin, primesArray, &arrayPosi, i);
	}
    
	printf("\nThe number you gave was %llu, and your primes are: ", original);
	primesArray[arrayPosi] = 0;
	arrayPosi = 0;
	while (primesArray[arrayPosi] != 0) {
		printf("%ld ", primesArray[arrayPosi]);
		arrayPosi++;
	}
}

void chopDown (long long unsigned int *bigNum, long *primesArray, int *arrayPosi, long int divisor)  // function to chop down numbers
{
	for (long int i = divisor; *bigNum % i == 0;) {
		*bigNum = *bigNum / i;  // Chop down userin with 2's
		
		if (*bigNum % i != 0) {  // If userin ISN'T divisible by factor i anymore, add i to primesArray
			primesArray[*arrayPosi] = i;
			(*arrayPosi)++;
			printf("%ld ", i);
		}
	}
}
