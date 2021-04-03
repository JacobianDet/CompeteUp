#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()
#define whoami(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); whi(_it, args); }

void whi(istream_iterator<string> it) { cerr<<"\n"; }

template<typename T, typename... Args>
void whi(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" "<<a<<" "; whi(++it, args...); }

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
const ll INF = 4e18;

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
ll arr[MV], seg[2][4*MV];
vector<PLL> axd, bxd;

class segtree1
{
	public: void build(int i, int s, int d);
			ll merger(ll left, ll right);
			ll query(int i, int s, int d, int qs, int qd);
};

class segtree2
{
	public: void build(int i, int s, int d);
			ll merger(ll left, ll right);
			ll query(int i, int s, int d, int qs, int qd);
};

void segtree1::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[0][i] = bxd[s-1].ff + bxd[s-1].ss;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[0][i] = merger(seg[0][2*i], seg[0][2*i+1]);
	return;
}

ll segtree1::merger(ll left, ll right)
{
	return max(left, right);
}

ll segtree1::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return 0LL;
	else if(qs <= s && d <= qd)
	return seg[0][i];
	int m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

void segtree2::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[1][i] = axd[s-1].ff + axd[s-1].ss;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[1][i] = merger(seg[1][2*i], seg[1][2*i+1]);
	return;
}

ll segtree2::merger(ll left, ll right)
{
	return max(left, right);
}

ll segtree2::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return 0LL;
	else if(qs <= s && d <= qd)
	return seg[1][i];
	int m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

int bbs1(ll vx, ll ct)
{
	int lo = 0;
	int hi = sz(bxd)-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(bxd[mid].ss + vx <= ct)
		hi = mid;
		else lo = mid + 1;	
	}
	if((lo > hi) || (bxd[lo].ss + vx > ct))
	return -1;	
	else return lo;
}

int bbs2(ll vx, ll ct)
{
	int lo = 0;
	int hi = sz(bxd)-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(bxd[mid].ff + vx <= ct)
		lo = mid;
		else hi = mid - 1;	
	}
	if((lo > hi) || (bxd[lo].ff + vx > ct))
	return -1;	
	else return lo;
}

int abs1(ll vx, ll ct)
{
	int lo = 0;
	int hi = sz(axd)-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(axd[mid].ss + vx <= ct)
		hi = mid;
		else lo = mid + 1;	
	}
	if((lo > hi) || (axd[lo].ss + vx > ct))
	return -1;	
	else return lo;
}

int abs2(ll vx, ll ct)
{
	int lo = 0;
	int hi = sz(axd)-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(axd[mid].ff + vx <= ct)
		lo = mid;
		else hi = mid - 1;	
	}
	if((lo > hi) || (axd[lo].ff + vx > ct))
	return -1;	
	else return lo;
}

void solve(int T)
{
	ll p,f;
	cin>>p>>f;
	ll cs, cw;
	cin>>cs>>cw;
	ll s,w;
	cin>>s>>w;
	for(ll i=0;i<=cs;i++)
	{
		if(p - i*s >= 0)
		{	
			ll j = max(0LL, min(cw, (p - i*s)/w));
			axd.pb({i, j});
		}	
	}	
	for(ll i=0;i<=cs;i++)
	{
		if(f - i*s >= 0)
		{
			ll j = max(0LL, min(cw, (f - i*s)/w));
			bxd.pb({i, j});
		}	
	}
	segtree1 D;
	if(sz(bxd) > 0)
	D.build(1, 1, sz(bxd));
	ll mz = 0;
	for(auto &&u : axd)
	{
		int p1 = bbs2(u.ff, cs);
		int p2 = bbs1(u.ss, cw);
		whoami(p1, p2, u.ff, u.ss);
		if((p1 != -1) && (p2 != -1) && (p2 <= p1))
		mz = max(mz, u.ff + u.ss + D.query(1, 1, sz(bxd), p2+1, p1+1));
		else mz = max(mz, u.ff + u.ss);
	}
	segtree2 J;
	if(sz(axd) > 0)
	J.build(1, 1, sz(axd));
	for(auto &&u : bxd)
	{
		int p1 = abs2(u.ff, cs);
		int p2 = abs1(u.ss, cw);
		whoami(p1, p2, u.ff, u.ss);
		if((p1 != -1) && (p2 != -1) && (p2 <= p1))
		mz = max(mz, u.ff + u.ss + J.query(1, 1, sz(axd), p2+1, p1+1));
		else mz = max(mz, u.ff + u.ss);
	}
	cout<<mz<<"\n";
	axd.clear();
	bxd.clear();
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

	cin>>T;
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