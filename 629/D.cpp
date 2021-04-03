#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 200005
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
ll arr[MV];
int memo[MV][3][8], vis[MV][3][8];
PII par[MV][3][8];
int n;

int xd(int ix, int pv, int mask, int T)
{
	if(ix == n)
	return __builtin_popcount(mask);
	else if(vis[ix][pv][mask] == T)
	return memo[ix][pv][mask];
	int ans = 4;
	if(!ix)
	{
		ans = xd(ix+1, 0, mask | (1<<0), T);
		par[ix][pv][mask] = {0, mask | (1<<0)};
	}	
	else if(ix < n-1)
	{
		ans = min(ans, xd(ix+1, pv ^ 1, mask | (1<<(pv ^ 1)), T));
		par[ix][pv][mask] = {pv ^ 1, mask | (1<<(pv ^ 1))};
		if(ar[ix-1] == ar[ix])
		{
			if(ans > xd(ix+1, pv, mask | (1<<pv), T))
			{
				ans = xd(ix+1, pv, mask | (1<<pv), T);
				par[ix][pv][mask] = {pv, mask | (1<<pv)};
			}	
		}	
	}
	else
	{
		if(ar[ix-1] == ar[ix])
		{
			if(!pv)
			{	
				ans = min(ans, xd(ix+1, pv ^ 1, mask | (1<<(pv ^ 1)), T));
				par[ix][pv][mask] = {pv ^ 1, mask | (1<<(pv ^ 1))};
			}	
			else 
			{
				ans = min(ans, xd(ix+1, pv, mask | (1<<pv), T));
				par[ix][pv][mask] = {pv, mask | (1<<pv)};
			}		
		}
		else
		{
			if(pv)
			{
				ans = min(ans, xd(ix+1, 2, mask | (1<<2), T));
				par[ix][pv][mask] = {2, mask | (1<<2)};
				if(ar[ix] == ar[0])
				{
					ans = min(ans, xd(ix+1, pv ^ 1, mask | (1<<(pv ^ 1)), T));
					par[ix][pv][mask] = {pv ^ 1, mask | (1<<(pv ^ 1))};
				}	
			}	
			else
			{
				ans = min(ans, xd(ix+1, pv ^ 1, mask | (1<<(pv ^ 1)), T));
				par[ix][pv][mask] = {pv ^ 1, mask | (1<<(pv ^ 1))};
			}		
		}
	}
	memo[ix][pv][mask] = ans;
	vis[ix][pv][mask] = T;
	return ans;	
}

void solve(int T)
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	int x = 1;
	for(int i=1;i<n;i++)
	{
		if(ar[i-1] != ar[i])
		{
			x = 0;
			break;
		}	
	}
	if(x == 1)
	{
		cout<<"1\n";
		for(int i=0;i<n;i++)
		cout<<"1 ";
		cout<<"\n";	
	}	
	else if(!(n & 1))
	{
		cout<<"2\n";
		for(int i=0;i<n;i++)
		{
			if(i & 1)
			cout<<"2 ";
			else cout<<"1 ";	
		}	
		cout<<"\n";
	}	
	else
	{
		int ans = xd(0, 0, 0, T);
		cout<<ans<<"\n";
		int cix = 0, civ = 0, cmask = 0;
		while(cix < n)
		{
			int nix = cix+1;
			int niv = par[cix][civ][cmask].ff;
			int nmask = par[cix][civ][cmask].ss;
			cout<<niv+1<<" ";
			cix = nix;
			civ = niv;
			cmask = nmask;
		}
		cout<<"\n";
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

	memset(vis, -1, sizeof(vis));
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