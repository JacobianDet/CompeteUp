#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 2000001
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

int ar[MV];
ll G[101][101], res[101][101], tp[101][101];
ll arr[MV];

void MATMUL(int ix, int n)
{
	memset(tp, 0, sizeof(tp));
	if(!ix)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ll xs = 0;
				for(int k=1;k<=n;k++)
				xs = ((xs%MOD) + (((res[i][k]%MOD) * (G[k][j]%MOD))%MOD))%MOD;
				tp[i][j] = xs;
 			}	
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			res[i][j] = tp[i][j];	
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ll xs = 0;
				for(int k=1;k<=n;k++)
				xs = ((xs%MOD) + (((G[i][k]%MOD) * (G[k][j]%MOD))%MOD))%MOD;
				tp[i][j] = xs;
 			}	
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			G[i][j] = tp[i][j];	
		}
	}
	return;	
}

void modexp(int n, ll k)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i == j)
			res[i][j] = 1;
			else res[i][j] = 0;	
		}	
	}
	while(k)
	{
		if(k & 1)
		MATMUL(0, n);
		MATMUL(1, n);
		k >>= 1;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		G[i][j] = res[i][j];	
	}
	return;
}

ll mer(ll a, ll n)
{
	ll rx = 1;
	while(n)
	{
		if(n & 1)
		rx = ((rx%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1; 	
	}
	return rx;
}

void solve(int T)
{
	int n,m;
	ll k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	memset(G, 0, sizeof(G));
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s][d]++;
	}	
	for(int i=1;i<=n;i++)
	{
		ll sx = 0;
		for(int j=1;j<=n;j++)
		sx = ((sx%MOD) + (G[i][j]%MOD))%MOD;
		sx = mer(sx, MOD-2)%MOD;
		for(int j=1;j<=n;j++)
		G[i][j] = ((G[i][j]%MOD) * (sx%MOD))%MOD;	
	}
	modexp(n, k);
	for(int i=1;i<=n;i++)
	{
		ll kx = 0, sx = 0;
		for(int j=1;j<=n;j++)
		kx = ((kx%MOD) + (((G[i][j]%MOD) * (arr[j]%MOD))%MOD))%MOD;
		cout<<kx<<" ";
	}
	cout<<"\n";
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