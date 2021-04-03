#include <bits/stdc++.h>

typedef long long ll;

ll bs1(ll val)
{
	ll lo = 0;
	ll hi = 1000000;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if((mid * mid) < val)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

ll bs2(ll val)
{
	ll lo = 0;
	ll hi = 1000000;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if((mid * mid) > val)
		hi = mid - 1;
		else lo = mid;	
	}
	return lo;
}

struct circ
{
	ll x, y, r;
}arr[1001];

ll Z[1000005];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,q;
	std::cin>>n>>q;
	for(int i=0;i<n;i++)
	std::cin>>arr[i].x>>arr[i].y>>arr[i].r;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((arr[i].x != arr[j].x) || (arr[i].y != arr[j].y) || (arr[i].r != arr[j].r))
			{
				ll dx = abs(arr[i].x - arr[j].x);
				ll dy = abs(arr[i].y - arr[j].y);
				ll c1 = bs2((dx * dx) + (dy * dy));
				ll c2 = bs1((dx * dx) + (dy * dy));
				ll rs = arr[i].r + arr[j].r;
				ll rd = abs(arr[i].r - arr[j].r);
				if((c1 >= rs) || ((c1 == rs) && (c2 > rs)))
				{
					ll mn = c2 - rs;
					ll mx = c1 + rs;
					Z[mn]++;
					Z[mx+1]--;
				}	
				else if((c2 <= rs) && ((c1 > rd) || ((c1 == rd) && (c2 > rd))))
				{
					ll mn = 0;
					ll mx = c1 + rs;
					Z[mn]++;
					Z[mx+1]--;
				}	
				else if((c2 >= 0) && (c2 <= rd))
				{
					ll mn = rd - c1;
					ll mx = c1 + rs;
					Z[mn]++;
					Z[mx+1]--;
				}	
			}	
		}	
	}
	for(int i=1;i<1000005;i++)
	Z[i] += Z[i-1];	
	while(q--)
	{
		ll k;
		std::cin>>k;
		std::cout<<Z[k]<<"\n";
	}	
	return 0;
}