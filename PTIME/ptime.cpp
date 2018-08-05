#include <bits/stdc++.h>
#define CHOR 10001

std::vector<bool> ispr(CHOR, true);
std::vector<long long> primex;

void siever()
{
    for(long long p=2; p*p < CHOR; p++)
    {
        if(ispr[p] == true)
        {
            for(long long i=p*p; i<CHOR; i+=p)
            ispr[i] = false;
        }
    }
    for(long long p=2; p<CHOR; p++)
    {
        if(ispr[p] == true)
        primex.push_back(p);
    }
}

int main(void)
{
    siever();
    long long n;
    std::cin>>n;
    for(long long i=0,j=primex.size();((i<j)&&(primex[i] <= n)); i++)
    {
        if(i != 0)
        std::cout<<" * ";
        long long ctor=1;
        for(long long j=2*primex[i];j<=n;j+=primex[i])
        {
            long long X=j;
            while(X % primex[i] == 0)
            {
                ctor++;
                X /= primex[i];
            }
        }
        std::cout<<primex[i]<<"^"<<ctor;
    }
    std::cout<<"\n";
    return 0;
}
