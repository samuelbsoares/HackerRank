#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int x, y;
    x = *a;
    y = *b;
    *a = x + y;
    *b = abs(x - y);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
