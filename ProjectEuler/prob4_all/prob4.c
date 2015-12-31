// Problem:
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define this_ITER facHolder[iteration]
#define PRODUCT (this_ITER.firstFactor * this_ITER.secondFactor)
#define NEWFACTOR (initNewFactor(facHolder, &facHolderEnd, digNum))

typedef struct {
	int firstFactor;
	int secondFactor;
} FactorSet;

int fillDigits(int);
FactorSet *initNewFactor(FactorSet *, int *, int);
int isPali(int, int);
void test(char *, long long);

/*
	multiply highest factors together to get top limit number
	subtract from top limit number in increments
	in each increment, use for loops to count down factors using the current limit as condition in the for loop
 */

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0); //Disable buffering

	long long palindrome = 0, topLimit, forLimit, increment;
	int digits, digNum, fy = NULL, fx = NULL;

	printf("%s", "How many digits you want in each of the factors of the palindrome?  ");
	scanf("%d", &digits);

	digNum = fillDigits(digits);
	topLimit = pow(digNum + 1, 2); increment = topLimit / pow(10, digits-1);  // topLimit/10 works, but not topLimit/100;  try to fix that

	int facHolderEnd = 0; FactorSet *facHolder = NULL; bool stop = false;
	for (forLimit = topLimit - increment; forLimit && !palindrome; forLimit -= increment)	{
		stop = true;
		int iteration = 0;
		test("forLimit", forLimit); test("iteration", iteration); printf("\n");  //Debug message
		for (;stop; iteration++) {
			if (facHolderEnd == iteration) {
				facHolder = NEWFACTOR;
			}
			if (PRODUCT < forLimit) break;
			for (;this_ITER.secondFactor > 0; this_ITER.secondFactor--) {
				// consider turning this into a function
				long long product = PRODUCT;
				if (product < forLimit) break;
				test("product", product); test("firstFactor", this_ITER.firstFactor); test("secondFactor", this_ITER.secondFactor);  //Debug message
				if (isPali(product, digits) && product > palindrome) {
					palindrome = product; fx = this_ITER.firstFactor; fy = this_ITER.secondFactor;
				}
			}
		}
	}

	free(facHolder);
	printf("Your palindrome is %lld, and your two factors are %d and %d\n", palindrome, fx, fy);
}

FactorSet *initNewFactor(FactorSet *facHolder, int *facHolderEnd, int digNum)
{
	facHolder = realloc(facHolder, sizeof(FactorSet *) * (*facHolderEnd + 1));
	if (facHolder == NULL) {printf("Null realloc");exit(-1);}

	int newFacHolderEnd = *facHolderEnd + 1;
	for(int i = 0; i < newFacHolderEnd; i++) {
		if (i >= *facHolderEnd) {
			facHolder[i].firstFactor = digNum - i;
			facHolder[i].secondFactor = digNum - i;
		}
	}
	(*facHolderEnd)++;

	return facHolder;
}

// small debug function
void test(char *name, long long number) {
	printf("%s is %lld. ", name, number);
}

int fillDigits(int digNum)
{
	char result[digNum+1];
	memset(result, '9', digNum); result[digNum] = '\0';

	printf("Your fillDigits result is %s, and digits is %d\n", result, digNum);
	return strtol(result, NULL, 10);
}

int isPali(int num, int digNum)
{
	char strNum[digNum * 2 + 1];
	snprintf(strNum, digNum*2+1, "%d", num);
	int strNumLen = digNum * 2, i, j;

	for (i = 0, j = strNumLen - 1; i <= (strNumLen - 1)/2; i++, j--) {
		if (strNum[i] != strNum[j]) {
			printf(" This is NOT a palindrome.\n");
			return false;
		}
	}

	printf(" This is a palindrome.\n");
	return true;
}
