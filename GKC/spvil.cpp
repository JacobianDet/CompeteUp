#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define INF 1000000000000000000

typedef long long ll;

std::pair<ll, ll> E[1001];
std::vector<ll> G[51];
std::vector<ll> RG[51];
bool vis[51];
std::vector<ll> finx;
ll tx;
ll cord[51], SCC[51], EX[51];
ll dist[51][51];

void dfs_vis1(ll s)
{
	vis[s] = 1;
	tx++;
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		dfs_vis1(G[s][i]);	
	}	
	tx++;
	finx.pb(s);
	return;
}

void dfs_vis2(ll s, ll x)
{
	vis[s] = 1;
	cord[s] = x;
	SCC[x]++;
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		dfs_vis2(G[s][i], x);	
	}
	return;
}

int main(void)
{
	freopen("Q2x.in","r",stdin);
	freopen("Q2x.txt","w",stdout);
	ll T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		tx = 0;
		ll n,m;
		std::cin>>n>>m;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(i != j)
				dist[i][j] = INF;	
			}	
		}	
		for(ll i=0;i<m;i++)
		{
			ll s,d,w;
			std::cin>>s>>d>>w;
			dist[s][d] = w;
			dist[d][s] = w;
		}	
		for(ll k=1;k<=n;k++)
		{
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);	
			}	
		}
		for(ll i=1;i<=n;i++)
		dist[i][i] = INF;	
		for(ll i=1;i<=n;i++)
		{
			std::vector<ll> Z;
			ll cmin = INF;
			for(ll j=1;j<=n;j++)
			{
				if(dist[i][j] < cmin)
				{
					cmin = dist[i][j];
					Z.clear();
					Z.pb(j);
				}	
				else if(dist[i][j] == cmin)
				Z.pb(j);	
			}	
			if(cmin != INF)
			G[i] = Z;
		}	
		ll x = 0;
		for(ll i=1;i<=n;i++)
		{
			for(ll j=0,k=(ll)G[i].size();j<k;j++)
			{
				E[x] = mp(i, G[i][j]);
				x++;
			}
		}
		m = x;
		for(ll i=0;i<m;i++)
		{
			ll s = E[i].first;
			ll d = E[i].second;
			RG[d].pb(s);
		}	
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])
			dfs_vis1(i);	
		}	
		memset(vis, 0, sizeof(vis));
		std::reverse(finx.begin(), finx.end());
		x = 0;
		for(ll i=0;i<n;i++)
		{
			if(!vis[finx[i]])
			{
				x++;
				dfs_vis2(finx[i], x);
			}	
			G[finx[i]].clear();	
		}	
		memset(vis, 0, sizeof(vis));
		for(ll i=0;i<m;i++)
		{
			ll s = E[i].first;
			ll d = E[i].second;
			s = cord[s];
			d = cord[d];
			if(s != d)
			G[s].pb(d);	
		}	
		ll ans = 1;
		for(ll i=1;i<=x;i++)
		{
			if(G[i].size() != 0)
			EX[i] = (ll)G[i].size();	
			else EX[i] = (1LL<<SCC[i]) - 2;
		}	
		for(ll i=1;i<=x;i++)
		ans *= EX[i];
		std::cout<<"Case #"<<t<<": "<<ans<<"\n";	
	}
	return 0;
}