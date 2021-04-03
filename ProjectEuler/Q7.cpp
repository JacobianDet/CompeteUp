#include <bits/stdc++.h>
#define pb push_back

bool sieve[10000000];

void siever(void)
{
	memset(sieve, true, sizeof(sieve));
	sieve[0] = false;
	sieve[1] = false;
	for(int p=2; p*p < 10000000; p++)
	{
		if(sieve[p])
		{
			for(int i=p*p; i<10000000; i+=p)
			sieve[i] = false;	
		}	
	}	
	return;
}

int main(void)
{
	siever();
	std::vector<int> p;
	for(int i=1;i<10000000;i++)
	{
		if(sieve[i])
		p.pb(i);	
	}	
	std::cout<<p[10000]<<"\n";
	return 0;
}