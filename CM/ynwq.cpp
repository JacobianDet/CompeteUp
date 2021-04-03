#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

struct sidx
{
	ll mn, mx;
	int mix;
}seg[400004];

class segtree
{
	public: void build(int i, int s, int d);
			sidx merger(sidx left, sidx right);
			void update(int i, int s, int d, int x, ll val);
			int query(int i, int s, int d, int qs, int qd, ll val);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].mn = arr[s];
		seg[i].mx = arr[s];
		seg[i].mix = s;
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
	res.mn = std::min(left.mn, right.mn);
	res.mx = std::max(left.mx, right.mx);
	res.mix = std::min(left.mix, right.mix);
	return res;
}

void segtree::update(int i, int s, int d, int x, ll val)
{
	if(s == d)
	{
		arr[s] = val;
		seg[i].mn = arr[s];
		seg[i].mx = arr[s];
		seg[i].mix = s;
 		return;
	}	
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, val);
	else update(2*i+1, m+1, d, x, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::query(int i, int s, int d, int qs, int qd, ll val)
{
	if(qs > d || qd < s)
	return 100001;
	if(qs <= s && d <= qd)
	{
		if(seg[i].mn > val)
		return seg[i].mix;
		else if(seg[i].mx <= val)
		return 100001;	
		else
		{
			int m = (s + d)/2;
			int p1 = 100001, p2 = 100001;
			if(s < d)
			{	
				if(seg[2*i].mx > val)
				p1 = query(2*i, s, m, qs, qd, val);
				else if(seg[2*i+1].mx > val)
				p2 = query(2*i+1, m+1, d, qs, qd, val);	
			}
			return std::min(p1, p2);
		}
	}
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd, val);
	int p2 = query(2*i+1, m+1, d, qs, qd, val);
	return std::min(p1, p2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	segtree T;
	T.build(1, 1, n);
	while(q--)
	{
		int x;
		std::cin>>x;
		if(--x)
		{
			int l, r;
			ll v;
			std::cin>>l>>r>>v;
			int zx = T.query(1, 1, n, l, r, v);
			if(zx == 100001)
			std::cout<<"-1\n";
			else std::cout<<zx<<"\n";
		}
		else
		{
			int id;
			ll v;
			std::cin>>id>>v;
			T.update(1, 1, n, id, v);
		}
	}
	return 0;	
}