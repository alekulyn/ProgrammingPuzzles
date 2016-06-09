// The following iterative sequence is defined for the set of positive integers:
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
// Which starting number, under one million, produces the longest chain?
// NOTE: Once the chain starts the terms are allowed to go above one million.
#include <stdio.h>
#include <inttypes.h>

int main ( int argc, char *argv[] ) {
	uint32_t limit;
	if (argc > 1) {
		sscanf(argv[1], "%"SCNu32, &limit);
	} else {
		scanf("%"SCNu32, &limit);
	}
	fflush(stdout);

	struct {
		uint32_t number;
		uint16_t chain_len;
	} record, this_num;

	for (uint32_t i = 2; i < limit; i++) {
		this_num.number = i; this_num.chain_len = 1;
		uint32_t this_link = i;
		while (this_link != 1) {
			this_num.chain_len++;
			if (this_link % 2 == 0) {
				this_link /= 2;
			} else {
				this_link = (this_link*3) + 1;
			}
		}

		if (this_num.chain_len > record.chain_len) {
			record.chain_len = this_num.chain_len;
			record.number = this_num.number;
		}
	}

	printf("The number with the longest Collatz sequence is %"PRIu32", with a chain length of %"PRIu16, record.number, record.chain_len);
	return 0;
}
