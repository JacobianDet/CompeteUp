#include <bits/stdc++.h>

typedef long long ll;

ll a[100001], b[100001]; 

ll bs1(ll n, ll m)
{
	ll mx = 0;
	for(int i=0;i<n;i++)
	mx = std::max(mx, a[i] * b[i]);
	ll lo = 0;
	ll hi = mx;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		ll ctr = 0;
		for(int i=0;i<n;i++)
		{
			if(mid >= a[i] * b[i])
			continue;
			else ctr += (a[i] - mid/b[i]);	
		}	
		if(ctr > m)
		lo = mid + 1;
		else hi = mid;	
	}	
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	for(int i=0;i<n;i++)
	std::cin>>b[i];
	ll ans = bs1(n, m);	
	std::cout<<ans<<"\n";
	return 0;	
}