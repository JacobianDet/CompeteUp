#include <bits/stdc++.h>

bool sieve[21];

void siever(void)
{
	memset(sieve, true, sizeof(sieve));
	sieve[0] = false;
	sieve[1] = false;
	for(int p=2; p*p < 20; p++)
	{
		if(sieve[p])
		{
			for(int i=p*p; i<=20; i+=p)
			sieve[i] = false;	
		}	
	}	
	return;
}

int expr(int a, int n)
{
	int res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}	
	return res;
}

int main(void)
{
	siever();
	int ans = 1;
	for(int i=1; i<=20; i++)
	{
		if(sieve[i])
		{
			int ct = 1;
			while(expr(i, ct) <= 20)
			ct++;
			ct--;
			ans *= expr(i, ct);	
		}	
	}	
	std::cout<<ans<<"\n";
	return 0;
}