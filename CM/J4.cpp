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

int ar[MV];
ll bt[MV][16];
ll xfd[1001][1001], memo[2][1001];
ll arr[MV];

// ll xd(int n, int k)
// {
// 	if(k < 0)
// 	return INF;	
// 	if(!n)
// 	{
// 		if(!k)
// 		return 0;
// 		else return INF;	
// 	}	
// 	if(memo[n][k] != -1)
// 	return memo[n][k];
// 	ll ans = INF;
// 	for(int x=n-1;x>0;x--)
// 	ans = min(ans, xfd[x][n] + xd(x-1, k-1));
// 	ans = min(ans, xd(n-1, k-1));
// 	memo[n][k] = ans;
// 	return ans;	
// }

void dc_dpcmp(int l, int r, int optl, int optr)
{
	if(l > r)
	return;
	int mid = ((l + r) >> 1);
	PLL bval = {INF, -1};
	for(int k=optl;k<=min(mid, optr);k++)
	bval = min(bval, {memo[0][k-1] + xfd[k][mid], k});
	memo[1][mid] = bval.ff;
	int opt = bval.ss;
	dc_dpcmp(l, mid-1, optl, opt);
	dc_dpcmp(mid+1, r, opt, optr);
	return;	
}

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int vx;
		cin>>vx;
		for(int j=0;j<16;j++)
		bt[i][j] = bt[i-1][j] + !!(vx & (1<<j));
	}
	for(int i=n;i>0;i--)
	{
		xfd[i][i] = 0;
		for(int j=i-1;j>0;j--)
		{
			for(int x=0;x<16;x++)
			xfd[j][i] += ((1LL*(bt[i][x] - bt[j-1][x]) * (1LL*(i-j+1) - bt[i][x] + bt[j-1][x])) * (1LL<<x));
		}
	}
	for(int i=1;i<=n;i++)
	memo[0][i] = xfd[1][i];
	for(int i=2;i<=k;i++)
	{
		dc_dpcmp(i, n, i, n);
		for(int j=1;j<=n;j++)
		memo[0][j] = memo[1][j];
	}	
	cout<<memo[0][n]<<"\n";
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