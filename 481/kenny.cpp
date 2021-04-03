#include <bits/stdc++.h>
#define CHOR 200001
#define pb push_back

typedef long long ll;

std::vector<ll> yo;

ll bs1(ll x)
{
	ll lo = 0;
	ll hi = (ll)yo.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo)/2;
		if(yo[mid] < x)
		lo = mid + 1;
		else hi = mid;	
	}	
	return lo;
}

int main(void)
{	
	ll n,k;
	std::cin>>n>>k;
	ll axe[n+1];
	ll sk[n+1];
	memset(sk,0,sizeof(sk));
	for(ll i=1;i<=n;i++)
	{	
		std::cin>>axe[i];
		yo.pb(axe[i]);
	}	
	std::sort(yo.begin(), yo.end());
	for(ll i=0;i<k;i++)
	{
		ll s,d;
		std::cin>>s>>d;
		if(axe[s] < axe[d])
		sk[d]--;
		if(axe[d] < axe[s])
		sk[s]--;	
	}	
	for(ll i=1;i<=n;i++)
	{
		ll x = bs1(axe[i]);
		sk[i] += x;
		std::cout<<sk[i]<<" ";
	}	
	std::cout<<"\n";
	return 0;
}