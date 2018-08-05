#include <bits/stdc++.h>
typedef long long ll;

struct order
{
	ll s,f,p;
};

ll n;
order Z[10000];
ll memo[10000];

bool compare(order a, order b)
{
	if(a.s < b.s)
	return true;
	else if((a.s == b.s) && (a.f < b.f))
	return true;
	else return false;	
}

ll binx(ll i)
{
	ll beg = 0;
	ll end = n-1;
	while(beg < end)
	{
		ll mid = beg + (end - beg)/2;
		if(Z[mid].s < Z[i].f)
		beg = mid + 1;
		else end = mid;	
	}	
	if(Z[beg].s < Z[i].f)
	return -1;
	else return beg;	
}

ll rent(ll i)
{
	if(i == n)
	return 0;
	if(memo[i] != -1)
	return memo[i];	
	ll ans = 0;
	ll ind = binx(i);
	if(ind == -1)
	ans = Z[i].p;
	else ans = Z[i].p + rent(ind);
	ans = std::max(ans, rent(i+1));
	memo[i] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	while(T--)
	{
		memset(memo, -1, sizeof(memo));
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			ll s,d,p;
			std::cin>>s>>d>>p;
			Z[i].s = s;
			Z[i].f = s+d;
			Z[i].p = p;
		}	
		std::sort(Z, Z+n, compare);
		ll ans = rent(0);
		std::cout<<ans<<"\n";
	}	
	return 0;
}	