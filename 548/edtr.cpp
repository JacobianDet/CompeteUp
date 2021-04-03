#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define MOD 1000000007

typedef long long ll;

std::vector<int> G[100001];
bool vis[100001];

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

ll dfs_visit(int s)
{
	ll ct = 1;
	vis[s] = 1;
	for(auto u : G[s])
	{
		if(!vis[u])
		ct += dfs_visit(u);	
	}
	return ct;
}

int main(void)
{	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int s,d,c;
		std::cin>>s>>d>>c;
		if(c)
		continue;
		G[s].pb(d);
		G[d].pb(s);	
	}
	ll ans = modexp(n, k)%MOD;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ll cc = dfs_visit(i);
			ans = ((ans%MOD) - (modexp(cc, k)%MOD) + MOD)%MOD;
		}	
	}
	std::cout<<ans<<"\n";
	return 0;
}