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

const int MOD = 998244353;

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
ll arr[MV], factx[MV], inv[MV], invf[MV];
bool isP[32000000];
VL px;

void factup(void)
{
	factx[0] = 1; factx[1] = 1;
	inv[1] = 1;
	invf[0] = 1; invf[1] = 1;
	for(ll i=2;i<MV;i++)
	{
		factx[i] = ((1LL*i%MOD) * (1LL*factx[i-1]%MOD))%MOD;
		inv[i] = ((1LL*(MOD - (MOD/i))%MOD) * (1LL*inv[MOD%i]%MOD))%MOD;
		invf[i] = ((1LL*inv[i]%MOD) * (1LL*invf[i-1]%MOD))%MOD;
	}
	return;
}

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(int p=2;p*p<32000000;p++)
	{
		if(isP[p])
		{
			for(int i=p*p;i<32000000;i+=p)
			isP[i] = 0;	
		}	
	}
	for(int i=2;i<32000000;i++)
	{
		if(isP[i])
		px.pb(i);	
	}	
	return;
}

void solve(int T)
{
	ll D;
	cin>>D;
	VL adf;
	for(auto &&u : px)
	{
		if(!(D % u))
		{	
			while(!(D % u))
			D /= u;
			adf.pb(u);
		}		
	}
	if(D > 1)
	adf.pb(D);	
	int q;
	cin>>q;
	while(q--)
	{
		ll v,u;
		cin>>v>>u;
		ll gc = __gcd(v, u);
		ll g1 = v/gc;
		ll g2 = u/gc;
		ll df1 = 1, df2 = 1;
		ll c1 = 0, c2 = 0;
		for(auto &&u : adf)
		{
			if((g1 == 1) && (g2 == 1))
			break;
			ll cx1 = 0, cx2 = 0;
			while(!(g1 % u))
			{
				g1 /= u;
				cx1++;
			}
			while(!(g2 % u))
			{
				g2 /= u;
				cx2++;
			}
			df1 = ((df1%MOD) * (invf[cx1]%MOD))%MOD;
			df2 = ((df2%MOD) * (invf[cx2]%MOD))%MOD;
			c1 += cx1;
			c2 += cx2;
		}
		if(g1 > 1)
		c1++;
		if(g2 > 1)
		c2++;
		df1 = ((df1%MOD) * (factx[c1]%MOD))%MOD;
		df2 = ((df2%MOD) * (factx[c2]%MOD))%MOD;
		cout<<(((df1%MOD) * (df2%MOD))%MOD)<<"\n";	
	}
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

	factup();
	siever();
	//cin>>T;
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