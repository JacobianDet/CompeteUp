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

// int readInt (void) {
// 	bool minus = false;
// 	int result = 0;
// 	char ch;
// 	ch = getchar_unlocked();
// 	while (true) {
// 		if (ch == '-') break;
// 		if (ch >= '0' && ch <= '9') break;
// 		ch = getchar_unlocked();
// 	}
// 	if (ch == '-') minus = true; else result = ch-'0';
// 	while (true) {
// 		ch = getchar_unlocked();
// 		if (ch < '0' || ch > '9') break;
// 		result = result*10 + (ch - '0');
// 	}
// 	if (minus)
// 		return -result;
// 	else
// 		return result;
// }

int ar[5020];
// int arr[MV];
int memo[2][5020], xfd[5020][5020];

void dc_dpcmp(int l, int r, int optl, int optr)
{
	if(l > r)
	return;
	int mid = ((l + r) >> 1);
	PII bval = {INT_MAX, -1};
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
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	scanf("%d", &ar[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(ar[i] > ar[j])
			xfd[i][j]++;
			xfd[i][j] += xfd[i][j-1];	
		}	
	}	
	for(int j=1;j<=n;j++)
	{
		for(int i=j-1;i>0;i--)
		xfd[i][j] += xfd[i+1][j];	
	}
	for(int i=1;i<=n;i++)
	memo[0][i] = xfd[1][i];	
	for(int i=2;i<=k;i++)
	{
		dc_dpcmp(i, n, i, n);
		for(int j=1;j<=n;j++)
		memo[0][j] = memo[1][j];	
	}	
	printf("%d\n", memo[0][n]);
	return;
}

int main(void)
{
	// FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	while(T--)
	solve(T);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}