#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ins insert
#define sz size

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;

int ar[MV];
ll arr[MV], lazy[4*MV];
PLL seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void update(int i, int s, int d, int qs, int qd, ll x);
			PLL query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = mp(arr[s], s);
		lazy[i] = 0;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = 0;
	return;
}

PLL segtree::merger(PLL left, PLL right)
{
	if(left.ff < right.ff)
	return left;
	else return right;	
}

void segtree::update(int i, int s, int d, int qs, int qd, ll x)
{
	if(lazy[i] != 0)
	{
		seg[i].ff += lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		seg[i].ff += x;
		if(s < d)
		{
			lazy[2*i] += x;
			lazy[2*i+1] += x;
		}	
		return;
	}
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, x);
	update(2*i+1, m+1, d, qs, qd, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != 0)
	{
		seg[i].ff += lazy[i];
		if(s < d)
		{
			lazy[2*i] += lazy[i];
			lazy[2*i+1] += lazy[i];
		}	
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return mp(1000000000000LL, 0);
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	PLL p1 = query(2*i, s, m, qs, qd);
	PLL p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	segtree Z;
	Z.build(1, 1, n);
	for(int i=1;i<=n;i++)
	{
		int x = Z.query(1, 1, n, 1, n).ss;
		ar[x] = i;
		Z.update(1, 1, n, x, x, 1000000000000LL);
		if(x+1 <= n)
		Z.update(1, 1, n, x+1, n, 1LL*(-i));
	}	
	for(int i=1;i<=n;i++)
	std::cout<<ar[i]<<" ";
	std::cout<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}