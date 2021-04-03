#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 4000001
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

const int MOD = 1<<30;

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

ll lo[MV], prx[MV], psx[MV];
VI px;

void siever(void)
{
	lo[1] = 1;
	prx[1] = 1;	
	psx[1] = 1;
	for(int i=2;i<MV;i++)
	{
		if(!lo[i])
		{
			lo[i] = i;
			px.pb(i);
		}	
		for(int j=0;((j<(int)px.sz()) && (px[j]<=lo[i]) && ((i*px[j])<MV));j++)
		lo[i*px[j]] = px[j];	
	}	
	for(int i=2;i<MV;i++)
	{
		if(lo[i/lo[i]] == lo[i])
		{
			int j = i/lo[i];
			if(lo[j/lo[j]] == lo[i])
			prx[i] = 0;
			else prx[i] = ((prx[j/lo[j]]%MOD) * ((MOD - lo[i])%MOD))%MOD;	
		}	
		else prx[i] = ((prx[i/lo[i]]%MOD) * ((MOD - lo[i] + 1)%MOD))%MOD;
		psx[i] = ((psx[i-1]%MOD) + (((i%MOD) * (prx[i]%MOD))%MOD))%MOD;
	}
	return;	
}

void solve(int T)
{
	ll a,b;
	cin>>a>>b;
	ll res = 0;
	for(int i=1,la;i<=min(a,b);i=la+1)
	{
		la = min((a/(a/i)), (b/(b/i)));
		ll vf1 = ((psx[la]%MOD) - (psx[i-1]%MOD) + MOD)%MOD;
		ll vf2 = ((!((a/i) & 1)) ? (((a/i)/2) * ((a/i)+1)) : ((a/i) * (((a/i)+1)/2)));
		vf2 %= MOD;
		ll vf3 = ((!((b/i) & 1)) ? (((b/i)/2) * ((b/i)+1)) : ((b/i) * (((b/i)+1)/2)));
		res = ((res%MOD) + (((((vf1%MOD) * (vf2%MOD))%MOD) * (vf3%MOD))%MOD))%MOD;
	}
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

	siever();
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