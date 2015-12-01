#include <stdio.h>
#include <stdlib.h>

void decide();

int main()
{
	int t;
	scanf("%d", &t); if (t < 1 || t > 10) {exit(-1);}
	
	for (int i = 0; i < t; i++)
	{
		decide();
	}
}

void decide()
{
	int n, k;
	scanf("%d", &n); if (n < 1 || n > 1000) {exit(-1);}
	scanf("%d", &k); if (k < 1 || k > n) {exit(-1);}
	
	int arrival, ontime = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arrival); if (arrival < -100 || arrival > 100) {exit(-1);}
		if (arrival <= 0)
		{
			ontime++;
		}
	}
	if (ontime >= k)
	{
		printf("NO\n");
	} else
	{
		printf("YES\n");
	}
};