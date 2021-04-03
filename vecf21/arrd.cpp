#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001], pref[100001], suf[100001];
std::map<ll, ll> lind;
std::map<ll, ll> rind;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	std::cin>>arr[i];
	for(ll i=1;i<=n;i++)
	{
		if(i == 1)
		pref[i] = arr[i];
		else pref[i] = pref[i-1] + arr[i];	
	}
	for(ll i=n;i>=1;i--)
	{
		if(i == n)
		suf[i] = arr[i];
		else suf[i] = suf[i+1] + arr[i];	
	}
	for(ll i=1;i<=n;i++)
	{
		if(!lind[arr[i]])
		lind[arr[i]] = i;	
	}	
	for(ll i=n;i>=1;i--)
	{
		if(!rind[arr[i]])
		rind[arr[i]] = i;	
	}
	bool ok = 0;
	for(ll i=0;i<n;i++)
	{
		//std::cout<<pref[i]<<" "<<suf[i+1]<<"\n";
		if(pref[i] > suf[i+1])
		{	
			ll vx = pref[i] - suf[i+1];
			if(!(vx & 1))
			{
				if(lind[vx>>1] && lind[vx>>1] <= i)
				{
					ok = 1;
					break;
				}	
			}
		}
		else if(suf[i+1] > pref[i])
		{
			ll vx = suf[i+1] - pref[i];
			if(!(vx & 1))
			{
				if(rind[vx>>1] && rind[vx>>1] >= i+1)
				{
					ok = 1;
					break;
				}	
			}
		}		
		else
		{
			ok = 1;
			break;
		}
	}
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}