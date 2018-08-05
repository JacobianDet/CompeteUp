#include <bits/stdc++.h>
#define ll long long
#define MV 1000000

ll a[MV + 1];

struct sqm
{
	ll val;
	bool all_1;	
}seg[4*MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			sqm merger(sqm left, sqm right);
			sqm query(ll i, ll s, ll d, ll qs, ll qd);
			void update(ll i, ll s, ll d, ll x, ll y);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i].val = a[s];
		if(a[s] == 1)
		seg[i].all_1 = 1;
		else seg[i].all_1 = 0;
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

sqm segtree::merger(sqm left, sqm right)
{
	sqm res;
	res.val = left.val + right.val;
	res.all_1 = left.all_1 & right.all_1;
	return res;
}	

sqm segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	if(s > qd || d < qs)
	return {0, 0};
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	sqm p1 = query(2*i, s, m, qs, qd);
	sqm p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);
}

void segtree::update(ll i, ll s, ll d, ll qs, ll qd)
{
	if(qs <= s && d <= qd)
	{
		if(seg[i].all_1)
		return;
		else if(s == d)
		{
			seg[i].val = (ll)sqrt(seg[i].val);
			if(seg[i].val == 1)
			seg[i].all_1 = 1;
			else seg[i].all_1 = 0;
			return; 
		}	
	}	
	else if(s > qd || d < qs)
	return;
	ll m = (s + d)/2;
	update(2*i, s, m, qs, qd);
	update(2*i+1, m+1, d, qs, qd);	
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int main(void)
{
	ll n;
	for(ll w = 1; scanf("%lld", &n) == 1; w++)
	{	
		for(ll i=1;i<=n;i++)
		scanf("%lld", a + i);
		segtree T;
		T.build(1, 1, n);
		ll q;
		scanf("%lld", &q);
		printf("Case #%lld:\n", w);
		for(ll i=0;i<q;i++)
		{
			ll t,x,y;
			scanf("%lld %lld %lld", &t, &x, &y);
			ll r = std::max(x, y);
			ll l = 0;
			if(x == r)
			l = y;
			else l = x;
			if(!t)
			T.update(1, 1, n, l, r);
			else printf("%lld\n", T.query(1, 1, n, l, r).val);	
		}	
		printf("\n");
	}		
	return 0;
}