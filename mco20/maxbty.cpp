#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
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
ll arr[2][MV];
PLL seg[2][4*MV];

class segtree
{
	public: void build(int ty, int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void update(int ty, int i, int s, int d, int x);
			PLL query(int ty, int i, int s, int d, int qs, int qd);
};

void segtree::build(int ty, int i, int s, int d)
{
	if(s == d)
	{
		seg[ty][i] = {arr[ty][s], arr[ty][s]};
		return;
	}	
	int m = (s + d)/2;
	build(ty, 2*i, s, m);
	build(ty, 2*i+1, m+1, d);
	seg[ty][i] = merger(seg[ty][2*i], seg[ty][2*i+1]);
	return;
}

PLL segtree::merger(PLL left, PLL right)
{
	PLL res;
	res.ff = (left.ff + right.ff);
	res.ss = min(left.ss, left.ff + right.ss);
	return res;
}

void segtree::update(int ty, int i, int s, int d, int x)
{
	if(s == d)
	{
		seg[ty][i] = {arr[ty][s], arr[ty][s]};
		return;
	}	
	int m = (s + d)/2;
	if(x <= m)
	update(ty, 2*i, s, m, x);
	else update(ty, 2*i+1, m+1, d, x);
	seg[ty][i] = merger(seg[ty][2*i], seg[ty][2*i+1]);
	return;	
}

PLL segtree::query(int ty, int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return {0, INF};
	else if(qs <= s && d <= qd)
	return seg[ty][i];
	int m = (s + d)/2;
	PLL p1 = query(ty, 2*i, s, m, qs, qd);
	PLL p2 = query(ty, 2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);
}

void solve(int T)
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>arr[0][i];
	for(int i=1;i<=n;i++)
	arr[1][i] = arr[0][n-i+1];	
	segtree Z;
	Z.build(0, 1, 1, n);
	Z.build(1, 1, 1, n);
	while(q--)
	{
		char po;
		ll l,r;
		cin>>po>>l>>r;
		if(po == 'U')
		{
			arr[0][l] = r;
			arr[1][n-l+1] = r;
			Z.update(0, 1, 1, n, l);
			Z.update(1, 1, 1, n, n-l+1);
		}
		else
		{
			PLL ax1, ax2, ax3;
			ax1 = {0, 0};
			ax2 = {0, 0};
			ax3 = {0, 0};
			ax1 = Z.query(0, 1, 1, n, 1, r);
			if(l > 1)
			ax2 = Z.query(0, 1, 1, n, 1, l-1);
			if(r+1 <= n)
			ax3 = Z.query(1, 1, 1, n, 1, n-r);
			// cout<<ax1.ff<<" "<<ax2.ff<<" "<<ax2.ss<<"\n";
			ll res = (ax1.ff - ax2.ff) + (ax2.ff - min(0LL, ax2.ss)) + (ax3.ff - min(0LL, ax3.ss));
			cout<<res<<"\n";
		}
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