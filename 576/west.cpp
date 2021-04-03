#include <bits/stdc++.h>
#define mp std::make_pair

int arr[200001], lazy[800004];
std::pair<int, int> seg[800004];

class segtree
{
	public: void build(int i, int s, int d);
			std::pair<int, int> merger(std::pair<int, int> left, std::pair<int, int> right);
			void update1(int i, int s, int d, int p, int x);
			void update2(int i, int s, int d, int x);
			std::pair<int, int> query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = mp(arr[s], arr[s]);
		lazy[i] = -1;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	lazy[i] = -1;
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

std::pair<int, int> segtree::merger(std::pair<int, int> left, std::pair<int, int> right)
{
	return mp(std::min(left.first, right.first), std::max(left.second, right.second));
}

std::pair<int, int> segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != -1)
	{
		seg[i] = mp(lazy[i], lazy[i]);
		if(s < d)
		{
			lazy[2*i] = std::max(lazy[2*i], lazy[i]);
			lazy[2*i+1] = std::max(lazy[2*i+1], lazy[i]);
		}	
		lazy[i] = -1;
	}
	if(s > qd || d < qs)
	return mp(10000000001, -1);
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	std::pair<int, int> p1 = query(2*i, s, m, qs, qd);
	std::pair<int, int> p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

void segtree::update1(int i, int s, int d, int p, int x)
{
	if(lazy[i] != -1)
	{
		seg[i] = mp(lazy[i], lazy[i]);
		if(s < d)
		{
			lazy[2*i] = std::max(lazy[2*i], lazy[i]);
			lazy[2*i+1] = std::max(lazy[2*i+1], lazy[i]);
		}	
		lazy[i] = -1;
	}
	if(s == d)
	{
		seg[i] = mp(x, x);
		return;
	}	
	int m = (s + d)/2;
	if(p <= m)
	update1(2*i, s, m, p, x);
	else update1(2*i+1, m+1, d, p, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

void segtree::update2(int i, int s, int d, int x)
{
	if(lazy[i] != -1)
	{
		seg[i] = mp(lazy[i], lazy[i]);
		if(s < d)
		{
			lazy[2*i] = std::max(lazy[2*i], lazy[i]);
			lazy[2*i+1] = std::max(lazy[2*i+1], lazy[i]);
		}	
		lazy[i] = -1;
	}
	if(seg[i].first > x)
	return;
	else if(seg[i].second <= x)
	{
		seg[i] = mp(x, x);
		if(s < d)
		{
			lazy[2*i] = std::max(lazy[2*i], x);
			lazy[2*i+1] = std::max(lazy[2*i+1], x);
		}	
		lazy[i] = -1;
		return;
	}	
	int m = (s + d)/2;
	update2(2*i, s, m, x);
	update2(2*i+1, m+1, d, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	std::cin>>q;
	segtree T;
	T.build(1, 1, n);
	while(q--)
	{
		int t;
		std::cin>>t;
		if(--t)
		{
			int x;
			std::cin>>x;
			T.update2(1, 1, n, x);
		}
		else
		{
			int p,x;
			std::cin>>p>>x;
			T.update1(1, 1, n, p, x);
		}
	}
	for(int i=1;i<=n;i++)
	std::cout<<T.query(1, 1, n, i, i).first<<" ";
	std::cout<<"\n";
	return 0;	
}