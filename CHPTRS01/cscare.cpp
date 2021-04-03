#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 300001
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

int ar1[MV], ar2[MV], lcp[MV];
ll arr[MV];

void solve(int T)
{
	int x;
	cin>>x;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ar1[i];
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	cin>>ar2[i];	
	if(n == 1)
	{
		int sx = 0;
		for(int i=0;i<m;i++)
		{
			if(abs(ar1[i] - ar2[0]) <= x)
			sx++;	
		}	
		cout<<sx<<"\n";
	}
	else
	{
		int sx = 0;
		VI df;
		for(int i=0;i<n-1;i++)
		df.pb(ar1[i] - ar1[i+1]);
		df.pb(MOD);
		for(int i=0;i<m-1;i++)
		df.pb(ar2[i] - ar2[i+1]);
		for(int i=1;i<n+m-1;i++)
		{
			int j = lcp[i-1];
			while(j && (df[i] != df[j]))
			j = lcp[j-1];
			if(df[i] == df[j])
			j++;
			lcp[i] = j;	
		}
		for(int i=n;i<n+m-1;i++)
		{
			// cout<<df[i]<<" "<<lcp[i]<<"\n";
			if((lcp[i] == n-1) && (abs(ar1[0] - ar2[i-2*n+2]) <= x))
			sx++;
		}
		cout<<sx<<"\n";
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