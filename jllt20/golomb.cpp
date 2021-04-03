#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 2000001
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

ll arr[MV], srr[MV], sar[MV], sqr[MV];

void pre(void)
{
	arr[1] = 1;
	sar[1] = 1;
	srr[1] = 1;
	sqr[1] = 1;
	for(int i=2;i<MV;i++)
	{	
		arr[i] = 1 + arr[i-arr[arr[i-1]]];
		sar[i] = sar[i-1] + 1LL*i * arr[i];
		sqr[i] = ((sqr[i-1]%MOD) + ((((((1LL*i)%MOD) * ((1LL*i)%MOD))%MOD) * (arr[i]%MOD))%MOD))%MOD;
		srr[i] = srr[i-1] + arr[i];
	}
	return;
}

ll bs1(ll x)
{
	ll lo = 1;
	ll hi = MV-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(sar[mid] >= x)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

void solve(int T)
{
	ll l,r;
	cin>>l>>r;
	ll c1 = bs1(r);
	ll c2 = ((l == 1) ? 0 : bs1(l-1));
	ll vx1 = srr[c1-1] + (r - sar[c1-1] + c1 - 1)/c1;
	ll vx2 = 0;
	if(l > 1)
	vx2 = srr[c2-1] + (l-1 - sar[c2-1] + c2 - 1)/c2;
	ll x1 = ((sqr[vx1-1]%MOD) + ((((((r - srr[vx1-1])%MOD) * (vx1%MOD))%MOD) * (vx1%MOD))%MOD))%MOD;
	ll x2 = 0;
	if(l > 1)
	x2 = ((sqr[vx2-1]%MOD) + ((((((l-1 - srr[vx2-1])%MOD) * (vx2%MOD))%MOD) * (vx2%MOD))%MOD))%MOD;
	ll xx = (x1 - x2 + MOD)%MOD;
	cout<<xx<<"\n";
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

	pre();
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