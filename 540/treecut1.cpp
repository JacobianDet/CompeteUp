#include <bits/stdc++.h>
#define pb push_back

int sze[3][300001], col[300001];
std::vector<int> G[300001];

void dfs_vis1(int s, int p)
{
	sze[col[s]][s]++;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_vis1(u, s);
			for(int i=0;i<3;i++)
			sze[i][s] += sze[i][u];	
		}
	}
	return;
}

int dfs_vis2(int s, int p, int rz, int bz)
{
	int ans = 0;
	if(col[s] == 1)
	rz++;
	else if(col[s] == 2)
	bz++;	
	for(auto u : G[s])
	{
		if(u != p)
		{
			rz += sze[1][u];
			bz += sze[2][u];	
		}	
	}
	for(auto u : G[s])
	{
		if(u != p)
		{
			if(((sze[1][u] && !sze[2][u]) || (!sze[1][u] && sze[2][u])) && (((rz - sze[1][u]) && !(bz - sze[2][u])) || (!(rz - sze[1][u]) && (bz - sze[2][u]))))
			ans++;
			ans += dfs_vis2(u, s, rz - sze[1][u], bz - sze[2][u]);
		}	
	}	
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>col[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_vis1(1, -1);
	int ans = dfs_vis2(1, -1, 0, 0);
	std::cout<<ans<<"\n";
	return 0;
}