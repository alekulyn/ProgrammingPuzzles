#include <stdio.h>
#include <stdbool.h>

int main()
{
    long int userin = 4000000;
    int sum = 0;

    long int temp, prev = 0, curr = 1;

    while (true) {  
            temp = curr;
            curr = curr + prev;
            prev = temp;
        
        if (curr % 2) {
           continue; 
        } if (curr > userin)
        {
            break;
        }
        
        printf("%ld\n", curr);
        sum += curr;
    }

    printf("\nThe sum is: %d", sum);
}