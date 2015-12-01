#include <stdio.h>
#include <string.h>

int main()
{
	int t = 0;
	scanf("%d", &t);
	if (t < 1 || t > 10)
	{
		return -1;
	}

	int n[t]; for (int i = 0; i < t; ++i) {n[i] = -1;}
	int final_heights[t]; for (int i = 0; i < t; ++i) {final_heights[i] = 1;}
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n[i]);
		if (n[i] < 0 || n[i] > 60)
		{
			return -1;
		}
	}
	
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			if (j % 2 == 0)
			{
				final_heights[i] *= 2;
			} else if (j % 2 == 1)
			{
				final_heights[i]++;
			}
		}
	}
	
	for (int i = 0; i < t; i++)
	{
		printf("%d\n", final_heights[i]);
	}
}