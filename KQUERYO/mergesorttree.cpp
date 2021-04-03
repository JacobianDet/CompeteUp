#include <bits/stdc++.h>
#define MV 30001
#define pb push_back

typedef long long ll;

ll arr[MV];
std::vector<ll> seg[4*MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			std::vector<ll> merger(std::vector<ll>& left, std::vector<ll>& right);
			ll query(ll i, ll s, ll d, ll qs, ll qd, ll k);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i].pb(arr[s]);
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

std::vector<ll> segtree::merger(std::vector<ll>& left, std::vector<ll>& right)
{
	std::vector<ll> res;
	ll n1 = left.size();
	ll n2 = right.size();
	ll i=0,j=0;
	while(i != n1 && j != n2)
	{
		if(left[i] < right[j])
		{	
			res.pb(left[i]);
			i++;
		}	
		else if(right[j] < left[i]) 	
		{
			res.pb(right[j]);
			j++;
		}	
		else
		{
			res.pb(left[i]);
			res.pb(right[j]);
			i++;
			j++;
		}	
	}	
	if(i != n1)
	{
		for( ;i<n1;i++)
		res.pb(left[i]);	
	}	
	else if(j != n2)
	{
		for( ;j<n2;j++)
		res.pb(right[j]);	
	}	
	return res;
}

ll segtree::query(ll i, ll s, ll d, ll qs, ll qd, ll k)
{
	if(s > qd || d < qs)
	return 0;
	if(qs <= s && d <= qd)
	return seg[i].size() - (std::upper_bound(seg[i].begin(), seg[i].end(), k) - seg[i].begin());
	ll m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd, k);
	ll p2 = query(2*i+1, m+1, d, qs, qd, k);
	return p1 + p2;		
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
	ll ans = 0;
	while(q--)
	{
		ll l,r,k;
		std::cin>>l>>r>>k;
		l = l ^ ans;
		r = r ^ ans;
		k = k ^ ans;	
		if(l < 1)
		l = 1;
		if(r > n)
		r = n;
		if(l > r)
		ans = 0;	
		else ans = T.query(1, 1, n, l, r, k);
		std::cout<<ans<<"\n";
	}
	return 0;
}