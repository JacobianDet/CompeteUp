#include <bits/stdc++.h>

typedef long long ll;

ll df[200001];
std::map<ll, bool> sv;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=0;i<n-1;i++)
	std::cin>>df[i];
	ll lb = 1, rb = n, ps = 0;
	sv[ps] = 1;
	bool ok = 1;
	for(ll i=0;i<n-1;i++)	
	{
		ps += df[i];
		if(sv[ps])
		{
			ok = 0;
			break;
		}	
		else sv[ps] = 1;
		lb = std::max(lb, (ll)1-ps);
		rb = std::min(rb, (ll)n-ps);
	}
	if(lb > rb)
	ok = 0;
	if(!ok)	
	std::cout<<"-1\n";
	else
	{
		std::cout<<lb<<" ";
		for(ll i=0;i<n-1;i++)
		{
			lb += df[i];
			std::cout<<lb<<" ";
		}	
		std::cout<<"\n";
	}	
	return 0;
}