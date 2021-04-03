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
#define mp make_pair
#define ins insert
#define sz size
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

PII NE[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
ll A[1001], B[1001], C[1001], D[1001], E[1001], F[1001];
VL xx, yy;
bool vis[3501][3501];
int gex[3501][3501];

void bfs_visit(int zx, int zy, int n, int m)
{
	queue<PII> Q;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{	
			Q.emp(zx-i, zy-j);
			vis[zx-i][zy-j] = 1;
		}
	}		
	while(!Q.empty())
	{
		PII px = Q.front();
		// whoami(px.ff, px.ss);
		Q.pop();
		for(int i=0;i<4;i++)
		{
			int cx = px.ff + NE[i].ff;
			int cy = px.ss + NE[i].ss;
			if((cx >= 0) && (cx < n) && (cy >= 0) && (cy < m) && !vis[cx][cy] && (~gex[px.ff][px.ss] & (1<<i)))
			{
				vis[cx][cy] = 1;
				Q.emp(cx, cy);
			}
		}		
	}
	return;
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		A[i] = a;
		B[i] = b;
		C[i] = c;
		xx.pb(a);
		xx.pb(b);
		yy.pb(c);
	}	
	for(int i=0;i<m;i++)
	{
		ll d,e,f;
		cin>>d>>e>>f;
		D[i] = d;
		E[i] = e;
		F[i] = f;
		xx.pb(d);
		yy.pb(e);
		yy.pb(f);
	}
	xx.pb(-MOD);
	xx.pb(MOD);
	xx.pb(0);
	yy.pb(-MOD);
	yy.pb(MOD);
	yy.pb(0);
	sort(begin(xx), end(xx));
	sort(begin(yy), end(yy));
	xx.resize(unique(begin(xx), end(xx)) - begin(xx));
	yy.resize(unique(begin(yy), end(yy)) - begin(yy));
	for(int i=0;i<n;i++)
	{
		int a = lower_bound(begin(xx), end(xx), A[i]) - begin(xx);
		int b = lower_bound(begin(xx), end(xx), B[i]) - begin(xx);
		int c = lower_bound(begin(yy), end(yy), C[i]) - begin(yy);
		// whoami(a, b, c);
		for(int j=a;j<b;j++)
		{	
			gex[j][c] |= (1<<2);
			gex[j][c-1] |= (1<<0);
		}		
	}
	for(int i=0;i<m;i++)
	{
		int d = lower_bound(begin(xx), end(xx), D[i]) - begin(xx);
		int e = lower_bound(begin(yy), end(yy), E[i]) - begin(yy);
		int f = lower_bound(begin(yy), end(yy), F[i]) - begin(yy);
		for(int j=e;j<f;j++)
		{	
			gex[d][j] |= (1<<3);
			gex[d-1][j] |= (1<<1);
		}		
	}
	n = (int)xx.sz();
	m = (int)yy.sz();	
	int zx = lower_bound(begin(xx), end(xx), 0) - begin(xx);
	int zy = lower_bound(begin(yy), end(yy), 0) - begin(yy);
	bfs_visit(zx, zy, n, m);
	for(int i=0;i<n;i++)
	{
		if(vis[i][0] || vis[i][m-1])
		{
			cout<<"INF\n";
			return;
		}	
	}
	for(int i=0;i<m;i++)
	{
		if(vis[0][i] || vis[n-1][i])
		{
			cout<<"INF\n";
			return;
		}	
	}	
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j])
			ans += (xx[i+1] - xx[i]) * (yy[j+1] - yy[j]);	
		}	
	}
	cout<<ans<<"\n";
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