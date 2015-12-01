#include <stdio.h>
#include <string.h>

int main(){
    int n; 
    scanf("%d",&n);
    if (n < 1 || n > 10)
    {
        return -1;
    }
    int arr[n];
    long long sum = 0;
    
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
       if (arr[arr_i] < 0 || arr[arr_i] > pow(10, 10))
       {
           return -1;
       }
       sum += arr[arr_i];
    }
    printf("%lld", sum);
    return 0;
}