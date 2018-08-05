#include <bits/stdc++.h>
#define MV 20001

typedef long long ll;

ll seg[4*MV];
ll arr[MV],fs;

class segtree
{
	public: void build(ll i, ll s, ll d);
			ll merger(ll left, ll right);
			void update(ll i, ll s, ll d, ll x, ll y);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i] = 1;
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
		arr[s] = y;
		seg[i] = 0;
		return;
	}	
	ll m = (s + d)/2;
	if(x <= seg[2*i])
	update(2*i, s, m, x, y);
	else 
	{
		update(2*i+1, m+1, d, x-seg[2*i], y);
		fs += seg[2*i];
	}	
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	while(T--)
	{
		memset(arr,0,sizeof(arr));
		fs = 0;
		ll n;
		std::cin>>n;
		segtree D;
		D.build(1, 1, n);
		for(ll i=1;i<=n;i++)
		{
			ll ctz = (n - i + 1);
			ll x = fs + i + 1; 
			if(x > ctz)
			{
				x %= ctz;
				if(!x)
				x = ctz;	
			}	
			fs = 0;
			D.update(1, 1, n, x, i);
		}	
		for(ll i=1;i<=n;i++)
		std::cout<<arr[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}