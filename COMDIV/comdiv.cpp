#include <bits/stdc++.h>
#define CHOR 1000001

std::vector<long long> minp(CHOR, 0);

void sievem()
{
    for(long long p=2;p*p<CHOR;p++)
    {
        if(minp[p] == 0)
        {
            for(long long i=p*p;i<CHOR;i+=p)
            {
                if(minp[i] == 0)
                minp[i] = p;
            }
        }
    }
    for(long long p=2;p<CHOR;p++)
    {
        if(minp[p] == 0)
        minp[p] = p;
    }
}

void prime(long long X,std::vector<std::pair<long long, long long>>& p)
{
   long long uc=0;
   while(X != 1)
   {
       long long temp1 = minp[X];
       X /= minp[X];
       uc++;
       long long temp2 = minp[X];
       if(temp1 != temp2)
       {
            p.push_back(std::make_pair(temp1, uc));
            uc = 0;
       }
   }
}

int main(void)
{
    sievem();
    long long T;
    scanf("%lld",&T);
    for(long long i=0;i<T;i++)
    {
        long long A,B;
        scanf("%lld %lld",&A,&B);
        std::vector<std::pair<long long, long long>> d1;
        long long comdiv=1;
        prime(std::__gcd(A,B),d1);
        for(std::vector<std::pair<long long, long long>>::iterator it=d1.begin();it!=d1.end();it++)
        comdiv *= ((it->second) + 1);
        printf("%lld\n",comdiv);
    }
    return 0;
}
