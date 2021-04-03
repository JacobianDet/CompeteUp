#include <bits/stdc++.h>
#define ll long long

ll m,s;
ll mpow[21];
ll memo[21][1001];

ll ppal(ll i, ll modx)
{
	if(i == ceil((float)(s+1)/2))
	{
		ll ans = 0;
		for(ll j=0;j<=9;j++)
		{
			if(i == s && !j)
			continue;	
			ll res = 0;
			if(floor((float)(s+1)/2) != ceil((float)(s+1)/2))
			res = (((mpow[i]%m) * (j%m))%m + ((mpow[s-i+1]%m) * (j%m))%m)%m;
			else res = ((mpow[i]%m) * (j%m))%m;
			if(!((modx + res)%m))
			ans += 1;
		}	
		return ans;
	}	
	if(memo[i][modx] != -1)
	return memo[i][modx];	
	ll ans = 0;
	for(ll j=0;j<=9;j++)
	{
		if(i == s && !j)
		continue;	
		ll res = ((((mpow[i]%m) * (j%m))%m) + (((mpow[s-i+1]%m) * (j%m))%m))%m;
		ans += ppal(i-1, (modx + res)%m);
	}
	memo[i][modx] = ans;
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
		memset(mpow,1,sizeof(mpow));
		memset(memo,-1,sizeof(memo));
		std::cin>>m>>s;
		for(ll i=2;i<21;i++)
		mpow[i] = ((mpow[i-1]%m) * (10%m))%m;
		ll ans = ppal(s, 0);
		std::cout<<ans<<"\n";
	}	
	return 0;
}