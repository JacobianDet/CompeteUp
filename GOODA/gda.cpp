#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 1000001

typedef long long ll;

std::vector<int> G[CHOR], RG[CHOR];
std::pair<int, int> E[CHOR];
std::vector<int> SCC[CHOR];
std::vector<int> S;
std::map<std::pair<int, int>, int> EL;
bool vis[CHOR];
int fin[CHOR], cord[CHOR];
ll sx1[CHOR], sx2[CHOR], arr[CHOR];
int tx;

void dfs_vis1(int s)
{
	vis[s] = 1;
	tx++;
	for(auto u : G[s])
	{
		if(!vis[u])
		dfs_vis1(u);	
	}
	tx++;
	fin[s] = tx;
	S.pb(s);
	return;
}

void dfs_vis2(int s, int x)
{
	vis[s] = 1;
	cord[s] = x;
	sx1[x] += arr[s];
	sx2[x] += arr[s];
	SCC[x].pb(s);
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}	
	return;
}

void dfs_vis3(int s)
{
	vis[s] = 1;
	ll sum = 0;
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			dfs_vis3(u);
			sum = std::max(sum, sx2[u]);
		}
		else sum = std::max(sum, sx2[u]);	
	}
	sx2[s] += sum;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,m,st,en;
    std::cin>>n>>m>>st>>en;
    for(int i=1;i<=n;i++)
    std::cin>>arr[i];	
    for(int i=0;i<m;i++)
    {
    	int s,d;
    	std::cin>>s>>d;
    	G[s].pb(d);
    	RG[d].pb(s);
    	E[i] = mp(s, d);
    }
    tx = 0;
    memset(vis, 0, sizeof(vis));
    memset(fin, 0, sizeof(fin));
    memset(cord, 0, sizeof(cord));
    memset(sx1, 0, sizeof(sx1));
    memset(sx2, 0, sizeof(sx2));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs_vis1(i);	
	}	
	std::reverse(S.begin(), S.end());
	memset(vis, 0, sizeof(vis));
	int x = 0;
	for(int i=0;i<n;i++)
	{
		if(!vis[S[i]])
		{
			x++;
			dfs_vis2(S[i], x);
		}
	}
	for(int i=1;i<=n;i++)
	G[i].clear();	
	for(int i=0;i<m;i++)
	{
		int s = cord[E[i].first], d = cord[E[i].second];
		if(s != d && !EL[mp(s, d)] && !EL[mp(d, s)])
		{
			G[s].pb(d);
			EL[mp(s, d)] = 1;
			EL[mp(d, s)] = 1;
		}		
	}	
	memset(vis, 0, sizeof(vis));
	dfs_vis3(cord[st]);
	std::cout<<(sx2[cord[st]] - sx2[cord[en]] + sx1[cord[en]])<<"\n";
	return 0;
}