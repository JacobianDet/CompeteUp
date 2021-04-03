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
ll arr[MV];
map<PLL, ll> dd1;
map<PLL, bool> vis;

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

void solve(int T)
{
	int n;
	cin>>n;
	vector<PLL> axd(n);
	for(auto &&u : axd)
	{
		cin>>u.ff>>u.ss;	
		int sg1 = 0, sg2 = 0;
		if(u.ff < 0)
		sg1 = 1;
		if(u.ss < 0)
		sg2 = 1;
		if(sg1 && sg2)
		{	
			u.ff = -u.ff;
			u.ss = -u.ss;
		}
		if(sg1 && !sg2)
		{
			u.ff = -u.ff;
			u.ss = -u.ss;
		}	
		if((u.ff == 0) || (u.ss == 0))
		{
			u.ff = abs(u.ff);
			u.ss = abs(u.ss);
		}	
		ll gc = __gcd(abs(u.ff), abs(u.ss));
		if(gc > 0)
		{
			u.ff /= gc;
			u.ss /= gc;
		}	
		dd1[u]++;
	}	
	ll fc = 1;
	for(auto &&u : dd1)
	{
		if(((u.ff.ff != 0) || (u.ff.ss != 0)) && !vis[u.ff])
		{
			vis[u.ff] = 1;
			ll ax = abs(u.ff.ss);
			ll bx = abs(u.ff.ff);
			if(u.ff.ss >= 0)
			bx = -bx;	
			if(dd1.count({ax, bx}))
			{
				vis[{ax, bx}] = 1;	
				fc = ((fc%MOD) * (((((modexp(2, u.ss)%MOD) + (modexp(2, dd1[{ax, bx}])%MOD))%MOD) - 1 + MOD)%MOD))%MOD;	
			}	
			else fc = ((fc%MOD) * (modexp(2, u.ss)%MOD))%MOD;
		}
	}
	fc = ((fc%MOD) - 1 + MOD)%MOD;
	if(dd1.count({0, 0}))
	fc = ((fc%MOD) + (dd1[{0, 0}]%MOD))%MOD;	
	cout<<fc<<"\n";
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