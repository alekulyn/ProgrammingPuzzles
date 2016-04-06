// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool validate_triple(int, int, int);

int total = 1000;

int main(int argc, char *argv[]) {
	for (int c = 997; c > 0; c -= 4) {
		for (int b = c-1; b > 0; b--) {
			for (int a = b-1; a > 0; a--) {
				if (validate_triple(a, b, c)) {
					printf("Found triple %d %d %d.  It's product is %d.\n", a, b, c, a*b*c);
					return 0;
				}
			}
		}
	}
}

bool validate_triple(int a, int b, int c) {
	bool is_triple = (pow(a, 2) + pow(b, 2) == pow(c, 2));
	bool is_total = (a+b+c == total);

	return is_triple && is_total;
}
