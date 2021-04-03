#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

ll arr[500001];
std::vector<ll> vx1, vx2;

ll bs1(ll v, ll k)
{
	ll lo = 0;
	ll hi = k-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(vx2[mid] < v)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(vx2[lo] >= v)
	return lo;
	else return -1;	
}

int main(void)
{
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll t;
		std::cin>>t;
		arr[i] = arr[i-1] + t;
	}	
	for(ll i=1;i<=n-2;i++)
	{
		if(3*arr[i] == arr[n])
		vx1.pb(i+1);	
	}	
	for(ll i=n-1;i>=2;i--)
	{
		if(2*arr[n] == 3*arr[i])
		vx2.pb(i);	
	}
	std::sort(vx1.begin(), vx1.end());
	std::sort(vx2.begin(), vx2.end());
	ll ans = 0;
	ll k = vx2.size();
	for(ll i=0,j=(ll)vx1.size();i<j;i++)
	{
		ll t = bs1(vx1[i], k);
		if(t != -1)
		ans += (k-t);	
	}	
	std::cout<<ans<<"\n";
	return 0;
}