// TODO: GMP Support
#include <stdio.h>
#include <stdlib.h>

struct triangleNumberStruct {
	TRIANGLE_T seed;
	TRIANGLE_T size;
	TRIANGLE_T *triangleNumbers;
} triNumWrap;


void TN_initSeed () {
	triNumWrap.seed = 0;
}

void TN_initSize () {
	triNumWrap.size = 1;
}

void TN_initTriangleNumbers () {
	triNumWrap.triangleNumbers = calloc(triNumWrap.size, sizeof(TRIANGLE_T));
}

void setTriangleNumbers (TRIANGLE_T *triangleNumbers, TRIANGLE_T seed, TRIANGLE_T size) {
	if (triangleNumbers == NULL) {
		TN_initSeed();
		TN_initSize();
		TN_initTriangleNumbers();
	} else {
		triNumWrap.triangleNumbers = triangleNumbers;
		triNumWrap.seed = seed;
		triNumWrap.size = size;
	}
}

void freeTriangleNumbers () {
	free(triNumWrap.triangleNumbers);
}

void TN_nextTriNum () {
	triNumWrap.seed += triNumWrap.size;
	triNumWrap.size++;

	triNumWrap.triangleNumbers = realloc(triNumWrap.triangleNumbers, triNumWrap.size * sizeof(TRIANGLE_T));

	triNumWrap.triangleNumbers[triNumWrap.size-1] = triNumWrap.seed;
}
