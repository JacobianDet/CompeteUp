#include <bits/stdc++.h>
#define pb push_back
#define INF 1000000000

std::vector<int> G[100001];
bool aff[100001];
int dfx[100001];
int d;

void dfs_vis1(int s, int p)
{
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_vis1(u, s);
			dfx[s] = std::max(dfx[s], 1 + dfx[u]);
		}
	}
	return;	
}

int dfs_vis2(int s, int p, int dst)
{
	int md1 = -INF, md2 = -INF, ct = 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			if(md1 < dfx[u] + 1)
			{
				md2 = md1;
				md1 = dfx[u] + 1;
			}	
			else if((md1 >= dfx[u] + 1) && (md2 < dfx[u] + 1))
			md2 = dfx[u] + 1;	
		}
	}
	if(md1 < dst)
	{
		md2 = md1;
		md1 = dst;
	}	
	else if((md1 >= dst) && (md2 < dst))
	md2 = dst;
	if(aff[s])
	{
		md1 = std::max(0, md1);
		md2 = std::max(0, md2);
	}		
	for(auto u : G[s])
	{
		if(u != p)
		{
			if(md1 == dfx[u] + 1)
			ct += dfs_vis2(u, s, md2 + 1);
			else ct += dfs_vis2(u, s, md1 + 1);	
		}
	}
	if(md1 <= d && dfx[s] <= d)	
	ct++;
	return ct;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
	{
		int t;
		std::cin>>t;
		aff[t] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!aff[i])
		dfx[i] = -INF;
		else dfx[i] = 0;
	}	
	for(int i=0;i<n-1;i++)
	{
		int s,df;
		std::cin>>s>>df;
		G[s].pb(df);
		G[df].pb(s);
	}	
	dfs_vis1(1, -1);
	int ans = dfs_vis2(1, -1, (aff[1] ? 0 : -INF));
	std::cout<<ans<<"\n";
	return 0;
}