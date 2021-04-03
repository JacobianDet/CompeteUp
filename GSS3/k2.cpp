#include <bits/stdc++.h>
#define ll long long
#define MV 1000000
#define NG -1000000

ll a[MV + 1];

struct posb
{
	ll sx,px,mv,tot;
};

posb seg[4*MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			posb merger(posb left, posb right);
			posb query(ll i, ll s, ll d, ll qs, ll qd);
			void update(ll i, ll s, ll d, ll x, ll y);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i] = {a[s], a[s], a[s], a[s]};
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

posb segtree::merger(posb left, posb right)
{
	posb mval;
	mval.sx = std::max(right.sx, right.tot + left.sx);
	mval.px = std::max(left.px, left.tot + right.px);
	mval.mv = std::max(left.mv, std::max(right.mv, std::max(left.sx + right.px, std::max(mval.px, mval.sx))));
	mval.tot = left.tot + right.tot;
	return mval;
}	

posb segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	if(s > qd || d < qs)
	return {NG, NG, NG, NG};
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	posb p1 = query(2*i, s, m, qs, qd);
	posb p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);
}

void segtree::update(ll i, ll s, ll d, ll x, ll y)
{
	if(s == d)
	{	
		seg[i] = {y, y, y, y};
		return;
	}	
	if(x > d || x < s)
	return;
	ll m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, y);
	else update(2*i+1, m+1, d, x, y);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	std::cin>>a[i];
	segtree T;
	T.build(1, 1, n);
	ll q;
	std::cin>>q;
	for(ll i=0;i<q;i++)
	{
		ll t,x,y;
		std::cin>>t>>x>>y;
		if(!t)
		T.update(1, 1, n, x, y);
		else std::cout<<T.query(1, 1, n, x, y).mv<<"\n";
	}	
	return 0;
}