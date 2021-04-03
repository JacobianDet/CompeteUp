#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 200001
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
void SETF() {cout.ios_base::setf(ios_base::fixed); cerr.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed); cerr.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

const int MOD = 1000000007;

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
ll gpt[MV], spt[MV], seg[4*MV], lazy[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			ll merger(ll left, ll right);
			void update(int i, int s, int d, int qs, int qd, ll v);
			ll query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = 0;
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

ll segtree::merger(ll left, ll right)
{
	return ((left%MOD) + (right%MOD))%MOD;
}

void segtree::update(int i, int s, int d, int qs, int qd, ll v)
{
	if(lazy[i] != 0)
	{
		ll gf = spt[d-s+1]%MOD;
		seg[i] = ((seg[i]%MOD) + (((lazy[i]%MOD) * (gf%MOD))%MOD))%MOD;
		if(s < d)
		{
			lazy[2*i] = ((lazy[2*i]%MOD) + (lazy[i]%MOD))%MOD;
			int m = (s + d)/2;
			lazy[2*i+1] = ((lazy[2*i+1]%MOD) + (((lazy[i]%MOD) * (gpt[m+1-s]%MOD))%MOD))%MOD;
		}
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		ll ov = v * gpt[s-qs];
		ll gf = spt[d-s+1]%MOD;
		seg[i] = ((seg[i]%MOD) + (((ov%MOD) * (gf%MOD))%MOD))%MOD;
		if(s < d)
		{
			lazy[2*i] = ((lazy[2*i]%MOD) + (ov%MOD))%MOD;
			int m = (s + d)/2;
			lazy[2*i+1] = ((lazy[2*i+1]%MOD) + (((ov%MOD) * (gpt[m+1-s]%MOD))%MOD))%MOD;
		}
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, v);
	update(2*i+1, m+1, d, qs, qd, v);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != 0)
	{
		ll gf = spt[d-s+1]%MOD;
		seg[i] = ((seg[i]%MOD) + (((lazy[i]%MOD) * (gf%MOD))%MOD))%MOD;
		if(s < d)
		{
			lazy[2*i] = ((lazy[2*i]%MOD) + (lazy[i]%MOD))%MOD;
			int m = (s + d)/2;
			lazy[2*i+1] = ((lazy[2*i+1]%MOD) + (((lazy[i]%MOD) * (gpt[m+1-s]%MOD))%MOD))%MOD;
		}
		lazy[i] = 0;
	}
	if(s > qd || d < qs)
	return 0;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

void solve(int T)
{
	int n,q;
	ll r;
	cin>>n>>r>>q;
	gpt[0] = 1; spt[0] = 0; spt[1] = 1;
	for(int i=1;i<=n;i++)
	{
		gpt[i] = ((gpt[i-1]%MOD) * (r%MOD))%MOD;
		spt[i+1] = ((spt[i]%MOD) + (gpt[i]%MOD))%MOD;
	}	
	segtree D;
	D.build(1, 1, n);
	while(q--)
	{
		int ty;
		cin>>ty;
		if(ty == 0)
		{
			ll st;
			int a,b;
			cin>>st>>a>>b;
			D.update(1, 1, n, a, b, st);
		}
		else if(ty == 2)
		{
			int l;
			cin>>l;
			ll sx = (MOD - (D.query(1, 1, n, l, l)%MOD))%MOD;
			D.update(1, 1, n, l, l, sx);
		}
		else
		{
			int a,b;
			cin>>a>>b;
			cout<<D.query(1, 1, n, a, b)%MOD<<"\n";
		}
	}
	return;
}

int main(void)
{
	FLASH();
	//freopen("cowjog.in", "r", stdin);
	//freopen("cowjog.out", "w", stdout);
	int T;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	//cin>>T;
	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}