#include <bits/stdc++.h>
#define MV 100001

typedef long long ll;

struct bitx
{
	int ctz[21];
}seg[4*MV];

int arr[MV], lazy[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			bitx merger(bitx left, bitx right);
			void update(int i, int s, int d, int qs, int qd, int x);
			bitx query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		for(int j=0;j<21;j++)
		{
			if(arr[s] & (1<<j))
			seg[i].ctz[j]++;
		}	
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

bitx segtree::merger(bitx left, bitx right)
{
	bitx res;
	for(int i=0;i<21;i++)
	res.ctz[i] = left.ctz[i] + right.ctz[i];	
	return res;
}

void segtree::update(int i, int s, int d, int qs, int qd, int x)
{
	if(lazy[i])
	{
		for(int j=0;j<21;j++)
		{
			if(lazy[i] & (1<<j))
			seg[i].ctz[j] = ((d-s+1)-seg[i].ctz[j]);	
		}
		if(s < d)
		{
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}
		lazy[i] = 0;	
	}	
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		for(int j=0;j<21;j++)
		{
			if(x & (1<<j))
			seg[i].ctz[j] = ((d-s+1)-seg[i].ctz[j]);	
		}	
		if(s < d)
		{
			lazy[2*i] ^= x;
			lazy[2*i+1] ^= x;
		}	
		return;
	}
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, x);
	update(2*i+1, m+1, d, qs, qd, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

bitx segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i])
	{
		for(int j=0;j<21;j++)
		{
			if(lazy[i] & (1<<j))
			seg[i].ctz[j] = ((d-s+1)-seg[i].ctz[j]);	
		}
		if(s < d)
		{
			lazy[2*i] ^= lazy[i];
			lazy[2*i+1] ^= lazy[i];
		}
		lazy[i] = 0;	
	}	
	if(s > qd || d < qs)
	{
		bitx res;
		for(int j=0;j<21;j++)
		res.ctz[j] = 0;
		return res;	
	}	
	if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	bitx p1 = query(2*i, s, m, qs, qd);
	bitx p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
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
			int l,r;
			std::cin>>l>>r;
			bitx axe = T.query(1, 1, n, l, r);
			ll ans = 0;
			for(int i=0;i<21;i++)
			{
				if(axe.ctz[i])
				ans += axe.ctz[i]*(1LL<<i);	
			}
			std::cout<<ans<<"\n";	
		}
		else
		{
			int l,r,x;
			std::cin>>l>>r>>x;
			T.update(1, 1, n, l, r, x);
		}	
	}
	return 0;	
}
