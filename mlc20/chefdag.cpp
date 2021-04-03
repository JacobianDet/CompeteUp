#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007
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
//ordered_set = order_by_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

using pau = pair<pair<pair<ll, ll>, ll>, ll>;

int ar[MV], tv[MV], indeg[MV], tz[MV], sze[MV];
ll arr[MV];
vector<VI> tst;
set<pau> FD[MV];
VI G[MV];

void solve(int T)
{
	tst.clear();
	int n,k;
	cin>>n>>k;
	tst.resize(k, VI(n));
	for(int i=1;i<=n;i++)
	tz[i] = 0;
	int tx;
	for(auto &&u1 : tst)
	{
		tx = 0;
		for(auto &&u2 : u1)
		{
			cin>>u2;
			tz[u2] = max(tz[u2], ++tx);
		}		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		ar[j] = 1;
		ar[i] = 0;	
		for(auto &&u1 : tst)
		{
			bool ok = 0;
			for(auto &&u2 : u1)
			{
				if(!ok)
				ar[u2] = 0;	
				if(u2 == i)
				ok = 1;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(ar[j])
			tv[j]++;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		ar[j] = 1;
		ar[i] = 0;	
		for(auto &&u1 : tst)
		{
			bool ok = 0;
			for(auto &&u2 : u1)
			{
				if(!ok)
				ar[u2] = 0;	
				if(u2 == i)
				ok = 1;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(ar[j])
			FD[i].ins({{{indeg[j], tv[j]}, tz[j]}, j});
		}
		sze[i] = (int)FD[i].sz();	
	}
	iota(ar, ar+n+1, 0);
	sort(ar+1, ar+n+1, [](int A, int B){ return ((sze[A] < sze[B]) || ((sze[A] == sze[B]) && (tz[A] < tz[B]))); });
	for(int i=1;i<=n;i++)
	{
		int u = ar[i];
		if((int)FD[u].sz() > 0)
		{
			pau px = *FD[u].begin();
			indeg[px.ss]++;
			for(auto &&v : FD[u])
			tv[v.ss]--;	
			G[u].pb(px.ss);
			// cout<<u<<" "<<px.ss<<"\n";
			for(int j=1;j<=n;j++)
			{
				if(FD[j].find(px) != FD[j].end())
				{	
					if(indeg[px.ss] == 1)
					sze[j]--;	
					FD[j].erase(px);
					FD[j].ins({{{indeg[px.ss], tv[px.ss]}, tz[px.ss]}, px.ss});
				}	
			}	
		}
		if(i < n)
		sort(ar+i+1, ar+n+1, [](int A, int B){ return ((sze[A] < sze[B]) || ((sze[A] == sze[B]) && (tz[A] < tz[B]))); });
	}
	for(int i=1;i<=n;i++)
	FD[i].clear();	
	int ic = 0;
	for(int i=1;i<=n;i++)
	{
		if(!indeg[i])
		ic++;	
	}	
	cout<<ic<<"\n";
	for(int i=1;i<=n;i++)
	{
		if(!((int)G[i].sz()))
		cout<<"0 ";
		else cout<<G[i][0]<<" ";	
	}
	cout<<"\n";
	for(int i=1;i<=n;i++)
	{	
		sze[i] = 0;
		tv[i] = 0;
		indeg[i] = 0;
		ar[i] = 0;
		G[i].clear();
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