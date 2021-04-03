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
const int MOF = 1000000006;

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
ll arr[MV], tx[5][5], res[5][5];

void MATMUL(int mk)
{
	ll tp[5][5];
	memset(tp, 0, sizeof(tp));
	if(!mk)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				for(int k=0;k<5;k++)
				tp[i][j] = ((tp[i][j]%MOF) + (((tx[i][k]%MOF) * (tx[k][j]%MOF))%MOF))%MOF;	
			}	
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			tx[i][j] = tp[i][j];
		}	
	}
	else
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				for(int k=0;k<5;k++)
				tp[i][j] = ((tp[i][j]%MOF) + (((res[i][k]%MOF) * (tx[k][j]%MOF))%MOF))%MOF;	
			}	
		}
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			res[i][j] = tp[i][j];
		}
	}
	return;		
}

void modexp(ll n)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		res[i][j] = (i == j);	
	}	
	while(n)
	{
		if(n & 1)
		MATMUL(1);
		MATMUL(0);
		n >>= 1;	
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		tx[i][j] = res[i][j];	
	}	
	return;
}

ll mexp(ll a, ll n)
{
	ll re = 1;
	while(n)
	{
		if(n & 1)
		re = ((re%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return re;
}

void solve(int T)
{
	ll n,f1,f2,f3,c;
	cin>>n>>f1>>f2>>f3>>c;
	tx[0][0] = 1;
	tx[0][1] = 1;
	tx[0][2] = 1;
	tx[0][3] = 2;
	tx[0][4] = (MOF - 6)%MOF;
	tx[1][0] = 1;
	tx[1][1] = 0;
	tx[1][2] = 0;
	tx[1][3] = 0;
	tx[1][4] = 0;
	tx[2][0] = 0;
	tx[2][1] = 1;
	tx[2][2] = 0;
	tx[2][3] = 0;
	tx[2][4] = 0;
	tx[3][0] = 0;
	tx[3][1] = 0;
	tx[3][2] = 0;
	tx[3][3] = 1;
	tx[3][4] = 1;
	tx[4][0] = 0;
	tx[4][1] = 0;
	tx[4][2] = 0;
	tx[4][3] = 0;
	tx[4][4] = 1;
	modexp(n-3);
	ll tz = 1;
	tz = ((tz%MOD) * (mexp(f3, tx[0][0])%MOD))%MOD;
	tz = ((tz%MOD) * (mexp(f2, tx[0][1])%MOD))%MOD;
	tz = ((tz%MOD) * (mexp(f1, tx[0][2])%MOD))%MOD;
	tz = ((tz%MOD) * (mexp(c, ((4%MOF) * (tx[0][3]%MOF))%MOF)%MOD))%MOD;
	tz = ((tz%MOD) * (mexp(c, tx[0][4])%MOD))%MOD;
	cout<<tz<<"\n";
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