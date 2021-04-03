#include <bits/stdc++.h>

typedef long double ld;

int main(void)
{
    int n,rx;
    scanf("%d %d", &n, &rx);
    ld r = rx;
    ld PI = atan(1) * 4;
    ld R = (r * sin(PI/n))/(1 - sin(PI/n));
    printf("%.12Lf\n", R);
    return 0;
}