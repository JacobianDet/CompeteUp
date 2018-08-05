#include <bits/stdc++.h>

void segsieve(std::vector<bool> &isPrime,long long m,long long n)
{
    for (long long i = 2; i * i <= n; ++i)
    {
        for (long long j = std::max(i * i, (m + (i - 1)) / i * i); j <= n; j += i)
        {
            isPrime[j - m] = false;
        }
    }
    if(m == 1)
    isPrime[0] = false;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long T;
    std::cin>>T;
    for(long long i=0;i<T;i++)
    {
        long long m,n;
        std::cin>>m>>n;
        std::vector<bool> isPrime(n-m+1,true);
        segsieve(isPrime,m,n);
        for(long long j=0,k=(int)isPrime.size();j<k;j++)
        {
            if(isPrime[j] == true)
            std::cout<<j+m<<std::endl;
        }
    }
    return 0;
}
