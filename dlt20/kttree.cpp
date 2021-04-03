#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 100001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()
#define whoami(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); whi(_it, args); }

void whi(istream_iterator<string> it) { cerr<<"\n"; }

template<typename T, typename... Args>
void whi(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" "<<a<<" "; whi(++it, args...); }

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

const int MOD = 998244353;
const ll INF = 4e18;

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

int ar[MV], col[MV], rk[MV], cmp[MV], sze[MV], ecs[MV][12], mrk[MV], memo[2][(1<<11)];

int n,k;

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
	sze[rx] += sze[ry];
	for(int i=0;i<=k;i++)
	ecs[rx][i] += ecs[ry][i];	
	if(rk[rx] == rk[ry])
	rk[rx]++;
	return;	
}

// int xd(int vn, int mask, int T)
// {
// 	// whoami(cmp[vn], mask);
// 	if(!mask)
// 	return 1;
// 	else if(!vn)
// 	return 0;	
// 	if(vis[vn][mask] == T)
// 	return memo[vn][mask];
// 	int ans = xd(vn-1, mask, T)%MOD;
// 	int nm = mask & mrk[cmp[vn]];
// 	for(int u = __builtin_ctz(nm);(nm > 0);(nm ^= (1<<u)), u = __builtin_ctz(nm))
// 	ans = (((1LL*ans)%MOD) + ((((1LL*xd(vn-1, mask ^ (1<<u), T))%MOD) * ((1LL*ecs[cmp[vn]][u+1])%MOD))%MOD))%MOD;
// 	vis[vn][mask] = T;
// 	memo[vn][mask] = ans;
// 	return ans;
// }

void solve(int T)
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>col[i];
		ar[i] = i;
		rk[i] = 0;
		sze[i] = 1;
		mrk[i] = 0;
		for(int j=0;j<=k;j++)
		ecs[i][j] = 0;
		ecs[i][col[i]]++;	
	}	
	dsu D;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		if(col[s] && col[d])
		D.find_union(s, d);	
	}
	VI cmt;	
	for(int i=1;i<=n;i++)
	{
		if(ar[i] == i)
		cmt.pb(i);	
	}
	int yt = 0;
	for(auto &&u : cmt)
	{
		if((sze[u] > 1) || col[u])
		{
			cmp[++yt] = u;	
			for(int i=1;i<=k;i++)
			{	
				if(ecs[u][i])
				mrk[u] |= (1<<(i-1));
			}		
		}		
	}
	n = yt;
	// int ans = xd(n, ((1<<k)-1), T)%MOD;
	// cout<<ans<<"\n";
	memo[0][0] = 1;
	memo[1][0] = 0;
	for(int mask=1;mask<(1<<k);mask++)
	{
		memo[0][mask] = 0;
		memo[1][mask] = 0;
	}	
	for(int i=1;i<=n;i++)
	{
		for(int mask=0;mask<(1<<k);mask++)
		{
			memo[1][mask] = ((1LL*memo[1][mask]%MOD) + (1LL*memo[0][mask]%MOD))%MOD;
			int nm = mask & mrk[cmp[i]];
			for(int u = __builtin_ctz(nm);(nm > 0);(nm ^= (1<<u)), u = __builtin_ctz(nm))
			memo[1][mask] = ((1LL*memo[1][mask]%MOD) + (((1LL*memo[0][mask ^ (1<<u)]%MOD) * (1LL*ecs[cmp[i]][u+1]%MOD))%MOD))%MOD;	
		}
		for(int mask=0;mask<(1<<k);mask++)
		{
			memo[0][mask] = memo[1][mask];
			memo[1][mask] = 0;
		}	
	}	
	cout<<memo[0][(1<<k)-1]<<"\n";
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

	// memset(vis, -1, sizeof(vis));
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