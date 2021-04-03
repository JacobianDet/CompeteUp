#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<std::pair<int, int> > G[101];
int sze[101], trx[101][2];
int memo[101][101];
int q;

void dfs_visit(int s, int p)
{
	sze[s] = 1;
	std::vector<std::pair<int, int> > chd;
	for(auto u : G[s])
	{
		if(u.first != p)
		{
			chd.pb(u);
			dfs_visit(u.first, s);
			sze[s] += sze[u.first];
		}
	}	
	for(int i=0;i<=std::min(q, sze[s]-1);i++)
	{	
		memo[s][i] = 0;
		trx[i][0] = 0;
		trx[i][1] = 0;
	}	
	for(auto u : chd)
	{
		for(int i=0;i<=std::min(q, sze[s]-1);i++)
		{	
			trx[i][0] = memo[s][i];
			trx[i][1] = memo[s][i];
		}	
		for(int i=1;i<=std::min(q, sze[s]-1);i++)
		{
			for(int j=1;j<=std::min(i, sze[u.first]);j++)
			trx[i][1] = std::max(trx[i][1], trx[i-j][0] + u.second + memo[u.first][j-1]);	
		}
		for(int i=0;i<=std::min(q, sze[s]-1);i++)
		memo[s][i] = trx[i][1];
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n>>q;
	for(int i=0;i<n-1;i++)
	{
		int s,d,w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
	}	
	dfs_visit(1, -1);
	std::cout<<memo[1][q]<<"\n";
	return 0;
}