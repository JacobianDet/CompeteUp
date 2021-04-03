#include <bits/stdc++.h>
#define CHOR 1000001
#define MV 100001
#define pb push_back

typedef long long ll;

ll lo[CHOR];

void siever(void)
{
	for(ll i=1;i<CHOR;i++)
	lo[i] = i;
	for(ll i=2;i<CHOR;i++)
	{
		if(lo[i] == i)
		{
			for(ll j=i*i;j<CHOR;j+=i)
			{
				if(lo[j] == j)
				lo[j] = i;	
			}	
		}	
	}
	return;	
}

ll arr[MV];

struct dualx
{
	std::vector<ll> pr;
	std::vector<ll> cnt;
}seg[4*MV];

ll bs1(ll i, ll x)
{
	ll lo = 0;
	ll hi = (ll)seg[i].pr.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo)/2;
		if(seg[i].pr[mid] < x)
		lo = mid + 1;
		else hi = mid;	
	}	
	if(seg[i].pr[lo] >= x)
	return lo;
	else return -1;	
}

ll bs2(ll i, ll y)
{
	ll lo = 0;
	ll hi = (ll)seg[i].pr.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo + 1)/2;
		if(seg[i].pr[mid] > y)
		hi = mid - 1;
		else lo = mid;	
	}	
	if(seg[i].pr[lo] <= y)
	return lo;
	else return -1;	
}

class segtree
{
	public: void build(ll i, ll s, ll d);
			dualx merger(dualx& left, dualx& right);
			ll query(ll i, ll s, ll d, ll qs, ll qd, ll x, ll y);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		ll z = arr[s];
		while(z != 1)
		{
			ll p = lo[z];
			ll ct = 0;
			while(p == lo[z])
			{
				ct++;
				z /= p;
			}	
			seg[i].pr.pb(p);
			seg[i].cnt.pb(ct);
		}
		return;	
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
}

dualx segtree::merger(dualx& left, dualx& right)
{
	dualx res;
	ll n1 = left.pr.size();
	ll n2 = right.pr.size();
	ll i=0, j=0;
	while(i != n1 && j != n2)
	{
		if(left.pr[i] < right.pr[j])
		{
			res.pr.pb(left.pr[i]);
			res.cnt.pb(left.cnt[i]);
			i++;
		}	
		else if(right.pr[j] < left.pr[i])
		{
			res.pr.pb(right.pr[j]);
			res.cnt.pb(right.cnt[j]);
			j++;
		}	
		else
		{
			res.pr.pb(left.pr[i]);
			res.cnt.pb(left.cnt[i] + right.cnt[j]);
			i++;
			j++;
		}	
	}
	if(i != n1)
	{
		for( ;i<n1;i++)
		{
			res.pr.pb(left.pr[i]);
			res.cnt.pb(left.cnt[i]);
		}	
	}	
	if(j != n2)
	{
		for( ;j<n2;j++)
		{
			res.pr.pb(right.pr[j]);
			res.cnt.pb(right.cnt[j]);
		}	
	}
	return res;	
}

ll segtree::query(ll i, ll s, ll d, ll qs, ll qd, ll x, ll y)
{
	if(s > qd || d < qs)
	return 0;
	if(qs <= s && d <= qd)
	{
		ll l = bs1(i, x);
		ll r = bs2(i, y);
		if(l == -1 || r == -1 || seg[i].pr[l] > y || seg[i].pr[r] < x)
		return 0;
		else
		{
			ll ctr = 0;
			for(ll j=l;j<=r;j++)
			ctr += seg[i].cnt[j];
			return ctr;
		}	
	}
	ll m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd, x, y);
	ll p2 = query(2*i+1, m+1, d, qs, qd, x, y);
	return p1 + p2;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	std::cin>>arr[i];
	segtree T;
	T.build(1, 1, n);
	ll q;
	std::cin>>q;
	while(q--)
	{
		ll l,r,x,y;
		std::cin>>l>>r>>x>>y;
		std::cout<<T.query(1, 1, n, l, r, x, y)<<"\n";
	}	
	return 0;
}

