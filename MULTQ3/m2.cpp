#include <bits/stdc++.h>
#define MV 100001

struct m2
{
	int ct[2];
}seg[4*MV];

int lazy[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			m2 merger(m2 left, m2 right);
			void update(int i, int s, int d, int qs, int qd);
			int query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].ct[0] = 1;
		seg[i].ct[1] = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

m2 segtree::merger(m2 left, m2 right)
{
	m2 res;
	for(int i=0;i<2;i++)
	res.ct[i] = left.ct[i] + right.ct[i];
	return res;
}

void segtree::update(int i, int s, int d, int qs, int qd)
{
	if(lazy[i])
	{
		for(int j=0;j<lazy[i];j++)
		{
			int t1 = seg[i].ct[0];
			int t2 = seg[i].ct[1];
			seg[i].ct[0] = t2;
			seg[i].ct[1] = t1;
		}
		if(s < d)
		{	
			lazy[2*i] = (lazy[2*i] + lazy[i])%2;
			lazy[2*i+1] = (lazy[2*i+1] + lazy[i])%2;
		}	
		lazy[i] = 0;	
	}	
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		int t1 = seg[i].ct[0];
		int t2 = seg[i].ct[1];
		seg[i].ct[0] = t2;
		seg[i].ct[1] = t1;
		if(s < d)
		{	
			lazy[2*i] = (lazy[2*i] + 1)%2;
			lazy[2*i+1] = (lazy[2*i+1] + 1)%2;
		}		
		return;
	}
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd);
	update(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i])
	{
		for(int j=0;j<lazy[i];j++)
		{
			int t1 = seg[i].ct[0];
			int t2 = seg[i].ct[1];
			seg[i].ct[0] = t2;
			seg[i].ct[1] = t1;
		}
		if(s < d)
		{	
			lazy[2*i] = (lazy[2*i] + lazy[i])%2;
			lazy[2*i+1] = (lazy[2*i+1] + lazy[i])%2;
		}	
		lazy[i] = 0;	
	}	
	if(s > qd || d < qs)
	return 0;
	if(qs <= s && d <= qd)
	return seg[i].ct[1];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return (p1 + p2);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	segtree T;
	T.build(1, 1, n);
	while(q--)
	{
		int x,l,r;
		std::cin>>x>>l>>r;
		if(x)
		std::cout<<T.query(1, 1, n, l, r)<<"\n";
		else T.update(1, 1, n, l, r);
	}
	return 0;	
}