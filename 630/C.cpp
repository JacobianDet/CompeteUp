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

int ar[MV], rk[MV], cv[MV][26];
ll arr[MV];

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);
};

int dsu::root(int x)
{
	return ((x == ar[x]) ? x : (ar[x] = root(ar[x])));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rk[rx] < rk[ry])
	swap(rx, ry);
	ar[ry] = rx;
	if(rk[rx] == rk[ry])
	rk[rx]++;
	for(int i=0;i<26;i++)
	cv[rx][i] += cv[ry][i];
	return;	
}

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	cv[i+1][s[i]-'a']++;
	for(int i=1;i<=n;i++)
	{
		ar[i] = i;
		rk[i] = 0;
	}	
	dsu D;
	for(int i=0;i<=k/2;i++)
	{
		int df = i;
		for(int j=0;j<n/k;j++)
		{
			D.find_union(df+1, i+1+j*k);
			D.find_union(df+1, k-i+j*k);
		}	
	}
	int ts = 0;
	for(int i=0;i<k/2;i++)
	{
		int st = 0, mst = 0;
		for(int j=0;j<26;j++)
		{
			st += cv[i+1][j];
			mst = max(mst, cv[i+1][j]);
		}	
		ts += (st - mst);
	}
	if(k & 1)
	{
		int st = 0, mst = 0;
		for(int j=0;j<26;j++)
		{
			st += cv[k/2+1][j];
			mst = max(mst, cv[k/2+1][j]);
		}
		ts += (st - mst);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		cv[i][j] = 0;	
	}
	cout<<ts<<"\n";
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