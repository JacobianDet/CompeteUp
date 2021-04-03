#include <bits/stdc++.h>
#define pb push_back
#define ll long long

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
	ll sum = 0;
	for(int i=1;i<2000000;i++)
	{
		if(sieve[i])
		sum += i;
	}	
	std::cout<<sum<<"\n";
	return 0;
}