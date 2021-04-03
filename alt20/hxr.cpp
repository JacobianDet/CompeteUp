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
ll arr[MV], aas[MV];
PLL axd[MV];
bitset<501> rx[501], cx[501], zrx[501], zcx[501], trx[501], tcx[501];

void MATMUL(int n, int mk)
{
	for(int i=0;i<n;i++)
	{
		trx[i].reset();
		tcx[i].reset();
	}
	if(!mk)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				trx[i][j] = ((rx[i] & cx[j]).count()) & 1;
				tcx[j][i] = ((rx[i] & cx[j]).count()) & 1;
			}		
		}
		for(int i=0;i<n;i++)
		{
			rx[i] = trx[i];
			cx[i] = tcx[i];				
		}	
	}	
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				trx[i][j] = ((zrx[i] & cx[j]).count()) & 1;
				tcx[j][i] = ((zrx[i] & cx[j]).count()) & 1;
			}		
		}
		for(int i=0;i<n;i++)
		{
			zrx[i] = trx[i];
			zcx[i] = tcx[i];				
		}
	}
	return;
}

void modexp(ll n, ll k)
{
	for(int i=0;i<n;i++)
	{
		zrx[i].reset();
		zcx[i].reset();
		zrx[i][i] = 1;
		zcx[i][i] = 1;
	}	
	while(k)
	{
		if(k & 1)
		MATMUL(n, 1);
		MATMUL(n, 0);
		k >>= 1;
	}
	for(int i=0;i<n;i++)
	{
		rx[i] = zrx[i];
		cx[i] = zcx[i];
	}
	return;	
}

void solve(int T)
{
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++)
	{	
		aas[i] = 0;
		rx[i].reset();
		cx[i].reset();
		cin>>axd[i].ff>>axd[i].ss;
		axd[i].ff--; axd[i].ss--;
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=axd[i].ff;j<=axd[i].ss;j++)
		{
			rx[i][j] = 1;
			cx[j][i] = 1;
		}		
	}
	modexp(n, k-1);
	for(int i=0;i<60;i++)
	{
		bitset<501> zb;
		zb.reset();
		for(int j=0;j<n;j++)
		zb[j] = !!(arr[j] & (1LL<<i));
		for(int j=0;j<n;j++)
		{
			if(((rx[j] & zb).count() & 1))
			aas[j] |= (1LL<<i);	
		}	
	}
	for(int i=0;i<n;i++)
	cout<<aas[i]<<" \n"[i==n-1];
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