#include <bits/stdc++.h>

long long binaryx(std::vector<long long> sloc, long long C)
{
    std::sort(sloc.begin(), sloc.end());
    long long n = sloc.size();
    long long lo = 1;
    long long hi = sloc[n-1] - sloc[0];
    while(lo < hi)
    {
        long long mid = lo + (hi-lo+1)/2;
        long long noc = 1, mcord = sloc[0];
        for(long long i=1;i<n;i++)
        {
            if(sloc[i] - mcord < mid)
            continue;
            else {
                 noc++;
                 mcord = sloc[i];
            }
        }
        if(noc < C)
        hi = mid - 1;
        else lo = mid;
    }
    return lo;
}

int main(void)
{
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long N,C;
        std::cin>>N>>C;
        std::vector<long long> sloc(N);
        for(long long j=0;j<N;j++)
        std::cin>>sloc[j];
        long long res = binaryx(sloc,C);
        std::cout<<res<<std::endl;
    }
    return 0;
}
