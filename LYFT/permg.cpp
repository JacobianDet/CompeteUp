#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<ll> G[100001];
ll arr[100001];
bool vis[100001];
std::pair<bool, bool> memo[100001];

std::pair<bool, bool> dfs_visit(int s)
{
	vis[s] = 1;
	bool aw = 0;
	bool bw = 1;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		memo[G[s][i]] = dfs_visit(G[s][i]);
		aw |= memo[G[s][i]].second;
		bw &= memo[G[s][i]].first;
		if(aw && !bw)
		break;	
	}
	memo[s] = mp(aw, bw);
	return memo[s];
}

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
		for(ll j=(1-i)/arr[i];j<=(n-i)/arr[i];j++)
		{
			if(((arr[i]*j + i) >= 1) && ((arr[i]*j + i) <= n) && (arr[arr[i]*j + i] > arr[i]))
			{	
				G[i].pb(arr[i]*j + i);
			}		
		}
	}	
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		memo[i] = dfs_visit(i);	
	}	
	for(int i=1;i<=n;i++)
	{
		if(memo[i].first)
		std::cout<<"A";
		else std::cout<<"B";	
	}	
	std::cout<<"\n";
	return 0;
}