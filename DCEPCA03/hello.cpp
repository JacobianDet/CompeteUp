#include <bits/stdc++.h>
#define CHOR 10000

std::vector<long long> phi(CHOR);

void phi_solver()
{
    for(long long i=1;i<=CHOR;i++)
    phi[i] = i;
    for(long long i=2;i<=CHOR;i++)
    {
        if(phi[i] == i)
        {
            for(long long j=i;j<=CHOR;j+=i)
            phi[j] = (phi[j]/i)*(i-1);
        }
    }
}

int main(void)
{
    phi_solver();
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long n,x=0;
        std::cin>>n;
        for(long long j=1;j<=n;j++)
        x += phi[j];
        x = x*x;
        std::cout<<x<<std::endl;
    }
    return 0;
}
