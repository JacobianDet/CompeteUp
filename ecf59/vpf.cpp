#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

int arr[300001], rank[300001];
ll prof[300001], d[300001];
bool vis[300001];

struct allin
{
	ll lx, rx, tx, mx;
	int lid, rid;
}X[300001];

class dsu
{
	public: int root(int x);
			void find_union(int x, int y); 
};

int dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rank[ry] > rank[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	if(rank[rx] == rank[ry])
	rank[rx]++;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	int n;
	ll a, mc = 0;
	std::cin>>n>>a;
	for(int i=1;i<=n;i++)
	{
		std::cin>>d[i]>>prof[i];
		prof[i] = a - prof[i];
		mc = std::max(mc, prof[i]);	
	}
	ll ans = mc;
	std::set<std::pair<ll, ll> > Z;
	for(int i=1;i<n;i++)
	{
		arr[i] = i;
		rank[i] = 0;
		vis[i] = 0;
		X[i].tx = prof[i] + prof[i+1];
 		X[i].lx = std::max(prof[i], X[i].tx);
		X[i].rx = std::max(prof[i+1], X[i].tx);
		X[i].mx = std::max(X[i].lx, std::max(X[i].rx, X[i].tx));
		X[i].lid = i;
		X[i].rid = i+1;
		Z.insert(mp((d[i+1] - d[i]) * (d[i+1] - d[i]), i));
	}
	dsu T;
	while(!Z.empty())
	{
		bool lok = 0, rok = 0;
		std::pair<ll, ll> px = *Z.begin();
		Z.erase(Z.begin());
		int ix = px.second;
		if(ix > 1 && vis[ix-1])
		lok = 1;
		if(ix < n-1 && vis[ix+1])
		rok = 1;	
		if(lok)
		{	
			int rx = T.root(ix-1);
			int ry = T.root(ix);
			T.find_union(ix, ix-1);
			allin res;
			res.lid = X[rx].lid;
			res.rid = X[ry].rid;
			res.lx = std::max(X[rx].lx, X[rx].tx + X[ry].lx - prof[X[ry].lid]);
			res.rx = std::max(X[ry].rx, X[ry].tx + X[rx].rx - prof[X[ry].lid]);
			res.mx = std::max(X[rx].mx, std::max(X[ry].mx, X[rx].rx + X[ry].lx - prof[X[ry].lid]));
			res.tx = X[rx].tx + X[ry].tx - prof[X[ry].lid];
			X[T.root(ix)] = res;
 		}
 		if(rok)
 		{
 			int rx = T.root(ix);
			int ry = T.root(ix+1);
			T.find_union(ix, ix+1);
			allin res;
			res.lid = X[rx].lid;
			res.rid = X[ry].rid;
			res.lx = std::max(X[rx].lx, X[rx].tx + X[ry].lx - prof[X[ry].lid]);
			res.rx = std::max(X[ry].rx, X[ry].tx + X[rx].rx - prof[X[ry].lid]);
			res.mx = std::max(X[rx].mx, std::max(X[ry].mx, X[rx].rx + X[ry].lx - prof[X[ry].lid]));
			res.tx = X[rx].tx + X[ry].tx - prof[X[ry].lid];
			X[T.root(ix)] = res;
 		}		
 		ans = std::max(ans, X[T.root(ix)].mx - px.first);
 		vis[ix] = 1;
	}
	std::cout<<ans<<"\n";
	return 0;
}