#include <bits/stdc++.h>
#define MV 200001

typedef long long ll;

std::unordered_map<ll, ll> cord;
std::unordered_map<ll, ll> copp;

struct qy
{
	char ch;
	ll val;
};

ll seg[4*MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			ll merger(ll left, ll right);
			void update(ll i, ll s, ll d, ll x, ll y);
			ll kqry(ll i, ll s, ll d, ll k);
			ll cqry(ll i, ll s, ll d, ll x);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i] = 0;
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::merger(ll left, ll right)
{
	return (left + right);
}

void segtree::update(ll i, ll s, ll d, ll x, ll y)
{
	if(s == d)
	{
		if(!y)
		seg[i] = 0;
		else seg[i] = 1;
		return;
	}	
	ll m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, y);
	else update(2*i+1, m+1, d, x, y);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

ll segtree::kqry(ll i, ll s, ll d, ll k)
{
	if(s == d)
	return s;
	ll m = (s + d)/2;
	if(k <= seg[2*i])
	return kqry(2*i, s, m, k);
	else return kqry(2*i+1, m+1, d, k-seg[2*i]);
}

ll segtree::cqry(ll i, ll s, ll d, ll x)
{
	if(s == d)
	return 0;
	ll m = (s + d)/2;
	if(x <= m)
	return cqry(2*i, s, m, x);
	else return seg[2*i] + cqry(2*i+1, m+1, d, x);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll q;
	std::cin>>q;
	qy Q[q];
	ll n = 0;
	std::set<ll> Z;
	for (ll i=0;i<q;i++)
	{
		std::cin>>Q[i].ch>>Q[i].val;
		if(Q[i].ch != 'K')
		Z.insert(Q[i].val);
	}
	for(std::set<ll>::iterator it=Z.begin();it != Z.end();it++)
	{
		n++;
		cord[n] = *it;
		copp[*it] = n;
	}
	segtree T;
	T.build(1, 1, n);
	for(ll i=0;i<q;i++)
	{
		if(Q[i].ch == 'I')
		T.update(1, 1, n, copp[Q[i].val], copp[Q[i].val]);
		else if(Q[i].ch == 'D')
		T.update(1, 1, n, copp[Q[i].val], 0);
		else if(Q[i].ch == 'K')
		{	
			if(seg[1] < Q[i].val)
			std::cout<<"invalid\n";
			else std::cout<<cord[T.kqry(1, 1, n, Q[i].val)]<<"\n";
		}
		else std::cout<<T.cqry(1, 1, n, copp[Q[i].val])<<"\n";	
	}	
	return 0;
}