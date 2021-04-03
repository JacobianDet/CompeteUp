#include <bits/stdc++.h>
#define MV 30001

typedef long long ll;

struct brk 
{
	ll lt,rt;
	bool isb;
}seg[4*MV];

std::string brck;

class segtree
{
	public: void build(ll i, ll s, ll d);
			void update(ll i, ll s, ll d, ll k);
			brk merger(brk left, brk right);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i].isb = 0;
		if(brck[s-1] == '(')
		{
			seg[i].lt = 1;
			seg[i].rt = 0;
		}	
		else
		{
			seg[i].lt = 0;
			seg[i].rt = -1;
		}	
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

brk segtree::merger(brk left, brk right)
{
	brk res;
	if(left.isb && right.isb)
	{
		res.lt = 0;
		res.rt = 0;
		res.isb = 1;
	}	
	else if(!left.isb && !right.isb)
	{
		ll x = left.lt + right.rt;
		if(x > 0)
		{
			res.lt = x + right.lt;
			res.rt = left.rt;
		}	
		else 
		{
			res.lt = right.lt;
			res.rt = x + left.rt;
		}	
		if((res.lt != 0) || (res.rt != 0))
		res.isb = 0;
		else res.isb = 1;	
	}	
	else 
	{
		ll x = left.lt + right.rt;
		if(x > 0)
		{
			res.lt = x + right.lt;
			res.rt = left.rt;
		}	
		else 
		{
			res.lt = right.lt;
			res.rt = x + left.rt;
		}	
		res.isb = 0;
	}	
	return res;
}

void segtree::update(ll i, ll s, ll d, ll k)
{
	if(s == d)
	{
		seg[i].isb = 0;
		if(brck[k-1] == '(')
		{	
			brck[k-1] = ')';
			seg[i].lt = 0;
			seg[i].rt = -1;

		}	
		else 
		{
			brck[k-1] = '(';
			seg[i].lt = 1;
			seg[i].rt = 0;
		}	
		return;
	}	
	if(k > d || k < s)
	return;
	ll m = (s + d)/2;
	if(k <= m)
	update(2*i, s, m, k);
	else update(2*i+1, m+1, d, k);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for(ll t=1;t<=10;t++)
	{	
		ll n;
		std::cin>>n;
		std::cin>>brck;
		segtree D;
		D.build(1, 1, n);
		ll q;
		std::cin>>q;
		std::cout<<"Test "<<t<<":\n";
		while(q--)
		{
			ll k;
			std::cin>>k;
			if(!k)
			{
				if(seg[1].isb)
				std::cout<<"YES\n";
				else std::cout<<"NO\n";	
			}	
			else D.update(1, 1, n, k);
		}
	}		
	return 0;
}