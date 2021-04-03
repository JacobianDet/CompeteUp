#include <bits/stdc++.h>
#define CHOR 1000000007

long long binc(std::pair<long long, long long> p, long long elem)
{
    long long lo = 0;
    long long hi = CHOR;
    while(lo < hi)
    {
        long long mid = lo + (hi-lo)/2;
        if(p.first + mid*p.second <= elem)
        lo = mid + 1;
        else hi = mid;
    }
    return p.first + lo*p.second;
}

int main(void)
{
    long long n;
    std::cin>>n;
    std::vector<std::pair<long long, long long>> p;
    long long s,d;
    for(long long i=0;i<n;i++)
    {
        std::cin>>s>>d;
        p.push_back(std::make_pair(s,d));
    }
    long long z = p[0].first;
    for(long long i=1;i<n;i++)
    z = binc(p[i], z);
    std::cout<<z<<"\n";
    return 0;
}
