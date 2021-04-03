#include <bits/stdc++.h>

typedef long long ll;

ll modexp(ll a, ll n, ll p)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = (res * a)%p;
		a = (a * a)%p;
		n >>= 1;	
	}
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,p;
		std::cin>>n>>p;
		if(n >= p)
		std::cout<<"0\n";
		else
		{
			ll ans = 1;
			for(ll i=0;i<=(p-n-2);i++)
			ans = (ans * modexp(p-1-i, p-2, p))%p;
			ans = ((p-1) * ans)%p;
			std::cout<<ans<<"\n";
		}	
	}
	return 0;
}