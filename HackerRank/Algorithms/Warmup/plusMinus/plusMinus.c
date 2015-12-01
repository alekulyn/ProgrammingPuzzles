#include <stdio.h>

int main(){
    const int POSI=0, NEGA=1, ZERO=2;
    int n, count[3] = {0}; 
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
       scanf("%d",&arr[i]);
       if (arr[i] > 0)
       {
           count[POSI] += 1;
       } else if (arr[i] < 0)
       {
           count[NEGA] += 1;
       } else if (arr[i] == 0)
       {
           count[ZERO] += 1;
       }
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("%6F\n", ((double) count[i])/((double) n));
    }
    return 0;
}
