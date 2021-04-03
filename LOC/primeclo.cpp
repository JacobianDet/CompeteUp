#include <bits/stdc++.h>
#define MV 100201
#define CHOR 10000001
#define pb push_back

typedef long long ll;

std::vector<ll> px;
std::vector<ll> lpx;
bool isPx[CHOR];

void siever(void)
{
	memset(isPx, 1, sizeof(isPx));
	isPx[0] = 0;
	isPx[1] = 0;
	for(ll p=2;p*p<CHOR;p++)
	{
		if(isPx[p])
		{
			for(ll i=p*p;i<CHOR;i+=p)
			isPx[i] = 0;	
		}
	}
	for(ll p=2;p<CHOR;p++)
	{
		if(isPx[p])
		px.pb(p);	
	}	
	return;
}

void siever2(ll a, ll b)
{
	lpx.resize(b-a+1);
	for(ll i=a;i<=b;i++)
	lpx[i-a] = i;	
	ll j=0;
	for(ll i=0,z=(ll)px.size();i<z;i++)
	{
		if(!(a % px[i]))
		j = a;
		else j = ((a / px[i])+1)*px[i];
		for( ;j<=b;j+=px[i])
		lpx[j-a] /= px[i];	
	}
	ll v = 0;
	for(ll i=a-1;i>=2;i--)
	{
		ll ctr = 0;
		for(ll p=1;p*p<=i;p++)
		{
			if(p*p == i)
			ctr++;
			else if(!(i % p))
			ctr += 2;	
		}
		if(ctr == 2)
		{
			v = i;
			break;
		}	
	}
	if(v >= CHOR)
	px.pb(v);
	for(ll i=a;i<=b;i++)
	{
		if((lpx[i-a] == i) && (i >= CHOR))
		px.pb(i);
	}
	std::sort(px.begin(), px.end());
	return;	
}

ll bs2(ll y)
{
	ll lo = 0;
	ll hi = (ll)px.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo + 1)/2;
		if(px[mid] >= y)
		hi = mid - 1;
		else lo = mid;	
	}	
	return lo;	
}

struct xxs
{
	ll sum;
	bool isP;
}seg[4*MV];

ll arr[MV];

class segtree
{
	public: void build(ll i, ll s, ll d);
			xxs merger(xxs left, xxs right);
			void update(ll i, ll s, ll d, ll qs, ll qd);
			ll query(ll i, ll s, ll d, ll qs, ll qd);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i].sum = arr[s];
		if(arr[s] > 2)
		seg[i].isP = 0;
		else seg[i].isP = 1;
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

xxs segtree::merger(xxs left, xxs right)
{
	xxs res;
	res.sum = left.sum + right.sum;
	res.isP = (left.isP & right.isP);
	return res;
}

void segtree::update(ll i, ll s, ll d, ll qs, ll qd)
{
	if(s > qd || d < qs)
	return;
	if(qs <= s && d <= qd)
	{
		if(seg[i].isP)
		return;
		else if(s == d)
		{
			ll t = bs2(seg[i].sum);
			seg[i].sum -= px[t];	
			if(seg[i].sum > 2)
			seg[i].isP = 0;
			else seg[i].isP = 1;
			return;
		}	
	}
	ll m = (s + d)/2;
	update(2*i, s, m, qs, qd);
	update(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

ll segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	if(s > qd || d < qs)
	return 0;
	if(qs <= s && d <= qd)
	return seg[i].sum;
	ll m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	return (p1 + p2);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll n,q;
	std::cin>>n>>q;
	ll a=1000002001,b=-1000002001;
	for(ll i=1;i<=n;i++)
	std::cin>>arr[i];
	for(ll i=1;i<=n;i++)
	{
		if(a > arr[i])
		a = arr[i];
		if(b < arr[i])
		b = arr[i];	
	}	
	siever2(a, b);
	segtree T;
	T.build(1, 1, n);
	while(q--)
	{
		ll x,l,r;
		std::cin>>x>>l>>r;
		if(--x)
		std::cout<<T.query(1, 1, n, l, r)<<"\n";
		else T.update(1, 1, n, l, r);
	}	
	return 0;	
}