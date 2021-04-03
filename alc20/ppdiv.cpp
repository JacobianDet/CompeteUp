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

int ar[MV], lo[MV], mu[MV];
ll arr[MV], inv[MV];

ll fexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}
	return res;
}

void mob_sling(void)
{
	for(int i=1;i<MV;i++)
	{	
		lo[i] = i;
		mu[i] = 1;
	}	
	for(int p=2;((1LL*p)*p)<MV;p++)
	{
		if(lo[p] == p)
		{	
			for(int i=p*p;i<MV;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}
		}		
	}	
	for(int i=2;i<MV;i++)
	{
		int j = i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];
	}
	inv[1] = 1;
	for(ll i=2;i<MV;i++)
	inv[i] = ((1LL*(MOD - (MOD/i))%MOD) * (1LL*inv[MOD%i]%MOD))%MOD;	
	return;
}

void solve(int T)
{
	ll n;
	cin>>n;
	ll res = 0;
	ll af = sqrtl(n);
	ll rf = 0;
	for(ll i=2;i<=af;i=rf+1)
	{
		rf = sqrtl(n/(n/(i*i)));
		ll k1 = ((((((((rf%MOD) * ((rf+1)%MOD))%MOD) * ((2*rf+1)%MOD))%MOD) * (inv[6]%MOD))%MOD) - (((((((i%MOD) * ((i-1)%MOD))%MOD) * ((2*i-1)%MOD))%MOD) * (inv[6]%MOD))%MOD) + MOD)%MOD;
		res = ((res%MOD) + (((k1%MOD) * ((n/(i*i))%MOD))%MOD))%MOD;
	}
	for(int j=3;j<60;j++)
	{
		if(mu[j] != 0)
		{
			// cout<<j<<" "<<mu[j]<<"\n";
			ll xf = 0;
			ll vt = (ll)pow(n, 1.0/(ld)j);
			for(ll i=2;i<=vt;i++)
			xf = ((xf%MOD) + ((((n/fexp(i, j))%MOD) * (fexp(i, j)%MOD))%MOD))%MOD;
			if(mu[j] == -1)
			res = ((res%MOD) + (xf%MOD))%MOD;
			else res = ((res%MOD) - (xf%MOD) + MOD)%MOD;	
		}
	}
	res = ((res%MOD) + (n%MOD))%MOD;
	cout<<res<<"\n";
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

	mob_sling();
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