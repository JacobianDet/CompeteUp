#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::pair<ll, ll> NE[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
std::vector<int> G[31];
std::pair<ll, ll> coord[31];
int deg[31];

void dfs_visit(int s, int p, ll x, ll y, ll lx, int dir)
{
	coord[s] = mp(x, y);
	int f = 0;
	for(auto u : G[s])
	{
		if((dir == 0 && f == 1) || (dir == 1 && f == 0) || (dir == 2 && f == 3) || (dir == 3 && f == 2))
		f++;
		if(u != p)
		{	
			dfs_visit(u, s, x + lx*NE[f].first, y + lx*NE[f].second, lx>>1, f);
			f++;
		}	
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
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		deg[s]++;
		deg[d]++;
	}
	bool ok = 1;
	for(int i=1;i<=n;i++)
	{
		if(deg[i] > 4)
		{
			ok = 0;
			break;
		}	
	}
	if(!ok)
	std::cout<<"NO\n";
	else
	{
		dfs_visit(1, -1, 0, 0, (1LL<<31), -1);
		std::cout<<"YES\n";
		for(int i=1;i<=n;i++)
		std::cout<<coord[i].first<<" "<<coord[i].second<<"\n";	
	}	
	return 0;
}