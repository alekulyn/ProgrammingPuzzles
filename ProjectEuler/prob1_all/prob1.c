#include <stdio.h>

main()
{
    int userin = 1000;
    int sum = 0;
    
    int i;
    // Find multiples of 3, add to sum
    for (i = 3; i < userin; i += 3) {
        sum += i;
    }
    
    for (i = 5; i < userin; i += 5) {
        if (i % 3 == 0) {
            // Multiples of 3 have already been added, next iteration
            continue;
        }
        sum += i;
    }
    
    printf("%d", sum);
}