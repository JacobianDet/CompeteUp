#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

std::pair<int, int> TG[15];

ll memo[(1<<15)][4];

ll PUL(int n, int mask, int gn)
{
	if(!__builtin_popcount(mask))
	return 1;
	if(memo[mask][gn] != -1)
	return memo[mask][gn];	
	ll ax = 0;
	for(int i=0;i<n;i++)
	{
		if((mask & (1<<i)) && (TG[i].second-1 == gn))
		{
			if(__builtin_popcount(mask ^ (1<<i)))
			{	
				if(!gn)
				ax = ((ax%MOD) + (((PUL(n, mask ^ (1<<i), 1)%MOD) + (PUL(n, mask ^ (1<<i), 2)%MOD))%MOD))%MOD;
				else if(gn == 1)
				ax = ((ax%MOD) + (((PUL(n, mask ^ (1<<i), 0)%MOD) + (PUL(n, mask ^ (1<<i), 2)%MOD))%MOD))%MOD;	
				else ax = ((ax%MOD) + (((PUL(n, mask ^ (1<<i), 0)%MOD) + (PUL(n, mask ^ (1<<i), 1)%MOD))%MOD))%MOD;
			}
			else ax = ((ax%MOD) + (PUL(n, mask ^ (1<<i), 3)%MOD))%MOD;	
		}	
	}
	memo[mask][gn] = ax;
	return ax;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n,T;
	std::cin>>n>>T;
	for(int i=0;i<n;i++)
	std::cin>>TG[i].first>>TG[i].second;
	ll ans = 0;
	for(int i=0;i<(1<<n);i++)
	{
		for(int x=0;x<3;x++)
		{	
			int tx = 0;
			for(int j=0;j<n;j++)
			{
				if(i & (1<<j))
				tx += TG[j].first;	
			}	
			if(tx == T)
			ans = ((ans%MOD) + (PUL(n, i, x)%MOD))%MOD;
		}		
	}	
	std::cout<<ans<<"\n";
	return 0;
}