#include <bits/stdc++.h>

long long binc(long long b, std::vector<long long> &p)
{
    long long n = p.size();
    long long lo = 1;
    long long hi = *std::max_element(p.begin(), p.end());
    while(lo < hi)
    {
        long long mid = lo + (hi-lo)/2;
        long long j = 0,res = 0,pop = 0;
        for(long long i=1;i<=b;i++)
        {
            if(p[j]-pop >= mid)
            res = mid;
            else res = p[j]-pop;
            pop += res;
            if(pop == p[j] && j != n)
            {
                j++;
                res = 0;
                pop = 0;
            }
            if(j == n)
            break;
        }
        if(j < n)
        lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main(void)
{
    long long n,b;
    scanf("%lld %lld",&n,&b);
    while(n != -1 && b != -1)
    {
        std::vector<long long> p(n);
        for(long long i=0;i<n;i++)
        scanf("%lld",&p[i]);
        long long ans = binc(b,p);
        printf("%lld\n\n",ans);
        scanf("%lld %lld",&n,&b);
    }
    return 0;
}
