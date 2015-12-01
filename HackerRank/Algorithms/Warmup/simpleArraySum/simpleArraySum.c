#include <stdio.h>
#include <string.h>

int main() {
    int sum = 0;
    int how_many;
    scanf("%d", &how_many);
    
    int num_array[how_many];
    for (int i = 0; i < how_many; i++)
    {
        scanf("%d", &num_array[i]);
        sum += num_array[i];
    }
    printf("%d", sum);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}