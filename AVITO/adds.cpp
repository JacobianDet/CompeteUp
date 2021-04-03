#include <bits/stdc++.h>
#define MV 10001

int seg[4*MV], lazy[4*MV];

struct qy
{
	int l,r,x;
}Q[MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			void update(int i, int s, int d, int qs, int qd, int x);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = 0;
		lazy[i] = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = 0;
	return;
}

int segtree::merger(int left, int right)
{
	return std::max(left, right);
}

void segtree::update(int i, int s, int d, int qs, int qd, int x)
{
	if(lazy[i])
	{
		seg[i] += lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}	
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		seg[i] += x;
		if(s < d)
		{
			lazy[2*i] += x;
			lazy[2*i+1] += x;
		}	
		return;
	}
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, x);
	update(2*i+1, m+1, d, qs, qd, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	segtree T;
	for(int i=0;i<q;i++)
	std::cin>>Q[i].l>>Q[i].r>>Q[i].x;
	std::set<int> ans;	
	for(int i=0;i<q;i++)
	{
		T.build(1, 1, n);
		for(int j=0;j<q-i;j++)
		{
			T.update(1, 1, n, Q[i+j].l, Q[i+j].r, Q[i+j].x);
			if(seg[1] >= 1 && seg[1] <= n)
			ans.insert(seg[1]);
		}	
	}
	std::cout<<ans.size()<<"\n";
	for(std::set<int>::iterator it = ans.begin();it != ans.end();it++)
	std::cout<<*it<<" ";
	std::cout<<"\n";
	return 0;	
}