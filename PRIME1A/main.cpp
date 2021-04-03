#include <bits/stdc++.h>
#define CHOR 100001

std::vector<bool> segpre(CHOR, true);
std::vector<long long> primes;

void presieve(void)
{
    segpre[0] = false;
    segpre[1] = false;
    for(long long p=2;p*p<=CHOR;p++)
    {
        if(segpre[p] == true)
        {
            for(long long i=p*p;i<=CHOR;i+=p)
            segpre[i] = false;
        }
    }
    for(long long p=2;p<=CHOR;p++)
    {
        if(segpre[p] == true)
        primes.push_back(p);
    }
}

void segsieve(std::vector<bool>& segs,long long l,long long r)
{
   long long j;
   if(l == 1)
   segs[0] = false;
   for(long long i=0,z=(long long)primes.size();i<z;i++)
   {
       if((l%primes[i] == 0) && (l != primes[i]))
       j = l;
       else if(l/primes[i] == 0)
       j = primes[i]*primes[i];
       else j = (l/primes[i] + 1)*primes[i];
       for( ;j<=r;j+=primes[i])
       segs[j-l] = false;
   }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    presieve();
    int T;
    std::cin>>T;
    for(int i=0;i<T;i++)
    {
        long long l,r;
        std::cin>>l>>r;
        std::vector<bool> segs(r-l+1, true);
        segsieve(segs,l,r);
        for(long long j=l;j<=r;j++)
        {
            if(segs[j-l] == true)
            std::cout<<j<<std::endl;
        }
    }
    return 0;
}
