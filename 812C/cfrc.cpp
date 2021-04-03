#include <bits/stdc++.h>

std::pair<long long, long long> binc(std::vector<long long> &ar, long long s)
{
    long long n = ar.size();
    long long lo = 0;
    long long hi = n;
    long long mx = 0;
    while(lo < hi)
    {
        long long mid = lo + (hi-lo+1)/2;
        long long c = 0;
        std::vector<long long> modi(n, 0);
        for(long long i=0;i<n;i++)
        modi[i] = ar[i] + (i+1)*mid;
        std::sort(modi.begin(), modi.end());
        for(long long i=0;i<mid;i++)
        c += modi[i];
        if(c > s)
        hi = mid-1;
        else{
            lo = mid;
            mx = c;
        }
    }
    if(lo == 0)
    mx = 0;
    return std::make_pair(lo, mx);
}

int main(void)
{
    long long n,s;
    std::cin>>n>>s;
    std::vector<long long> ar(n);
    for(long long i=0;i<n;i++)
    std::cin>>ar[i];
    std::pair<long long, long long> p = binc(ar, s);
    std::cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}
