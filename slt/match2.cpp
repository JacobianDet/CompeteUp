#include <bits/stdc++.h>
#define pb push_back 
#define mp std::make_pair
#define MV 100001

int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int a[MV], b[MV];
std::vector<std::vector<int> > vfx;

int seg[4*MV], lazy[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			void update(int i, int s, int d, int qs, int qd, int val);
			int query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		if(a[s] == b[s])
		seg[i] = 1;
		else seg[i] = 0;
		lazy[i] = 0;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = merger(lazy[2*i], lazy[2*i+1]);
	return;
}

int segtree::merger(int left, int right)
{
	return (left + right);
}

void segtree::update(int i, int s, int d, int qs, int qd, int val)
{
	if(lazy[i])
	{
		if(!vfx[lazy[i]].size())
		seg[i] = 0;
		else seg[i] = (std::upper_bound(vfx[lazy[i]].begin(), vfx[lazy[i]].end(), d) - std::lower_bound(vfx[lazy[i]].begin(), vfx[lazy[i]].end(), s));
		if(s < d)
		{
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
		}
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		if(!vfx[val].size())
		seg[i] = 0;
		else seg[i] = (std::upper_bound(vfx[val].begin(), vfx[val].end(), d) - std::lower_bound(vfx[val].begin(), vfx[val].end(), s));
		if(s < d)
		{
			lazy[2*i] = val;
			lazy[2*i+1] = val;
		}
		lazy[i] = 0;
		return;
	}
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, val);
	update(2*i+1, m+1, d, qs, qd, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i])
	{
		if(!vfx[lazy[i]].size())
		seg[i] = 0;
		else seg[i] = (std::upper_bound(vfx[lazy[i]].begin(), vfx[lazy[i]].end(), d) - std::lower_bound(vfx[lazy[i]].begin(), vfx[lazy[i]].end(), s));
		if(s < d)
		{
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
		}
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return 0;
	if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	T = readInt();
	while(T--)
	{
		std::map<int, int> cord;
		vfx.resize(500001);
		int n,q;
		n = readInt();
		q = readInt();
		int x = 0;
		for(int i=1;i<=n;i++)
		{
			int t;
			t = readInt();
			if(!cord[t])
			{
				x++;
				cord[t] = x;
				a[i] = x;
			}
			else a[i] = cord[t];
		}	
		int pv = 0;
		for(int i=1;i<=n;i++)
		{
			int t;
			t = readInt();
			if(!cord[t])
			{
				x++;
				cord[t] = x;
				b[i] = x;
			}
			else b[i] = cord[t];
			vfx[cord[t]].pb(i);
			if(a[i] == b[i])
			pv++;
		}	
		segtree D;
		D.build(1, 1, n);     
		while(q--)
		{
			int l,r,v;
			l = readInt();
			r = readInt();
			v = readInt();
			l = l ^ pv;
			r = r ^ pv;
			v = v ^ pv;
			if(!cord[v])
			{
				x++;
				cord[v] = x;
				v = x;
			}
			else v = cord[v];
			D.update(1, 1, n, l, r, v);
			pv = seg[1];      
			std::cout<<pv<<"\n";
		}
		vfx.clear();
	}
	return 0;
}