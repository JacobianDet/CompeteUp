#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

int main(void)
{
	ll n,k,s;
	std::cin>>n>>k>>s;
	if((n-1)*k < s || k > s)
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		ll st = 1;
		for(ll i=k;i>0;i--)
		{
			ll jp = ceil((ld)s/i);
			ll rs = 0;
			if(st + jp <= n)
			rs = st + jp;
			else rs = st - jp;	
			std::cout<<rs<<" ";
			st = rs;
			s -= jp;
		}	
		std::cout<<"\n";
	}
	return 0;
}