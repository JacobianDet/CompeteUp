#include <bits/stdc++.h>
#define MV 100001
#define CHOR 1000000000000

typedef long long ll;

struct ldkb
{
	ll pref,suff,mval,tot;
}seg[4*MV];

ll arr[MV];
ll n;

class segtree
{
	public: void build(ll i, ll s, ll d);
			ldkb merger(ldkb left, ldkb right);
			ldkb query(ll i, ll s, ll d, ll qs, ll qd);
};

void segtree::build(ll i, ll s, ll d)	
{
	if(s == d)
	{	
		seg[i] = {arr[s], arr[s], arr[s], arr[s]};
		return;
	}
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

ldkb segtree::merger(ldkb left, ldkb right)
{
	ldkb ans;
	ans.pref = std::max(left.pref, left.tot + right.pref);
	ans.suff = std::max(right.suff, left.suff + right.tot);
	ans.mval = std::max(std::max(left.mval, right.mval), std::max(std::max(ans.pref, ans.suff), right.pref + left.suff));
	ans.tot = left.tot + right.tot;
	return ans;
}

ldkb segtree::query(ll i, ll s, ll d, ll qs, ll qd)
{
	if(qd < s || qs > d)
	return {-CHOR, -CHOR, -CHOR, 0};
	if(qs <= s && d <= qd)
	return seg[i];
	ll m = (s + d)/2;
	ldkb p1 = query(2*i, s, m, qs, qd);
	ldkb p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(arr,0,sizeof(arr));
		std::cin>>n;
		for(ll i=1;i<=n;i++)
		std::cin>>arr[i];
		segtree D;
		D.build(1, 1, n);
		ll q;
		std::cin>>q;
		while(q--)
		{
			ll x1,y1,x2,y2;
			std::cin>>x1>>y1>>x2>>y2;
			if(y1 < x2)
			{
				ll a = D.query(1, 1, n, x1, y1).suff;
				ll b = D.query(1, 1, n, y1, x2).tot - arr[x2] - arr[y1];
				ll c = D.query(1, 1, n, x2, y2).pref;
				std::cout<<a+b+c<<"\n";
			}	
			else
			{
				ll a = D.query(1, 1, n, x2, y1).mval;
				ll b = D.query(1, 1, n, x1, x2).suff + D.query(1, 1, n, x2, y2).pref - arr[x2];
				ll c = D.query(1, 1, n, x1, y1).suff + D.query(1, 1, n, y1, y2).pref - arr[y1];
				std::cout<<std::max(a, std::max(b, c))<<"\n";
			}	
		}	
	}
	return 0;	
}