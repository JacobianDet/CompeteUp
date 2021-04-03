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

int ar[MV], seg[4*MV];
ll arr[MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			void update(int i, int s, int d, int x, int vx);
			int query(int i, int s, int d, int qs, int qd); 
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = MOD;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::merger(int left, int right)
{
	return min(left, right);
}

void segtree::update(int i, int s, int d, int x, int vx)
{
	if(s == d)
	{
		seg[i] = vx;
		return;
	}
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, vx);
	else update(2*i+1, m+1, d, x, vx);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return MOD;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

struct dxd
{
	int tx, tp, idx;
};

vector<dxd> swp;

struct x3
{
	int s,e,p;
}ax[MV], qy[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ax[i].s>>ax[i].e>>ax[i].p;
		swp.pb({ax[i].s, 2, i});
		swp.pb({ax[i].e, 1, i});
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>qy[i].s>>qy[i].e>>qy[i].p;
		swp.pb({qy[i].s, 3, i});
	}
	segtree D;
	D.build(1, 1, n);
	sort(swp.begin(), swp.end(), [](dxd A, dxd B){ return ((A.tx < B.tx) || ((A.tx == B.tx) && (A.tp < B.tp))); });
	for(auto u : swp)
	{
		if(u.tp == 1)
		D.update(1, 1, n, u.idx, MOD);
		else if(u.tp == 2)
		D.update(1, 1, n, u.idx, ax[u.idx].p);
		else 
		{
			int lb = max(1, qy[u.idx].e - qy[u.idx].p);
			int rb = min(n, qy[u.idx].e + qy[u.idx].p);
			ar[u.idx] = D.query(1, 1, n, lb, rb);
			if(ar[u.idx] == MOD)
			ar[u.idx] = -1;	
		}	
	}
	for(int i=1;i<=q;i++)
	cout<<ar[i]<<"\n";
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