#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define MV 400001

typedef long long ll;

std::pair<ll, ll> arr[MV];
std::pair<ll, ll> bx[MV];

bool cmp(std::pair<ll, ll> u, std::pair<ll, ll> v)
{
	return (u.first == v.first) ? (u.second < v.second) : (u.first < v.first);
}

struct mn
{
	ll sum, lx;
}seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			mn merger(mn left, mn right);
			void update(int i, int s, int d, int x, ll val);
			mn query(int i, int s, int d, ll a, ll b, ll sz);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i].sum = 0;
		seg[i].lx = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

mn segtree::merger(mn left, mn right)
{
	mn res;
	res.sum = 0;
	res.lx = 0;
	res.sum = left.sum + right.sum;
	res.lx = left.lx + right.lx;
	return res;
}

void segtree::update(int i, int s, int d, int x, ll val)
{
	if(s == d)
	{
		seg[i].sum = val;
		seg[i].lx = 1;
		return;
	}	
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, val);
	else update(2*i+1, m+1, d, x, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

mn segtree::query(int i, int s, int d, ll a, ll b, ll sz)
{
	if(!(seg[i].sum))
	return {-1, 0};
	else if(s > d)
	return {0, 0};
	else if((seg[i].sum + b) <= a*(sz + seg[i].lx))
	return seg[i];
	else if(s == d)
	return {0, 0};	
	else
	{	
		int m = (s + d)/2;
		mn p1 = query(2*i, s, m, a, b, sz);
		if(!(p1.sum))
		return p1;	
		else if(p1.sum == -1)
		{
			p1.sum = 0;
			p1.lx = 0;
		}
		if((p1.sum + b) <= a*(sz + p1.lx))
		{
			mn p2 = query(2*i+1, m+1, d, a, (p1.sum + b), (p1.lx + sz));
			if(p2.sum == -1)
			p2 = {0, 0};	
			p1 = merger(p1, p2);
		} 	
		return p1;
	}	
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
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			ll a, b;
			std::cin>>a>>b;
			arr[i] = mp(a, b);
		}	
		std::sort(arr+1, arr+n+1, cmp);
		for(int i=1;i<=n;i++)
		bx[i] = mp(arr[i].second, i);
		std::sort(bx+1, bx+n+1, cmp);
		segtree D;
		D.build(1, 1, n);
		ll ans = 0;
		for(int i=n;i>=1;i--)
		{
			mn res = D.query(1, 1, n, arr[i].first, arr[i].second, 1);
			if(!(res.lx))
			{
				if(arr[i].first >= arr[i].second)
				res.lx++;	
			}	
			else res.lx++;
			ans = std::max(ans, res.lx);
			int lp = std::lower_bound(bx+1, bx+n+1, mp(arr[i].second, i), cmp) - (bx+1);
			D.update(1, 1, n, lp+1, arr[i].second);
		}	
		std::cout<<ans<<"\n";
	}
	return 0;	
}