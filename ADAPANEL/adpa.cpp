#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 200001
#define MOD 1000000007

std::vector<int> G[CHOR], RG[CHOR];
std::pair<int, int> E[CHOR];
std::vector<int> SCC[CHOR];
std::vector<int> S;
bool vis[CHOR];
int fin[CHOR], cord[CHOR], sx[CHOR], part[CHOR];
int tx;
std::vector<int> GPN;

void pre(void)
{
	for(int i=1;(((3*i-1)*i)/2 <= CHOR);i++)
	{
		GPN.pb(((3*i-1)*i)/2);
		if(((-3*i-1)*(-i))/2 <= CHOR)
		GPN.pb(((-3*i-1)*(-i))/2);
		else break;	
	}	
	part[0] = 1;
	for(int i=1;i<=CHOR;i++)
	{
		int rx = 0, cx = 0;
		bool sg = 1;
		for(auto u : GPN)
		{
			if(u > i)
			break;	
			if(!(cx & 1))
			sg ^= 1;
			if(!sg)
			rx = ((1LL*rx%MOD) + (1LL*part[i-u]%MOD))%MOD;
			else rx = ((1LL*rx%MOD) - (1LL*part[i-u]%MOD) + MOD)%MOD;
			cx++;	
		}
		part[i] = rx;
	}
	return;
}

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
	sx[x]++;
	SCC[x].pb(s);
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    pre();
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    	int s,d;
    	std::cin>>s>>d;
    	s++;
    	d++;
    	G[s].pb(d);
    	RG[d].pb(s);
    	E[i] = mp(s, d);
    }
    tx = 0;
    memset(vis, 0, sizeof(vis));
    memset(fin, 0, sizeof(fin));
    memset(cord, 0, sizeof(cord));
	memset(sx, 0, sizeof(sx));
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
	int ans = 1;
	for(int i=1;i<=x;i++)
	ans = ((1LL*ans%MOD) * (1LL*part[sx[i]]%MOD))%MOD;
	std::cout<<ans<<"\n";
	return 0;	
}