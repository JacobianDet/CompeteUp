#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 2000001
#define MOD 1000000007

typedef long long ll;

std::vector<int> G[CHOR], RG[CHOR];
std::pair<int, int> E[CHOR];
std::vector<int> SCC[CHOR];
std::vector<int> S;
std::map<std::pair<int, int>, int> EL;
bool vis[CHOR];
int fin[CHOR], cord[CHOR];
int tx;

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
	SCC[x].pb(s);
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}	
	return;
}

void dfs_vis3(int s, int &ct)
{
	vis[s] = 1;
	for(auto u : G[s])
	{
		ct++;
		if(!vis[u])
		dfs_vis3(u, ct);		
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int d;
    	std::cin>>d;
    	G[i].pb(d);
    	RG[d].pb(i);
    	E[i-1] = mp(i, d);
    }
    tx = 0;
    memset(vis, 0, sizeof(vis));
    memset(fin, 0, sizeof(fin));
    memset(cord, 0, sizeof(cord));
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
	for(int i=0;i<n;i++)
	{
		int s = cord[E[i].first], d = cord[E[i].second];
		if(s != d && !EL[mp(s, d)] && !EL[mp(d, s)])
		{
			G[s].pb(d);
			EL[mp(s, d)] = 1;
			EL[mp(d, s)] = 1;
		}		
	}
	ll fx = 1;
	int ct = 0;
	for(int i=1;i<=x;i++)
	{
		ll sz = (int)SCC[i].size();
		if(sz == 1)
		continue;
		else fx = ((fx%MOD) * (((modexp(2, sz)%MOD) - 2)%MOD))%MOD;	
	}
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=x;i++)
	{
		if(!vis[i])
		dfs_vis3(i, ct);	
	}	
	fx = ((fx%MOD) * (modexp(2, ct)%MOD))%MOD;
	std::cout<<fx<<"\n";
	return 0;	
}		