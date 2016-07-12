#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int d;
    long ld;
    long long lld;
    char c;
    float f;
    double lf;
    scanf("%d %ld %lld %c %f %lf", &d, &ld, &lld, &c, &f, &lf);
    printf("%d\n%ld\n%lld\n%c\n%f\n%lf", d, ld, lld, c, f, lf);
    return 0;
}
