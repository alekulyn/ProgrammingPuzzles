#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    char stair[n+1];
    memset(stair,' ',n);
    for (int i = 0; i < n; i++)
    {
        for (int j = (n - i - 1); j < n; j++)
        {
            stair[j] = '#';
        }
        stair[n] = '\0';
        printf("%*s\n", n, stair);
    }
    return 0;
}