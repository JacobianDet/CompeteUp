#include <bits/stdc++.h>
#define CHOR 100000000
using namespace std;

void sieve(vector<long long> &primepos)
{
	vector<bool> eratos(CHOR+1,true);
	eratos[0] = false;
	eratos[1] = false;
	eratos[2] = true;
	primepos.push_back(2);
	for(long long i=4; i <= CHOR; i+=2)
	{
		eratos[i] = false;
	}
	for(long long i=3; i <= CHOR; i+=2)
	{
		if(eratos[i] == true)
		{
			primepos.push_back(i);
			for(long long j=i*i; j <= CHOR; j+=2*i)
			eratos[j]=false;
		}
	}
}

int main() {
	vector<long long> primepos;
	sieve(primepos);
	long long Q;
	scanf("%lld",&Q);
	for(long long i=0;i<Q;i++)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",primepos[n-1]);
	}
	return 0;
}
