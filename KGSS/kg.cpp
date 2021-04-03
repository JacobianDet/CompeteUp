#include <bits/stdc++.h>
#define mp std::make_pair
#define ll long long
#define MV 100000

ll a[MV+1];
std::pair<ll, ll> seg[4*MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			std::pair<ll, ll> merger(std::pair<ll, ll> left, std::pair<ll, ll> right);
			std::pair<ll, ll> query(ll i, ll s, ll d, ll qs, ll qd);
			void update(ll i, ll s, ll d, ll x, ll y);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i] = mp(a[s], 0);
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

std::pair<ll, ll> segtree::merger(std::pair<ll, ll> left, std::pair<ll, ll> right)
{
	ll max1 = std::max(left.first, right.first);
	ll max2 = 0;
	if(max1 == left.first)
	max2 = std::max(right.first, left.second);
	else max2 = std::max(left.first, right.second);
	return mp(max1, max2);
}

std::pair<ll, ll> segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	if(s > qd || d < qs)
	return mp(0, 0);
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	std::pair<ll, ll> p1 = query(2*i, s, m, qs, qd);
	std::pair<ll, ll> p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);
}

void segtree::update(ll i, ll s, ll d, ll x, ll y)
{
	if(s == d)
	{	
		seg[i] = mp(y, 0);
		return;
	}
	if(x > d || x < s)
	return;
	ll m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, y);
	else update(2*i + 1, m+1, d, x, y);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return; 		
}

int main(void)
{
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
		char ch;
		ll x,y;
		std::cin>>ch>>x>>y;
		if(ch == 'U')
		T.update(1, 1, n, x, y);
		else if(ch == 'Q')
		{
			std::pair<ll, ll> p = T.query(1, 1, n, x, y);
			std::cout<<p.first + p.second<<"\n";
		}
	}	
	return 0;
}