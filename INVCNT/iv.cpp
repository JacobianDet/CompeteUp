#include <bits/stdc++.h>
#define CHOR 200001
#define pb push_back

typedef long long ll;

ll arr[CHOR];

struct zex
{
	std::vector<ll> tlna;
	ll inc;
}seg[4*CHOR];

ll bs1(ll val, std::vector<ll>& elec)
{
	ll lo = 0;
	ll hi = (ll)elec.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo)/2;
		if(elec[mid] < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if(elec[lo] >= val)	
	return lo;
	else return lo + 1;
}

class segtree
{
	public: void build(ll i, ll s, ll d);
			zex merger(zex left, zex right);
};

void segtree::build(ll i, ll s, ll d)
{
	if(s == d)
	{
		seg[i].tlna.clear();
		seg[i].tlna.pb(arr[s]);
		seg[i].inc = 0;
		return;
	}	
	ll m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

zex segtree::merger(zex left, zex right)
{
	zex res;
	res.inc = 0;
	res.tlna.clear();
	for(ll i=0,j=(ll)left.tlna.size();i<j;i++)	
	res.inc += bs1(left.tlna[i], right.tlna);
	res.inc += (left.inc + right.inc);
	ll i=0, j=0;
	ll n1 = left.tlna.size(), n2 = right.tlna.size();
	while(i != n1 && j != n2)
	{
		if(left.tlna[i] < right.tlna[j])
		{
			res.tlna.pb(left.tlna[i]);
			i++;
		}	
		else if(left.tlna[i] > right.tlna[j])
		{
			res.tlna.pb(right.tlna[j]);
			j++;
		}
		else
		{
			res.tlna.pb(left.tlna[i]);
			res.tlna.pb(right.tlna[j]);
			i++;
			j++;
		}	
	}
	while(i != n1)
	{
		res.tlna.pb(left.tlna[i]);
		i++;
	}	
	while(j != n2)
	{
		res.tlna.pb(right.tlna[j]);
		j++;	
	}	
	return res;
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
		ll n;
		std::cin>>n;
		for(ll i=1;i<=n;i++)
		std::cin>>arr[i];
		segtree D;
		D.build(1, 1, n);
		std::cout<<seg[1].inc<<"\n";	
	}	
	return 0;
}