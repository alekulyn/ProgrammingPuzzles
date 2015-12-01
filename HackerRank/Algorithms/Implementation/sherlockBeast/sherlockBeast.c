#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *compute(int decNum);
bool isLegit(int pointer);

int main ()
{
	int t;
	scanf("%d", &t); if (t < 1 || t > 20) {exit(-1);}
	
	int n[t];
	char *results[t];
	for (int i = 0; i < t; i++) {
		scanf("%d", &n[i]); if (n[i] < 1 || n[i] > 100000) {exit(-1);}
		results[i] = compute(n[i]);
	}
	
	for (int i = 0; i < t; i++) {
		printf("%s\n", results[i]);
	}
}

char *compute(int decNum)
{
	char *result = (char *) malloc((decNum+1) * sizeof(char)); int pointer = decNum - 1; //Location of last five
	for (int i = 0; i < decNum; i++) {  //Could replace this with memset
		result[i] = '5';
	}
	
	bool legitCheck = isLegit(pointer);
	while (!legitCheck && pointer >= 4) 	{
		for (int i = 0; i < 5; i++, pointer--) {  //Could replace this with memset
			result[pointer] = '3';
		}
		legitCheck = isLegit(pointer);
	}
	
	if (legitCheck == false) {
		return "-1";
	} else {
		return result;
	}
}

bool isLegit(int pointer)
{
	if ((pointer + 1) % 3 == 0) {
		return true;
	} else {
		return false;
	}
}

// 11:55555533333
// 12:555555555555
// 13:5553333333333
// 14:55555555533333