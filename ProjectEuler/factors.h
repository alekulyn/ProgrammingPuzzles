// TODO: GMP Support

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct factorStruct {
	FACTOR_T factor;
	FACTOR_T size;
	FACTOR_T *factors;
} Factor;

void factorize (FACTOR_T factorArg) {
	Factor.factor = factorArg;
	Factor.size = 0;

	for (int i = 1; i <= sqrt(Factor.factor); i++) {
		if (Factor.factor % i == 0) {
			Factor.size++;
			Factor.factors = realloc(Factor.factors, sizeof(FACTOR_T) * Factor.size);
			Factor.factors[Factor.size-1] = i;
		}
	}

	// Find next half of factors
	Factor.factors = realloc(Factor.factors, sizeof(FACTOR_T) * Factor.size * 2);
	for (int i = Factor.size-1, j = Factor.size; i >= 0; i--, j++) {
		int quotient = Factor.factor / Factor.factors[i];
		if (quotient == Factor.factors[i]) {
			j--;
			continue;
		} else {
			Factor.factors[j] = quotient;
			Factor.size++;
		}
	}
}

