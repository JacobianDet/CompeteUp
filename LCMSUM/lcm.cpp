#include <bits/stdc++.h>
#define CHOR 1000001

std::vector<long long> phi(CHOR);
std::vector<long long> calcm(CHOR);

void etf()
{
	for(long long i=1;i<CHOR;i++)
	phi[i] = i;
	for(long long i=2;i<CHOR;i++)
	{
		if(phi[i] == i)
		{
			for(long long j=i;j<CHOR;j+=i)
				phi[j] = phi[j]*(i-1)/i;
		}
	}
}

void dsor()
{
    for(long long j=1;j<CHOR;j++)
    {
        for(long long i=2*j;i<CHOR;i+=j)
        calcm[i] = calcm[i] + i*phi[i/j]/(2*j);
    }
    for(long long i=1;i<CHOR;i++)
    {
    	if(i == 1)
    	calcm[i] = 1;
    	else calcm[i] = i*(calcm[i] + 1);
    }
}

int main(void)
{
    etf();
    dsor();
    long long T;
    scanf("%lld",&T);
    for(long long i=0;i<T;i++)
    {
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",calcm[n]);
    }
    return 0;
}
