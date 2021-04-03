#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::map<ll, ll> mii;
	int n;
	std::cin>>n;
	ll pref[n+1];
	memset(pref,0,sizeof(pref));
	for(int i=1;i<=n;i++)
	{
		ll t;
		std::cin>>t;
		pref[i] = pref[i-1] + t;
	}
	ll ctr = 0;
	for(int i=1;i<=n;i++)
	{
		mii[pref[i]]++;
		if(!pref[i])
		ctr++;	
	}	
	for(std::map<ll, ll>::iterator it = mii.begin(); it != mii.end(); it++)
	{
		ll t = it->second;
		if(t < 2)
		continue;
		else ctr += (t*t-t)/2;
	}	
	std::cout<<ctr<<"\n";
	return 0;
}