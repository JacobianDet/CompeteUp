#include <bits/stdc++.h>
#define CHOR 1000000001

std::vector<long long> phi(CHOR);

void etf()
{
    for(long long i=1;i < CHOR;i++)
    phi[i] = i;
    for(long long i = 2; i < CHOR; i++)
    {
        if(phi[i] == i)
        {
            for(long long j = i; j < CHOR; j+=i)
            phi[j] = phi[j]*(i - 1)/i;
        }
    }
}

int main(void)
{
    etf();
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long n;
        std::cin>>n;
        std::cout<<phi[n]<<std::endl;
    }
    return 0;
}
