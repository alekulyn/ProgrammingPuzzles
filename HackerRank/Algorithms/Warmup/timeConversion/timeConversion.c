#include <stdio.h>
#include <string.h>

int main(){
    int hh, mm, ss;
    char afternoon[2];
    scanf("%2d:%2d:%2d%2s", &hh, &mm, &ss, afternoon);
    
    //Check for erroneous values
    if (hh > 12 || hh < 1) {
        return -1;
    } else if (mm > 59 || mm < 0) {
        return -1;
    } else if (ss > 59 || ss < 0) {
        return -1;
    } else if ((strcmp(afternoon, "AM") != 0) && (strcmp(afternoon, "PM") != 0)) {
        return -1;
    }
    
    if (strcmp(afternoon, "PM") == 0 && hh != 12) {
        hh += 12;
    } else if (strcmp(afternoon, "AM") == 0 && hh == 12) {
        hh = 0;
    }

    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}