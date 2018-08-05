#include <bits/stdc++.h>
#define MV 100001

typedef long long ll;

struct sqr
{
	ll sqs,sum;
}seg[4*MV];

struct lz
{
	ll val,tm;
}lazy0[4*MV], lazy1[4*MV];

ll arr[MV];
ll tz;

class segtree
{
	public: void build(ll i, ll s, ll d);
			sqr merger(sqr left, sqr right);
			void lzupd(ll i, ll s, ll d);
			void upd0(ll i, ll s, ll d, ll qs, ll qd, ll v);
			void upd1(ll i, ll s, ll d, ll qs, ll qd, ll v);
			ll query(ll i, ll s, ll d, ll qs, ll qd);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i].sqs = arr[s]*arr[s];
		seg[i].sum = arr[s];
		lazy0[i].val = 0;
		lazy0[i].tm = 0;
		lazy1[i].val = 0;
		lazy1[i].tm = 0;
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy0[i].val = 0;
	lazy0[i].tm = 0;
	lazy1[i].val = 0;
	lazy1[i].tm = 0;
	return;
}

sqr segtree::merger(sqr left, sqr right)
{
	sqr res;
	res.sqs = left.sqs + right.sqs;
	res.sum = left.sum + right.sum;
	return res;
}

void segtree::lzupd(ll i, ll s, ll d)
{
	if(lazy0[i].tm || lazy1[i].tm)
	{
		if(lazy0[i].tm && lazy1[i].tm)
		{
			if(lazy0[i].tm < lazy1[i].tm)
			{
				seg[i].sqs = (d-s+1)*lazy0[i].val*lazy0[i].val;
				seg[i].sum = (d-s+1)*lazy0[i].val;
				seg[i].sqs += (2*seg[i].sum*lazy1[i].val + (d-s+1)*lazy1[i].val*lazy1[i].val);
				seg[i].sum += (d-s+1)*lazy1[i].val;
				if(s < d)
				{
					lazy0[2*i].val = lazy0[i].val;
					lazy0[2*i].tm = lazy0[i].tm;
					lazy1[2*i].val = lazy1[i].val;
					lazy1[2*i].tm = lazy1[i].tm;
					lazy0[2*i+1].val = lazy0[i].val;
					lazy0[2*i+1].tm = lazy0[i].tm;
					lazy1[2*i+1].val = lazy1[i].val;
					lazy1[2*i+1].tm = lazy1[i].tm;
				}	
			}	
			else
			{
				seg[i].sqs = (d-s+1)*lazy0[i].val*lazy0[i].val;
				seg[i].sum = (d-s+1)*lazy0[i].val;
				if(s < d)
				{
					lazy0[2*i].val = lazy0[i].val;
					lazy0[2*i].tm = lazy0[i].tm;
					lazy0[2*i+1].val = lazy0[i].val;
					lazy0[2*i+1].tm = lazy0[i].tm;
				}	
			}	
		}
		else if(lazy0[i].tm)
		{
			seg[i].sqs = (d-s+1)*lazy0[i].val*lazy0[i].val;
			seg[i].sum = (d-s+1)*lazy0[i].val;
			if(s < d)
			{
					lazy0[2*i].val = lazy0[i].val;
					lazy0[2*i].tm = lazy0[i].tm;
					lazy0[2*i+1].val = lazy0[i].val;
					lazy0[2*i+1].tm = lazy0[i].tm;
			}	
		}	
		else
		{
			seg[i].sqs += (2*seg[i].sum*lazy1[i].val + (d-s+1)*lazy1[i].val*lazy1[i].val);
			seg[i].sum += (d-s+1)*lazy1[i].val;
			if(s < d)
			{
				if(lazy0[2*i].tm && lazy1[2*i].tm)
				{
					if(lazy0[2*i].tm < lazy1[2*i].tm)
					lazy1[2*i].val += lazy1[i].val;	
					else lazy1[2*i].val = lazy1[i].val;	
				}
				else lazy1[2*i].val += lazy1[i].val;
				lazy1[2*i].val = lazy1[i].tm;	
				if(lazy0[2*i+1].tm && lazy1[2*i+1].tm)
				{
					if(lazy0[2*i+1].tm < lazy1[2*i+1].tm)
					lazy1[2*i+1].val += lazy1[i].val;	
					else lazy1[2*i+1].val = lazy1[i].val;	
				}
				else lazy1[2*i+1].val += lazy1[i].val;
				lazy1[2*i+1].val = lazy1[i].tm;	

			}	
		}
		lazy0[i].val = 0;
		lazy0[i].tm = 0;
		lazy1[i].val = 0;
		lazy1[i].tm = 0;
	}
	return;
}

void segtree::upd0(ll i, ll s, ll d, ll qs, ll qd, ll v)
{
	lzupd(i, s, d);
	if(d < qs || s > qd)
	return;
	if(qs <= s && d <= qd)
	{
		seg[i].sqs = (d-s+1)*v*v;
		seg[i].sum = (d-s+1)*v;
		if(s < d)
		{
			lazy0[2*i].val = v;
			lazy0[2*i].tm = tz;
			lazy0[2*i+1].val = v;
			lazy0[2*i+1].tm = tz;
			lazy1[2*i].val = 0;
			lazy1[2*i].tm = 0;
			lazy1[2*i+1].val = 0;
			lazy1[2*i+1].tm = 0;

		}
		return;	
	}	
	ll m = (s + d)/2;
	upd0(2*i, s, m, qs, qd, v);
	upd0(2*i+1, m+1, d, qs, qd, v);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

void segtree::upd1(ll i, ll s, ll d, ll qs, ll qd, ll v)
{
	lzupd(i, s, d);
	if(d < qs || s > qd)
	return;
	if(qs <= s && d <= qd)
	{
		seg[i].sqs += (2*seg[i].sum*v + (d-s+1)*v*v);
		seg[i].sum += (d-s+1)*v;
		if(s < d)
		{
			if(lazy0[2*i].tm && lazy1[2*i].tm)
			{
				if(lazy0[2*i].tm < lazy1[2*i].tm)
				lazy1[2*i].val += v;	
				else lazy1[2*i].val = v;	
			}
			else lazy1[2*i].val += v;
			lazy1[2*i].val = tz;	
			if(lazy0[2*i+1].tm && lazy1[2*i+1].tm)
			{
				if(lazy0[2*i+1].tm < lazy1[2*i+1].tm)
				lazy1[2*i+1].val += v;	
				else lazy1[2*i+1].val = v;	
			}
			else lazy1[2*i+1].val += v;
			lazy1[2*i+1].val = tz;		
		}
		return;	
	}	
	ll m = (s + d)/2;
	upd1(2*i, s, m, qs, qd, v);
	upd1(2*i+1, m+1, d, qs, qd, v);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	lzupd(i, s, d);
	if(d < qs || s > qd)
	return 0;
	if(qs <= s && d <= qd)
	return seg[i].sqs;
	ll m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return (p1 + p2);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	for(ll t=1;t<=T;t++)
	{
		tz = 0;
		ll n,q;
		std::cin>>n>>q;
		for(ll i=1;i<=n;i++)
		std::cin>>arr[i];
		segtree D;
		D.build(1, 1, n);
		std::cout<<"Case "<<t<<":\n";
		while(q--)
		{
			ll x;
			std::cin>>x;
			tz++;
			if(x == 0)
			{
				ll l,r,v;
				std::cin>>l>>r>>v;
				D.upd0(1, 1, n, l, r, v);
			}	
			else if(x == 1)
			{
				ll l,r,v;
				std::cin>>l>>r>>v;
				D.upd1(1, 1, n, l, r, v);
			}	
			else
			{
				ll l,r;
				std::cin>>l>>r;
				std::cout<<D.query(1, 1, n, l, r)<<"\n";
			}	
		}	
	}
	return 0;	
}