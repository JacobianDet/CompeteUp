#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	int q;
	std::cin>>q;
	for(int i=0;i<q;i++)
	{
		ll l,r;
		std::cin>>l>>r;
		ll ans = 0;
		for(ll i = l; i <= r; i += ((~i)&(i+1)))
		ans = i;
		std::cout<<ans<<"\n";
	}
	return 0;	
}