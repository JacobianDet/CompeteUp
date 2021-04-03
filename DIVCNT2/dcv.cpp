#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 70000010
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

ll readLL (void) {
	bool minus = false;
	ll result = 0;
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

ll su0[MV], mu[MV], musq[MV];
int lo[MV];
UMLL smu, smusq, ssu0;
unordered_map<ll, bool, h_llint> vsmu, vsmusq, vssu0;

void mob_sling(int yt)
{
	for(int i=1;i<yt;i++)
	{	
		lo[i] = i;
		mu[i] = 1;
		su0[i] = 2;
	}
	su0[1] = 1;	
	for(int p=2;(p*p)<yt;p++)
	{
		if(lo[p] == p)
		{	
			for(int i=p*p;i<yt;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}
		}		
	}	
	for(int i=2;i<yt;i++)
	{
		if(lo[i/lo[i]] == lo[i])
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];
	}
	for(int i=2;i<yt;i++)
	{
		int j = i;
		ll ct = 0;
		while(lo[j/lo[j]] == lo[j])
		{
			j /= lo[j];
			ct++;
		}
		if(ct > 0)
		su0[i] = (su0[i/lo[i]]/(1 + ct)) * (2 + ct);	
		else su0[i] = su0[lo[i]] * su0[i/lo[i]];	
	}
	for(int p=1;p<yt;p++)
	{
		musq[p] = musq[p-1] + (mu[p] * mu[p]);
		mu[p] += mu[p-1];
		su0[p] += su0[p-1];
	}	
	return;
}	

ll mu_pref(ll x, int yt)
{
	if(x < yt)
	return mu[x];
	if(vsmu[x])
	return smu[x];
	ll ans = 0;
	for(ll i=2,la;i<=x;i=la+1)
	{
		la = x/(x/i);
		ll a1 = la, a2 = (i-1);
		ll df = a1 - a2;
		ll pf = mu_pref(x/i, yt);
		ans += (df * pf);
	}	
	ans = 1 - ans;
	smu[x] = ans;
	vsmu[x] = 1;
	return ans;	
}

ll musq_pref(ll x, int yt)
{
	if(x < yt)
	return musq[x];
	if(vsmusq[x])
	return smusq[x];
	ll ans = 0;
	for(ll i=1,la;i*i<=x;i=la+1)
	{
		la = sqrtl(x/(x/(i*i)));
		ll pf = mu_pref(la, yt) - mu_pref(i-1, yt);
		ans += ((x/(i*i)) * pf);
	}
	smusq[x] = ans;
	vsmusq[x] = 1;
	return ans;	
}

ll su0_pref(ll x, int yt)
{
	if(x < yt)
	return su0[x];
	if(vssu0[x])
	return ssu0[x];
	ll ans = 0;
	for(ll i=1,la;i<=x;i=la+1)
	{
		la = x/(x/i);
		ll a1 = la, a2 = (i-1);
		ll df = a1 - a2;
		ans += ((x/i) * df);
	}
	ssu0[x] = ans;
	vssu0[x] = 1;
	return ans;	
}

void solve(int T)
{
	VL ux(T);
	ll mn = 0;
	for(auto &&n : ux)
	{
		n = readLL();
		if(n > mn)
		mn = n;
	}
	VL res;
	int yt = (pow(mn, 2.0/3.0) + 10);
	if(yt > MV)
	yt = MV;	
	mob_sling(yt);
	for(auto &&n : ux)
	{		
		ll ans = 0;
		for(ll i=1,la;i<=n;i=la+1)
		{
			la = n/(n/i);
			ll df = su0_pref(n/i, yt);
			ll pf = musq_pref(la, yt) - musq_pref(i-1, yt);
			ans += (df * pf);
		}
		res.pb(ans);
	}	
	for(auto &&u : res)
	printf("%lld\n", u);
	return;	
}

int main(void)
{
	// FLASH();
	int T;
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