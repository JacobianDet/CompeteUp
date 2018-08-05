#include <bits/stdc++.h>
#define CHOR 1000001

std::vector<long long> phi(CHOR);
std::vector<std::vector<long long>> depth(CHOR);

void phi_solver()
{
    for(long long i=1;i<CHOR;i++)
    phi[i] = i;
    for(long long i=2;i<CHOR;i++)
    {
        if(phi[i] == i)
        {
            for(long long j=i;j<CHOR;j+=i)
            phi[j] = (phi[j]/i)*(i-1);
        }
    }
}

void depth_calc()
{
    for(long long i=1;i<CHOR;i++)
    {
        long long amma=0;
        long long x=i;
        while(x != 1)
        {
            amma++;
            x = phi[x];
        }
        depth[amma].push_back(i);
    }
}

int main(void)
{
    phi_solver();
    depth_calc();
    long long T;
    scanf("%lld",&T);
    for(long long i=0;i<T;i++)
    {
        long long m,n,k,appa=0;
        scanf("%lld %lld %lld",&m,&n,&k);
        for(std::vector<long long>::iterator it=depth[k].begin();it != depth[k].end();it++)
        {
            if((*it) >= m && (*it) <= n)
            appa++;
        }
        printf("%lld\n",appa);
    }
    return 0;
}
