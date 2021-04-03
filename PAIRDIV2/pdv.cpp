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

const int MOD = 1000000000;

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
bool isP[MV];
VL px;

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0, isP[1] = 0;
	for(int p=2;p*p<MV;p++)
	{
		if(isP[p])
		{
			for(int i=p*p;i<MV;i+=p)
			isP[i] = 0;
		}
	}	
	for(int p=2;p<MV;p++)
	{
		if(isP[p])
		px.pb(p);	
	}	
	return;
}

void solve(int T)
{
	ll n,a,b;
	cin>>n>>a>>b;
	VL dv, mu;
	for(ll i=1;i*i<=n;i++)
	{
		if(!(n % i))
		{
			dv.pb(i);
			if((i*i) != n)
			dv.pb(n/i);	
		}
	}	
	sort(begin(dv), end(dv));
	for(auto &&u : dv)
	{
		ll uy = u, m = 1;
		for(auto &&e : px)
		{
			if(!(uy % e))
			{
				uy /= e;
				m = -m;
				if(!(uy % e))
				{
					m = 0;
					break;
				}	
			}	
		}
		mu.pb(m);	
	}
	ll tot = 0;
	for(int i=0;i<(int)dv.sz();i++)
	{
		ll p1 = dv[i];
		ll p2 = n/dv[i];
		ll x2 = ((b/p2)%MOD);
		ll x1 = 0;
		for(int j=0;j<(int)dv.sz();j++)
		{
			if(!(p2 % dv[j]))
			x1 = ((x1%MOD) + (((mu[j] + MOD) * (((a/p1)/dv[j])%MOD))%MOD))%MOD;	
		}
		tot = ((tot%MOD) + (((x1%MOD) * (x2%MOD))%MOD))%MOD;
	}	
	cout<<tot<<"\n";
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

	siever();
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