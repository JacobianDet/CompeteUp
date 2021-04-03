#include <bits/stdc++.h>
#define ll long long
#define CHOR 10000000

bool sieve[CHOR];

ll siever(void)
{
	ll n = 600851475143;
	memset(sieve, true, sizeof(sieve));
	sieve[0] = false;
	sieve[1] = false;
	for(ll p=2; p*p <= CHOR; p++)
	{
		if(sieve[p])
		{
			for(ll i=p*p; i < CHOR; i+=p)
			sieve[i] = false;	
		}	
	}
	for(ll i=1;i<1e7;i++)
	{
		if(sieve[i])
		{
			while((n/i) > 1 && !(n%i))
			n /= i;	
		}	
	}	
	return n; 
}

int main(void)
{
	std::cout<<siever()<<"\n";
	return 0;
}