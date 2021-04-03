#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 38158120
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
// #define whoami(x) cerr<<#x<<" "<<x<<"\n";
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

int64_t readLL (void) {
	bool minus = false;
	int64_t result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = 1LL*(ch-'0');
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + 1LL*(ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int64_t phi[MV];
unordered_map<ll, uint64_t, h_llint> sp;
unordered_map<ll, bool, h_llint> vis;

void siever(int yt)
{
	iota(phi, phi+yt, 0);
	for(int p=2;p<yt;p++)
	{
		if(phi[p] == p)
		{
			for(int i=p;i<yt;i+=p)
			phi[i] = (phi[i]/p) * (p-1);	
		}
	}	
	sp[0] = 0;
	sp[1] = 1;
	for(int i=2;i<yt;i++)
	phi[i] += phi[i-1];
	return;
}

uint64_t etf_pref(int64_t x, int yt)
{
	if(x < yt)
	return phi[x];
	if(vis[x])
	return sp[x];
	uint64_t ans = 0;
	for(int64_t i=2,la;i<=x;i=la+1)
	{
		la = x/(x/i);
		uint64_t a1 = la, a2 = (i-1);
		uint64_t df = a1 - a2;
		uint64_t pf = etf_pref(x/i, yt);
		ans += (df * pf);
	}	
	uint64_t ux = x;
	uint64_t uxt = ((ux & 1) ? (((ux+1) / 2) * ux) : ((ux / 2) * (ux+1)));
	ans = uxt - ans;
	sp[x] = ans;
	vis[x] = 1;
	return ans;
}

void solve(int64_t T)
{
	vector<int64_t> ux(T);
	vector<uint64_t> rt;
	int64_t mn = 0;
	for(auto &&n : ux)
	{	
		n = readLL();
		if(n > mn)
		mn = n;
	}
	int yt = 0;
	if(mn <= 100000000)
	yt = 400000;
	else if((mn > 100000000) && (mn <= 10000000000))
	yt = 5011877;
	else if((mn > 10000000000) && (mn <= 100000000000))
	yt = 21877620;	
	else yt = MV;	
	siever(yt);
	// printf("%lld %lld\n", mn, yt);
	for(auto &&n : ux)
	{		
		uint64_t res = 0;
		for(int64_t i=1,la;i<=n;i=la+1)
		{
			la = n/(n/i);
			uint64_t ux = n/i;
			uint64_t df = ((ux & 1) ? (((ux-1) / 2) * ux) : ((ux / 2) * (ux-1)));
			uint64_t pf = etf_pref(la, yt) - etf_pref(i-1, yt);
			res += (df * pf); 
		}
		rt.pb(res);
	}	
	for(auto &&res : rt)
	printf("%llu\n", res);
	return;
}

int main(void)
{
	FLASH();
	int64_t T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	T = readLL();
	solve(T);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}