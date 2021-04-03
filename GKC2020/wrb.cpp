#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 500001
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
ld lg2[MV];

void lggr(void)
{
	lg2[0] = 0;
	lg2[1] = 0;
	for(int i=2;i<MV;i++)
	lg2[i] = lg2[i-1] + log2l((ld)i);
	return;	
}

// int vis[305][305];
// ld memo[305][305];

// ld xd(int ix, int jx, int h, int w, int l, int u, int r, int d, int T)
// {
// 	if((ix >= u) && (ix <= d) && (jx >= l) && (jx <= r))
// 	return 0;
// 	else if((ix == h) && (jx == w))
// 	return 1;
// 	if(vis[ix][jx] == T)
// 	return memo[ix][jx];
// 	ld ans = 0;
// 	if((ix + 1 <= h) && (jx + 1 <= w))
// 	ans = 0.5*xd(ix+1, jx, h, w, l, u, r, d, T) + 0.5*xd(ix, jx+1, h, w, l, u, r, d, T);
// 	else if(ix + 1 <= h)
// 	ans = xd(ix+1, jx, h, w, l, u, r, d, T);
// 	else if(jx + 1 <= w)
// 	ans = xd(ix, jx+1, h, w, l, u, r, d, T);
// 	vis[ix][jx] = T;
// 	memo[ix][jx] = ans;
// 	return ans;	
// }

ld cef(int st, int en)
{
	if((st+en-2) < 0)
	return 0;	
	else return pow((ld)2.0, lg2[st+en-2] - lg2[st-1] - lg2[en-1] + (ld)2.0 - st - en);
}

void solve(int T)
{
	int w,h,l,u,r,d;
	cin>>w>>h>>l>>u>>r>>d;
	// ld res = xd(1, 1, h, w, l, u, r, d, T);
	int st = l-1, en = d+1;
	ld res = 0;
	if(en <= h)
	{	
		while(st > 0)
		{
			ld mt = 1.0;
			if(en >= h)
			{	
				mt = 0.5;
				en = h-1;
			}		
			res += mt * cef(st, en);
			st--;
			en++;
		}
	}	
	st = r+1, en = u-1;
	if(st <= w)
	{	
		while(en > 0)
		{
			ld mt = 1.0;
			if(st >= w)
			{	
				mt = 0.5;
				st = w-1;
			}		
			res += mt * cef(st, en);
			st++;
			en--;
		}
	}	
	cout<<"Case #"<<T<<": ";
	SETF();
	cout<<setprecision(10)<<res<<"\n";
	UNSETF();
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	lggr();
	cin>>T;
	for(auto _=1;_<=T;_++)
	solve(_);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}