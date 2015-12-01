#include <math.h>
#include <stdio.h>
#include <string.h>

int main(){
    int n; 
    scanf("%d",&n);
    int a[n][n], pri_diag[n], sec_diag[n];
    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
           scanf("%d",&a[i][j]);
           if (i == j)
           {
               pri_diag[i] = a[i][j];
           }
           if (i + j + 1 == n)
           {
               sec_diag[i] = a[i][j];
           }           
       }
    }
    
    int pri_diag_sum = 0, sec_diag_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pri_diag_sum += pri_diag[i];
        sec_diag_sum += sec_diag[i];
    }

    printf("%d", abs(pri_diag_sum - sec_diag_sum));
    return 0;
}
