#include <bits/stdc++.h>

typedef long long ll;

ll lpref[200001], rpref[200001], upref[200001], dpref[200001];

ll bs1(ll n, ll x, ll y)
{
	ll lo = 0;
	ll hi = n;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		bool ok = 0;
		for(ll i=1;i<=n-mid+1;i++)
		{
			ll lv = lpref[i-1] + (lpref[n] - lpref[i+mid-1]);
			ll rv = rpref[i-1] + (rpref[n] - rpref[i+mid-1]);
			ll uv = upref[i-1] + (upref[n] - upref[i+mid-1]);
			ll dv = dpref[i-1] + (dpref[n] - dpref[i+mid-1]);
			ll cv = std::max((x - rv + lv), (rv - lv - x)) + std::max((y - uv + dv), (uv - dv - y));
			if((mid >= cv) && !((mid - cv) & 1))
			{
				ok = 1;
				break;
			}	
			else ok = 0;
		}
		if(!ok)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

int main(void)
{
	ll n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	ll x,y;
	std::cin>>x>>y;
	ll z = abs(x) + abs(y);
	if((n < z) || ((n > z) && ((n - z) & 1)))
	std::cout<<"-1\n";
	else
	{
		for(ll i=0;i<n;i++)
		{
			if(s[i] == 'L')
			lpref[i+1] = 1;
			else if(s[i] == 'R')
			rpref[i+1] = 1;
			else if(s[i] == 'U')
			upref[i+1] = 1;
			else dpref[i+1] = 1;	
		}	
		for(ll i=1;i<=n;i++)
		{
			lpref[i] += lpref[i-1];
			rpref[i] += rpref[i-1];
			upref[i] += upref[i-1];
			dpref[i] += dpref[i-1];
		}	
		ll ans = bs1(n, x, y);
		std::cout<<ans<<"\n";
	}	
	return 0;
}