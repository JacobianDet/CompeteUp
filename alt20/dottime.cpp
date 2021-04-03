#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 500001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
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

const int MOD = 998244353;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct h_llint {
  static uint64_t splitmix64(uint64_t x) {    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct h_pair{
  size_t operator()(const PLL&x)const{
    return hash<ll>()(((ll)x.ff)^(((ll)x.ss)<<32));
  }
};

typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;
//ordered_set = order_of_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV];
ll arr[MV], lazy[4*MV];
PLL seg[4*MV], rz[MV];

class segtree
{
	public: void build(int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void update(int i, int s, int d, int qs, int qd, ll val);
			PLL query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {0, 0};
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
	return {(((left.ff%MOD) + (right.ff%MOD))%MOD), (((left.ss%MOD) + (right.ss%MOD))%MOD)};
}

void segtree::update(int i, int s, int d, int qs, int qd, ll val)
{
	if(lazy[i] != 0)
	{
		seg[i].ss = ((((seg[i].ss%MOD) + ((((((1LL*d-s+1)%MOD) * ((MOD + lazy[i])%MOD))%MOD) * ((MOD + lazy[i])%MOD))%MOD))%MOD) + (((((2%MOD) * ((MOD + lazy[i])%MOD))%MOD) * (seg[i].ff%MOD))%MOD))%MOD;
		seg[i].ff = ((seg[i].ff%MOD) + ((((d-s+1)%MOD) * ((MOD + lazy[i])%MOD))%MOD))%MOD;
		if(s < d)
		{
			lazy[2*i] = (((MOD + lazy[2*i])%MOD) + ((MOD + lazy[i])%MOD))%MOD;
			lazy[2*i+1] = (((MOD + lazy[2*i+1])%MOD) + ((MOD + lazy[i])%MOD))%MOD;
		}
		lazy[i] = 0;
	}	
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		seg[i].ss = ((((seg[i].ss%MOD) + ((((((1LL*d-s+1)%MOD) * ((MOD + val)%MOD))%MOD) * ((MOD + val)%MOD))%MOD))%MOD) + (((((2%MOD) * ((MOD + val)%MOD))%MOD) * (seg[i].ff%MOD))%MOD))%MOD;
		seg[i].ff = ((seg[i].ff%MOD) + ((((d-s+1)%MOD) * ((MOD + val)%MOD))%MOD))%MOD;
		if(s < d)
		{
			lazy[2*i] = (((MOD + lazy[2*i])%MOD) + ((MOD + val)%MOD))%MOD;
			lazy[2*i+1] = (((MOD + lazy[2*i+1])%MOD) + ((MOD + val)%MOD))%MOD;
		}
		lazy[i] = 0;
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, val);
	update(2*i+1, m+1, d, qs, qd, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != 0)
	{
		seg[i].ss = ((((seg[i].ss%MOD) + ((((((1LL*d-s+1)%MOD) * ((MOD + lazy[i])%MOD))%MOD) * ((MOD + lazy[i])%MOD))%MOD))%MOD) + (((((2%MOD) * ((MOD + lazy[i])%MOD))%MOD) * (seg[i].ff%MOD))%MOD))%MOD;
		seg[i].ff = ((seg[i].ff%MOD) + ((((d-s+1)%MOD) * ((MOD + lazy[i])%MOD))%MOD))%MOD;
		if(s < d)
		{
			lazy[2*i] = (((MOD + lazy[2*i])%MOD) + ((MOD + lazy[i])%MOD))%MOD;
			lazy[2*i+1] = (((MOD + lazy[2*i+1])%MOD) + ((MOD + lazy[i])%MOD))%MOD;
		}
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return {0, 0};
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
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	rz[i] = {1, i};
	for(int i=m+1;i<=n-m+1;i++)
	rz[i] = {1, m};
	for(int i=n-m+2;i<=n;i++)
	rz[i] = {i-(n-m+1)+1, m};	
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	segtree D;
	D.build(1, 1, m);
	ll sx = 0;
	for(int i=1;i<=n-m+1;i++)
	sx = ((sx%MOD) + (arr[i]%MOD))%MOD;
	D.update(1, 1, m, 1, 1, sx);
	for(int i=n-m+2;i<=n;i++)
	{
		sx = ((sx%MOD) - (arr[i-n+m-1]%MOD) + MOD)%MOD;
		sx = ((sx%MOD) + (arr[i]%MOD))%MOD;
		D.update(1, 1, m, i-n+m, i-n+m, sx);
	}	
	while(q--)
	{
		int pos;
		ll val;
		cin>>pos>>val;
		ll df = ((val%MOD) - (arr[pos]%MOD) + MOD)%MOD;
		arr[pos] = val;
		D.update(1, 1, m, rz[pos].ff, rz[pos].ss, df);
		cout<<D.query(1, 1, m, 1, m).ss<<"\n";
	}
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	cin>>T;
	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}