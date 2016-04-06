// The four adjacent digits in the 1000-digit number that have the greatest product are 9 * 9 * 8 * 9 = 5832.
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

// TODO: Better variable names.
// TODO: Better modularity/organization.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char nmbr_grid[] =
"73167176531330624919225119674426574742355349194934"
"96983520312774506326239578318016984801869478851843"
"85861560789112949495459501737958331952853208805511"
"12540698747158523863050715693290963295227443043557"
"66896648950445244523161731856403098711121722383113"
"62229893423380308135336276614282806444486645238749"
"30358907296290491560440772390713810515859307960866"
"70172427121883998797908792274921901699720888093776"
"65727333001053367881220235421809751254540594752243"
"52584907711670556013604839586446706324415722155397"
"53697817977846174064955149290862569321978468622482"
"83972241375657056057490261407972968652414535100474"
"82166370484403199890008895243450658541227588666881"
"16427171479924442928230863465674813919123162824586"
"17866458359124566529476545682848912883142607690042"
"24219022671055626321111109370544217506941658960408"
"07198403850962455444362981230987879927244284909188"
"84580156166097919133875499200524063689912560717606"
"05886116467109405077541002256983155200055935729725"
"71636269561882670428252483600823257530420752963450"
;

struct {
	int adjct;
	int crr_idx;

	unsigned long long highscore;
	int *pdct_fctr;
} State;

int main(int argc, char *argv[]) {
	if (argc > 1) {
		State.adjct = strtol(argv[1], NULL, 10);
	} else {
		scanf("%d", &State.adjct);
	}
	State.pdct_fctr = realloc(State.pdct_fctr, sizeof(int) * State.adjct);

	for (int zero_prox = -1; State.crr_idx+State.adjct < strlen(nmbr_grid);	State.crr_idx++, zero_prox--) {
		if (zero_prox < 0) {  //Find next zero
			char *crr_char = nmbr_grid+State.crr_idx;
			zero_prox = strchr(crr_char, '0') - crr_char;
		}
		if (zero_prox < State.adjct) {  //If the next zero is within range
			State.crr_idx += zero_prox;
			zero_prox = -1;
			continue;
		}

		unsigned long long thisPdct = 1;
		for (int i = 0; i < State.adjct; i++) {
			thisPdct *= (nmbr_grid[State.crr_idx+i] - '0');
		}

		if (thisPdct > State.highscore) {
			//DEBUG
			printf("Overriding %llu with %llu and factors: ", State.highscore, thisPdct);
			for (int i = 0; i < State.adjct; i++) {
				State.pdct_fctr[i] = nmbr_grid[State.crr_idx+i];
				printf("%c ", State.pdct_fctr[i]);
			} printf("\n");

			State.highscore = thisPdct;
		}
	}

	printf("The greatest product from %d adjacent digits is %llu, with factors of: ", State.adjct, State.highscore);
	for (int i = 0; i < State.adjct; i++) {
		printf("%c ", State.pdct_fctr[i]);
	} printf("\n");
	free(State.pdct_fctr);
}
