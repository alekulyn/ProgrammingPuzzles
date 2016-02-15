// The sum of the squares of the first ten natural numbers is,
// 1^2 + 2^2 + ... + 10^2 = 385
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
#include <stdio.h>
#include <math.h>

int main() {
	int end_nmbr;
	scanf("%d", &end_nmbr);

	unsigned long long sum_of_sq = 0;
	unsigned long long sq_of_sum = 0;

	for (int i = 1; i <= end_nmbr; i++) {
		sum_of_sq += pow(i, 2);
		sq_of_sum += i;
	}
	sq_of_sum = pow(sq_of_sum, 2);

	printf("Counting up to %d\n", end_nmbr);
	printf("The sum of the squares is: %lld\n", sum_of_sq);
	printf("The square of the sum is: %lld\n", sq_of_sum);
	printf("Their difference is: %lld\n", sq_of_sum - sum_of_sq);

	return 0;
}
