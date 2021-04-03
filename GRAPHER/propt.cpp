#include <bits/stdc++.h>
#define pb push_back
#define MV 200001

struct sidx
{
	int val, odx, evx;
}seg[4*MV];

bool lvl[MV];
int lazy[4*MV], arr[MV], st[MV], sz[MV], cnv[MV];
std::vector<int> G[MV];
int tx;

class segtree
{
	public: void build(int i, int s, int d);
			sidx merger(sidx left, sidx right);
			void update(int i, int s, int d, int qs, int qd, int val);
			sidx query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].val = arr[cnv[s]];
		seg[i].odx = (lvl[cnv[s]] & 1);
		seg[i].evx = !(lvl[cnv[s]] & 1);
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

sidx segtree::merger(sidx left, sidx right)
{
	sidx res;
	res.val = left.val + right.val;
	res.odx = left.odx + right.odx;
	res.evx = left.evx + right.evx;
	return res;
}

void segtree::update(int i, int s, int d, int qs, int qd, int val)
{
	if(lazy[i] != 0)
	{
		seg[i].val += ((seg[i].evx - seg[i].odx) * lazy[i]);
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		} 
		lazy[i] = 0;
	}
	if(qs > d || qd < s)
	return;
	if(qs <= s && d <= qd)
	{
		seg[i].val += ((seg[i].evx - seg[i].odx) * val);
		if(s < d)
		{
			lazy[2*i] += val;
			lazy[2*i+1] += val;
		}
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, val);
	update(2*i+1, m+1, d, qs, qd, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

sidx segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != 0)
	{
		seg[i].val += ((seg[i].evx - seg[i].odx) * lazy[i]);
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		} 
		lazy[i] = 0;
	}
	if(qs > d || qd < s)
	return {0, 0, 0};
	if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	sidx p1 = query(2*i, s, m, qs, qd);
	sidx p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);
}

void dfs_visit(int s, int p)
{
	if(p != -1)
	lvl[s] = (1 ^ lvl[p]);
	tx++;
	st[s] = tx;
	cnv[tx] = s;
	sz[s]++;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			sz[s] += sz[u];
		}
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	tx = 0;
	dfs_visit(1, -1);
	segtree T;
	T.build(1, 1, n);
	while(m--)
	{
		int ty;
		std::cin>>ty;
		if(--ty)
		{
			int x;
			std::cin>>x;
			std::cout<<T.query(1, 1, n, st[x], st[x]).val<<"\n";
		}
		else
		{
			int x, val;
			std::cin>>x>>val;
			if(lvl[x] & 1)
			val = -val;
			T.update(1, 1, n, st[x], st[x] + sz[x] - 1, val);	
		}
	}
	return 0;
}