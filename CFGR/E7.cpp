#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 300001
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

int ar[MV], rz[MV], qry[MV];
ll arr[MV];
PII seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			PII merger(PII left, PII right);
			void update(int i, int s, int d, int x, int v);
			PII query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {0, 0};
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PII segtree::merger(PII left, PII right)
{
	PII res;
	if(right.ss >= left.ff)
	{
		res.ff = right.ff;
		res.ss = left.ss + (right.ss - left.ff);
	}	
	else
	{
		res.ff = right.ff + (left.ff - right.ss);
		res.ss = left.ss;
	}
	return res;
}

void segtree::update(int i, int s, int d, int x, int v)
{
	if(s == d)
	{
		if(v > 0)
		seg[i].ff += v;
		else seg[i].ss += -v;
		if(seg[i].ff >= seg[i].ss)
		{
			seg[i].ff -= seg[i].ss;
			seg[i].ss = 0;
		}
		else
		{
			seg[i].ss -= seg[i].ff;
			seg[i].ff = 0;
		}
		return;
	}
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, v);
	else update(2*i+1, m+1, d, x, v);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

PII segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return {0, 0};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	PII p1 = query(2*i, s, m, qs, qd);
	PII p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		rz[ar[i]] = i;
	}	
	int mx = n;
	segtree D;
	D.build(1, 1, n);
	D.update(1, 1, n, rz[mx], 1);
	for(int i=1;i<=n;i++)
	{
		int v;
		cin>>v;
		cout<<mx<<" ";
		D.update(1, 1, n, v, -1);
		while(D.query(1, 1, n, 1, n).ff <= 0)
		{
			mx--;
			D.update(1, 1, n, rz[mx], 1);
		}
	}	
	cout<<"\n";
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