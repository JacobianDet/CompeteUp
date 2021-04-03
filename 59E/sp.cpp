#include <bits/stdc++.h>
#define ll long long
#define mp std::make_pair
#define pb push_back

struct rempar
{
	ll x,y,z;
	bool operator <(const rempar& trp) const
	{
		return (x < trp.x) || (((trp.x == x)) && (y < trp.y)) || (((trp.x == x)) && ((trp.y == y)) && (z < trp.z));
	}
};

std::set<rempar> fbd;

std::vector<std::vector<ll> > G(3001);
ll del[3001][3001];
ll p[3001][3001];
ll n,k,m;

void bfs_visit(void)
{
	for(ll i=0;i<3001;i++)
	{
		for(ll j=0;j<3001;j++)
		{
			del[i][j] = 1e10;
			p[i][j] = -1;
		}	
	}	
	std::queue<std::pair<ll, ll> > Q;
	for(ll i=0,j=(ll)G[1].size();i<j;i++)
	{
		del[1][G[1][i]] = 0;
		p[1][G[1][i]] = 0;
		Q.push(mp(1, G[1][i]));
	}
	while(!Q.empty())
	{
		std::pair<ll, ll> f = Q.front();
		Q.pop();
		ll u = f.first;
		ll v = f.second;
		if(v == n && del[n][n] > del[u][v] + 1)
		{
			del[n][n] = del[u][v] + 1;
			p[n][n] = u;
			continue;
		}
		for(ll i=0,j=(ll)G[v].size();i<j;i++)
		{
			if((fbd.find({u,v,G[v][i]}) == fbd.end()) && (del[v][G[v][i]] > del[u][v] + 1))
			{	
				p[v][G[v][i]] = u;
				del[v][G[v][i]] = del[u][v] + 1;
				Q.push(mp(v, G[v][i]));
			}		
		}	
	} 	
	return;
}

int main(void)
{
	std::cin>>n>>m>>k;
	for(ll i=0;i<m;i++)
	{
		ll s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(ll i=0;i<k;i++)
	{
		ll a,b,c;
		std::cin>>a>>b>>c;
		fbd.insert({a,b,c});
	}	
	bfs_visit();
	if(p[n][n] == -1)
	{
		std::cout<<"-1\n";
		return 0;
	}	
	ll v = n;
	ll u = p[n][n];
	std::vector<ll> path;
	path.pb(v);
	while(p[u][v] != 0)
	{
		ll temp = v;
		v = u;
		u = p[u][temp];
		path.pb(v);
	}	
	path.pb(1);
	std::reverse(path.begin(), path.end());
	std::cout<<(ll)path.size()-1<<"\n";
	for(ll i=0,j=(ll)path.size();i<j;i++)
	std::cout<<path[i]<<" ";
	std::cout<<"\n";
	return 0;	
}