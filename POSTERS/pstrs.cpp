#include <bits/stdc++.h>
#define ll long long
#define MV 10000001

ll lazy[4*MV];
std::set<ll> ctr;

class segtree
{
	public: void build(ll i, ll s, ll d);
			void flazy(ll i, ll s, ll d);
			void ctrs(ll i, ll s, ll d);
			void update(ll i, ll s, ll d, ll qs, ll qd, ll v);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		lazy[i] = 0;
		return;
	}	
	ll m = (s+d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	lazy[i] = 0;
	return;
}

void segtree::flazy(ll i, ll s, ll d)
{
	if(lazy[i])
	{
		if(s < d)
		{
			lazy[2*i] = lazy[i];
			lazy[2*i+1] = lazy[i];
			lazy[i] = 0;
		}	
	}	
	return;
}

void segtree::update(ll i, ll s, ll d, ll qs, ll qd, ll v)
{
	flazy(i, s, d);
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		lazy[i] = v;
		flazy(i, s, d);
		return;
	}	
	ll m = (s+d)/2;
	update(2*i, s, m, qs, qd, v);
	update(2*i+1, m+1, d, qs, qd, v);
	return;
}

void segtree::ctrs(ll i, ll s, ll d)
{
	if(lazy[i])
	{
		ctr.insert(lazy[i]);
		return;
	}	
	if(s == d)
	return;
	ll m = (s+d)/2;
	ctrs(2*i, s, m);
	ctrs(2*i+1, m+1, d);
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll t;
	std::cin>>t;
	segtree T;
	while(t--)
	{
		T.build(1, 1, MV-1);
		ll n;
		std::cin>>n;
		for(ll i=1;i<=n;i++)
		{
			ll l,r;
			std::cin>>l>>r;
			T.update(1, 1, MV-1, l, r, i);
		}
		T.ctrs(1, 1, MV-1);
		std::cout<<ctr.size()<<"\n";
		ctr.clear();
	}	
	return 0;
}