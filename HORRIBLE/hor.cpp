#include <bits/stdc++.h>
#define MV 100001

typedef long long ll;

ll seg[4*MV], lazy[4*MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			ll merger(ll left, ll right);
			void update(ll i, ll s, ll d, ll qs, ll qd, ll v);
			ll query(ll i, ll s, ll d, ll qs, ll qd);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i] = 0;
		lazy[i] = 0;
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = merger(lazy[2*i], lazy[2*i+1]);
	return;
}

ll segtree::merger(ll left, ll right)
{
	return (left + right);
}

void segtree::update(ll i, ll s, ll d, ll qs, ll qd, ll v)
{
	if(lazy[i])
	{
		seg[i] += (d-s+1)*lazy[i];
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
		seg[i] += (d-s+1)*v;
		if(s < d)
		{
			lazy[2*i] += v;
			lazy[2*i+1] += v;
		}	
		return;
	}	
	ll m = (s + d)/2;
	update(2*i, s, m, qs, qd, v);
	update(2*i+1, m+1, d, qs, qd, v);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	if(lazy[i])
	{
		seg[i] += (d-s+1)*lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}	
	if(s > qd || d < qs)
	return 0;
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return (p1 + p2);
}

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n,q;
		std::cin>>n>>q;
		segtree D;
		D.build(1, 1, n);
		while(q--)
		{
			ll x;
			std::cin>>x;
			if(x)
			{
				ll l,r;
				std::cin>>l>>r;
				std::cout<<D.query(1, 1, n, l, r)<<"\n";
			}	
			else
			{
				ll l,r,v;
				std::cin>>l>>r>>v;
				D.update(1, 1, n, l, r, v);
			}	
		}	
	}
	return 0;	
}