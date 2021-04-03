#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define MV 100001

typedef long long ll;

struct t3
{
    ll v,b;
}seg[4*MV];

ll arr[MV], lazy[4*MV];
std::vector<int> G[MV];
int dsc[MV], tvl[MV], sze[MV];
int tx;

void dfs_visit(int s, int p)
{
    tx++;
    dsc[s] = tx;
    tvl[tx] = s;
    sze[s] = 1;
    for(auto u : G[s])
    {
        if(u != p)
        {
            dfs_visit(u, s);
            sze[s] += sze[u];
        }
    }
    return;
}

class segtree
{
	public: void build(int i, int s, int d);
			t3 merger(t3 left, t3 right);
			void updatev(int i, int s, int d, int qs, int qd, ll v);
			void updateb(int i, int s, int d, int x);
			t3 query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {arr[s], 0};
		lazy[i] = 0;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	lazy[i] = 0;
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

t3 segtree::merger(t3 left, t3 right)
{
	t3 res;
	res.v = left.v + right.v;
	res.b = left.b + right.b;
	return res;
}

void segtree::updateb(int i, int s, int d, int x)
{
    if(lazy[i] != 0)
	{
		seg[i].v += 1LL*(d-s+1-seg[i].b) * lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s == d)
	{
	   if(seg[i].b)
	   seg[i].b = 0;
	   else seg[i].b = 1;
	   return;
	}
	int m = (s + d)/2;
	if(x <= m)
	updateb(2*i, s, m, x);
	else updateb(2*i+1, m+1, d, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

void segtree::updatev(int i, int s, int d, int qs, int qd, ll v)
{
    if(lazy[i] != 0)
	{
		seg[i].v += 1LL*(d-s+1-seg[i].b) * lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
	    seg[i].v += (d-s+1-seg[i].b) * v;
	    if(s < d)
		{
			lazy[2*i] += v;
			lazy[2*i+1] += v;
		}
		return;
	}
	int m = (s + d)/2;
	updatev(2*i, s, m, qs, qd, v);
	updatev(2*i+1, m+1, d, qs, qd, v);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

t3 segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != 0)
	{
		seg[i].v += 1LL*(d-s+1-seg[i].b) * lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return {0, 0};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	t3 p1 = query(2*i, s, m, qs, qd);
	t3 p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
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
        int s, d;
        std::cin>>s>>d;
        G[s].pb(d);
        G[d].pb(s);
    }
    tx = 0;
    dfs_visit(1, -1);
    for(int i=1;i<=n;i++)
    std::cin>>arr[dsc[i]];
    segtree T;
    T.build(1, 1, n);
    int q;
    std::cin>>q;
    while(q--)
    {
        int t;
        std::cin>>t;
        if(t == 1)
        {
            int nd;
            ll v;
            std::cin>>nd>>v;
            T.updatev(1, 1, n, dsc[nd], dsc[nd]+sze[nd]-1, v);
        }
        else if(t == 2)
        {
            int nd;
            ll v;
            std::cin>>nd>>v;
            T.updatev(1, 1, n, dsc[nd], dsc[nd], v);
        }
        else if(t == 3)
        {
            int nd;
            std::cin>>nd;
            T.updateb(1, 1, n, dsc[nd]);
        }
        else
        {
            int nd;
            std::cin>>nd;
            std::cout<<T.query(1, 1, n, dsc[nd], dsc[nd]).v<<"\n";
        }
    }
    return 0;
}