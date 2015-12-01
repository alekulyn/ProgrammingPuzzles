#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int processDividend(long long unsigned int);

int main()
{
	int t;
	scanf("%d", &t);  if (t < 1 || t > 15) {exit(0);}
	
	long long unsigned int n[t];
	int results[t];
	for (int i = 0; i < t; i++) {
		scanf("%I64u", &n[i]);  //%I64u for Windows, and %llu for *nix
		if (t <= 0 || t >= pow(10, 10)) {exit(0);}
		results[i] = processDividend(n[i]);
	}
	
	for (int i = 0; i < t; i++) {
		printf("%d\n", results[i]);
	}
}

int processDividend(long long unsigned int dividend)
{
	//10 + 2 is for 10^10 plus the 1 and the null character
	char str_dividend[10+2]; int counter = 0;
	snprintf(str_dividend, 10+2, "%d", dividend);

	for (int i = 0; i < strlen(str_dividend); i++) {
		char this_digit[2]; strncpy(this_digit, &str_dividend[i], 1); this_digit[1] = '\0';
		if (strcmp(this_digit, "0") == 0) {
			continue;
		}
		if (dividend % strtol(this_digit, NULL, 10) == 0) {
			counter++;
		}
	}
	return counter;
}