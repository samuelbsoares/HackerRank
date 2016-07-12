#include <stdlib.h>
#include <stdio.h>
#include <string.h>
    
int main() {
    char str[15];
    int x;
    scanf("%d", &x);
    if(x==1) {
        strcpy(str, "one");
    }
    else if(x==2) {
        strcpy(str, "two");
    }
    else if(x==3) {
        strcpy(str, "three");
    }
    else if(x==4) {
        strcpy(str, "four");
    }
    else if(x==5) {
        strcpy(str, "five");
    }
    else if(x==6) {
        strcpy(str, "six");
    }
    else if(x==7) {
        strcpy(str, "seven");
    }
    else if(x==8) {
        strcpy(str, "eight");
    }
    else if(x==9) {
        strcpy(str, "nine");
    }
    else {
        strcpy(str, "Greater than 9");
    }
    printf("%s", str);
    return 0;
}
