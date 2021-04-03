#include <bits/stdc++.h>
#define CHOR 10000001

typedef long long ll;

ll lo[CHOR];

ll fexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}	
	return res;
}

void lo_val(void)
{
	for(ll i=1;i<CHOR;i++)
	{
		lo[i] = i;
	}	
	for(ll i=2;i<CHOR;i++)
	{
		if(lo[i] == i)
		{
			for(ll j=i*i;j<CHOR;j+=i)
			{
				if(lo[j] == j)
				lo[j] = i;	
			}	
		}	
	}
	return;
}		

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	lo_val();
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		ll prod = 1;
		while(lo[n] != 1)
		{
			ll ctr = 0;
			ll p = lo[n];
			while(p == lo[n])
			{
				ctr++;
				n /= lo[n];
			}
			prod *= (fexp(p, 2*ctr) - (fexp(p, 2*ctr) - 1)/(p + 1));	
		}	
		std::cout<<prod<<"\n";
	}	
	return 0;
}