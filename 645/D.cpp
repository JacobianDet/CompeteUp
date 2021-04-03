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
#define sz size
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
ll arr[MV];
VL axd, pf, spf;

ll bs1(ll i, ll x, ll n)
{
	ll lo = i;
	ll hi = n-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		ll cv = pf[mid] - ((i > 0) ? pf[i-1] : 0);
		if(cv >= x)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

void solve(int T)
{
	ll n,x;
	cin>>n>>x;
	for(ll i=0;i<n;i++)
	{
		ll t;
		cin>>t;
		axd.pb(t);
	}	
	for(int i=0;i<n;i++)
	axd.pb(axd[i]);
	for(int i=0;i<2*n;i++)
	{
		if(!i)
		{
	    	pf.pb(axd[i]);
	    	spf.pb((axd[i] * (axd[i]+1))/2);
	    }	
		else
		{
			pf.pb(pf[i-1] + axd[i]);
			spf.pb(spf[i-1] + (axd[i] * (axd[i]+1))/2);
		}		
	}	
	ll mx = 0;
	for(ll i=0;i<n;i++)
	{
		ll jx = bs1(i, x, 2*n);
		if(jx > i)
		{
			ll df1 = axd[jx] - (x - pf[jx-1] + ((i > 0) ? pf[i-1] : 0));
			ll df2 = axd[i];
			mx = max(mx, spf[jx-1] - ((i > 0) ? spf[i-1] : 0) + ((x - pf[jx-1] + ((i > 0) ? pf[i-1] : 0)) * (1 + x - pf[jx-1] + ((i > 0) ? pf[i-1] : 0)))/2);
			if(df1 < df2)
			mx = max(mx, spf[jx] - ((i > 0) ? spf[i-1] : 0) - ((df1 + 1) * df1)/2);
		}
		else 
		{
			ll sf = (axd[i] * (axd[i] + 1))/2 - ((axd[i] - x) * (axd[i] - x + 1))/2;
			mx = max(mx, sf);
		}		
	}	
	cout<<mx<<"\n";
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