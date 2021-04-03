#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

int vx[100001];
std::vector<int> G[100001];
int lvl[100001], par[100001], st[100001], ts[100001], sx[100001];
int P[100001][20];
int tx, DZ;
std::vector<int> valx[100001];
std::vector<int> seg[400004];

void dfs_visit(int s, int p)
{
	st[s] = 0;
	lvl[s] = 0;
	par[s] = 0;
	if(p != -1)
	{
		lvl[s] += (1 + lvl[p]);
		par[s] = p;
	}	
	tx++;
	st[s] = tx;
	ts[tx] = s;
	for(auto u : G[s])
	{
		if(u != p)
		{	
			dfs_visit(u, s);
			sx[s] += sx[u];
		}		
	}
	sx[s]++;
	return;
}

void ZFX(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(!(lvl[i] % DZ))
		{
			int p = i;
			while(p != 1)
			{
				valx[i].pb(vx[p]); 
				p = par[p];
			}	
			valx[i].pb(vx[1]);
			std::sort(valx[i].begin(), valx[i].end());
		}	
	}
	return;
}

struct segtree
{
	public: void build(int i, int s, int d);
			std::vector<int> merger(std::vector<int>& left, std::vector<int>& right);
			int query(int i, int s, int d, int qs, int qd, int l, int r); 
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].clear();
		seg[i].pb(vx[ts[s]]);
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i].clear();
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

std::vector<int> segtree::merger(std::vector<int>& left, std::vector<int>& right)
{
	std::vector<int> res;
	int i=0, j=0, n1 = (int)left.size(), n2 = (int)right.size();
	while((i != n1) && (j != n2))
	{
		if(left[i] < right[j])
		{
			res.pb(left[i]);
			i++;
		}	
		else if(left[i] > right[j])
		{
			res.pb(right[j]);
			j++;
		}	
		else
		{
			res.pb(left[i]);
			res.pb(right[j]);
			i++;
			j++;
		}
	}
	while(i != n1)
	{
		res.pb(left[i]);
		i++;
	}
	while(j != n2)
	{
		res.pb(right[j]);
		j++;
	}
	return res;
}

int segtree::query(int i, int s, int d, int qs, int qd, int l, int r)
{
	if((s > qd) || (d < qs))
	return 0;
	if(qs <= s && d <= qd)
	{
		int px1 = std::upper_bound(seg[i].begin(), seg[i].end(), r) - seg[i].begin();
		int px2 = std::lower_bound(seg[i].begin(), seg[i].end(), l) - seg[i].begin();
		return (px1 - px2);
	}
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd, l, r);
	int p2 = query(2*i+1, m+1, d, qs, qd, l, r);
	return (p1 + p2);
}

void ST_build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		P[i][j] = -1;
	}
	for(int i=1;i<=n;i++)
	P[i][0] = par[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];
		}	
	}
	return;	
}
 
int LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}
	int l2 = 0;
	for(l2=1;(1<<l2)<=lvl[p];l2++);
	l2--;
	for(int i=l2;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];	
	}	
	if(p == q)
	return p;	
	for(int i=l2;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}
	}	
	return par[p];
}
 
int xdist(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
	}	
    int lx = 0;
    for(lx=0;(1<<lx)<=lvl[p];lx++);
    lx--;
    for(int i=lx;i>=0;i--)
    {
        if((lvl[p] - (1<<i)) >= (lvl[q]+1))
        p = P[p][i];
    }
    return p;
}

int calc(int s, int l, int r)
{
	int ct = 0;
	if(s == 1)
	return 0;
	int p = par[s];
	while(lvl[p] % DZ)
	{
		if(vx[p] >= l && vx[p] <= r)
		ct++;
		p = par[p];	
	}	
	int px1 = std::upper_bound(valx[p].begin(), valx[p].end(), r) - valx[p].begin();
	int px2 = std::lower_bound(valx[p].begin(), valx[p].end(), l) - valx[p].begin();
	ct += (px1 - px2);
	return ct;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	tx = 0;
	DZ = 1000;
	int n,q,p;
	std::cin>>n>>q>>p;
	for(int i=1;i<=n;i++)
	valx[i].clear();
	for(int i=1;i<=n;i++)
	{	
		std::cin>>vx[i];
		vx[i] %= p;
	}
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}			
	dfs_visit(1, -1);
	ST_build(n);
	ZFX(n);
	segtree T;
	T.build(1, 1, n);
	int ans = 0;
	while(q--)
	{
		int a,b,l1,r1,l2,r2;
		std::cin>>a>>b>>l1>>r1>>l2>>r2;
		a ^= ans;
		b ^= ans;
		l1 ^= ans;
		r1 ^= ans;
		l2 ^= ans;
		r2 ^= ans;
		int z = LCA_find(a, b);
		int xv = 0, yv = 0;
		if(a != z)
		yv = T.query(1, 1, n, st[a] + 1, st[a] + sx[a] - 1, l2, r2);
		else 
		{
			int xd = xdist(a, b);
			yv = T.query(1, 1, n, st[1], st[1] + sx[1] - 1, l2, r2) - T.query(1, 1, n, st[xd], st[xd] + sx[xd] - 1, l2, r2) - (((vx[z] >= l2) && (vx[z] <= r2)) ? 1 : 0);
		}
		if(yv)
		xv = calc(a, l1, r1) + calc(b, l1, r1) - 2*calc(z, l1, r1) - (((vx[z] >= l1) && (vx[z] <= r1)) ? 1 : 0);	
		ans = xv * yv;
		std::cout<<ans<<"\n";	
	}
	return 0;
}