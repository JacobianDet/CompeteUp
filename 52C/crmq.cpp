#include <bits/stdc++.h>
#define MV 200001

typedef long long ll;

ll seg[4*MV], lazy[4*MV], arr[MV];

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
		seg[i] = arr[s];
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
	return std::min(left, right);
}

void segtree::update(ll i, ll s, ll d, ll qs, ll qd, ll v)
{
	if(lazy[i] != 0)
	{
		seg[i] += lazy[i];
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
		seg[i] += v;
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
	if(lazy[i] != 0)
	{
		seg[i] += lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}	
	if(s > qd || d < qs)
	return 100000000000000000;
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	std::cin>>arr[i];
	segtree T;
	T.build(1, 1, n);
	ll q;
	std::cin>>q;
	std::cin.ignore();
	while(q--)
	{
		std::string s;
		std::getline(std::cin, s);
		ll inp[3], ctr = 0;
		bool mark = 0;
		memset(inp, 0, sizeof(inp));
		for(ll i=0,j=(ll)s.size();i<j;i++)
		{
			if(s[i] == ' ')
			ctr++;
			else
			{
				if(s[i] == '-')
				mark = 1;
				else inp[ctr] = (inp[ctr] * 10) + (s[i] - '0'); 	
			}		
		}	
		if(mark)
		inp[2] *= -1;
		/*for(ll i=0;i<3;i++)
		std::cout<<inp[i]<<"A\n";*/	
		if(ctr == 1)
		{
			ll l = inp[0] + 1;
			ll r = inp[1] + 1;			
			if(l <= r)
			std::cout<<T.query(1, 1, n, l, r)<<"\n";
			else std::cout<<std::min(T.query(1, 1, n, l, n), T.query(1, 1, n, 1, r))<<"\n";	
		}
		else
		{
			ll l = inp[0] + 1;
			ll r = inp[1] + 1;
			ll v = inp[2];
			if(l <= r)
			T.update(1, 1, n, l, r, v);
			else 
			{
				T.update(1, 1, n, l, n, v);
				T.update(1, 1, n, 1, r, v);
			}	
		}	
	}
	return 0;	
}