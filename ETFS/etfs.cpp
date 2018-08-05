#include <bits/stdc++.h>
#define CHOR 10000001

std::vector<bool> segpre(CHOR, true);
std::vector<long long> primes;

void presieve(void)
{
    segpre[0] = false;
    segpre[1] = false;
    for(long long p=2;p*p<CHOR;p++)
    {
        if(segpre[p] == true)
        {
            for(long long i=p*p;i<CHOR;i+=p)
            segpre[i] = false;
        }
    }
    for(long long p=2;p<CHOR;p++)
    {
        if(segpre[p] == true)
        primes.push_back(p);
    }
}

void phi_calc(std::vector<long long>& phi,std::vector<long long>& lpr,long long a,long long b)
{
   long long j;
   for(long long i=0,z=(long long)primes.size();i<z;i++)
   {
       if(a % primes[i] == 0)
       j = a;
       else j = ((a/primes[i])+1)*primes[i];
       for( ;j<=b;j+=primes[i])
       {
            while(lpr[j-a]%primes[i] == 0)
            lpr[j-a] /= primes[i];
            phi[j-a] = (phi[j-a]/primes[i])*(primes[i]-1);
       }
   }
   for(j=a;j<=b;j++)
   {
       if(lpr[j-a] != 1)
       phi[j-a] = (phi[j-a]/lpr[j-a])*(lpr[j-a]-1);
   }
}

int main(void)
{
    presieve();
    long long a,b;
    scanf("%lld %lld",&a,&b);
    std::vector<long long> phi(b-a+1);
    std::vector<long long> lpr(b-a+1);
    for(long long i=a;i<=b;i++)
    {
        lpr[i-a] = i;
        phi[i-a] = i;
    }
    phi_calc(phi,lpr,a,b);
    for(long long i=a;i<=b;i++)
    printf("%lld\n",phi[i-a]);
    return 0;
}
