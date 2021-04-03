#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define CHOR 100001

typedef long long ll;

struct x3
{
	int s,d;
	ll w;
}E[CHOR];

std::vector<std::pair<int, ll> > T[CHOR];
int knn[CHOR], arr[CHOR], sze[CHOR];
bool mark[CHOR];

class dsu
{
	public: int root(int x);
			bool find_union(int x, int y); 
};

int dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

bool dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return 0;
	if(sze[ry] > sze[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	sze[rx] += sze[ry];
	return 1;
}

bool cmpx(x3 X, x3 W)
{
	if(X.w < W.w)
	return 1;
	else if((X.w == W.w) && (X.s < W.s))
	return 1;
	else if((X.w == W.w) && (X.s == W.s) && (X.d < W.d))
	return 1;
	else return 0;	
}

std::pair<ll, bool> dfs_visit(int s, int p)
{
	ll ans = 0;
	for(auto u : T[s])
	{
		if(u.first != p)
		{
			std::pair<ll, bool> px = dfs_visit(u.first, s);
			mark[s] |= px.second;
			if(px.second)
			ans = std::max(ans, std::max(px.first, u.second));	
		}
	}
	return mp(ans, mark[s]);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,k;
	std::cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		std::cin>>knn[i];
		mark[knn[i]] = 1;
	}	
	for(int i=0;i<m;i++)
	{
		int s,d;
		ll w;
		std::cin>>s>>d>>w;
		E[i] = {s, d, w};			
	}	
	std::sort(E, E+m, cmpx);
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	dsu V;
	for(int i=0;i<m;i++)
	{
		if(V.find_union(E[i].s, E[i].d))
		{
			T[E[i].s].pb(mp(E[i].d, E[i].w));
			T[E[i].d].pb(mp(E[i].s, E[i].w));
		}
	}
	ll ans = dfs_visit(knn[1], -1).first;
	for(int i=0;i<k;i++)
	std::cout<<ans<<" ";
	std::cout<<"\n";
	return 0;	
}