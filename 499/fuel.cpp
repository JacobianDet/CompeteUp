#include <bits/stdc++.h>

typedef long double ld;

int a[1001], b[1001];

ld bs1(int n, int m)
{
    ld lo = (ld)0;
    ld hi = (ld)2000000000;
    for(int t=0;t<1000;t++)
    {
        ld mid = (lo + hi)/2;
        ld fl = mid;
        fl -= ((ld)m + fl)/(ld)a[0];
        for(int i=1;i<n;i++)
        {
            if(fl >= 0)
            fl -= ((ld)m + fl)/(ld)b[i];
            else break;
            if(fl >= 0)
            fl -= ((ld)m + fl)/(ld)a[i];
            else break;
        }
        if(fl >= 0)
        fl -= ((ld)m + fl)/(ld)b[0];
        if(fl >= 0)
        hi = mid;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
    scanf("%d", &a[i]);
    for(int i=0;i<n;i++)
    scanf("%d", &b[i]);
    bool ok = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == 1 || b[i] == 1)
        {
            ok = 1;
            break;
        }
    }
    if(ok)
    printf("-1\n");
    else
    {
        ld ans = bs1(n, m);
        if(ans > 1000000000)
        printf("-1\n");
        else printf("%.10Lf\n", ans);
    }    
    return 0;
}