#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const ll INF = 4e15;

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

ll dist[2][MV];
int dsc[MV], mdsc[MV];
bool vis[MV], bbx[MV];
vector<PLL> G[MV], RG[MV], BG[MV];
PPLL edg[MV];
int tx = 0;

void dijkstra_find(int n, int yt, int mk)
{
	for(int i=1;i<=n;i++)
	{
		dist[mk][i] = INF;
		vis[i] = 0;
	}
	dist[mk][yt] = 0;
	priority_queue<PLL, vector<PLL>, greater<PLL> > P;
	P.push({0, yt});
	while(!P.empty())
	{
		PLL px = P.top();
		ll s = px.ss;
		ll t = px.ff;
		P.pop();
		if(vis[s])
		continue;
		vis[s] = 1;
		if(!mk)
		{
			for(auto e : G[s])
			{	
				ll u = e.ff;
				ll w = e.ss;
				if(dist[mk][u] > dist[mk][s] + w)
				{
					dist[mk][u] = dist[mk][s] + w;
					P.push({dist[mk][u], u});
				}
			}
		}
		else
		{
			for(auto e : RG[s])
			{
				ll u = e.ff;
				ll w = e.ss;
				if(dist[mk][u] > dist[mk][s] + w)
				{
					dist[mk][u] = dist[mk][s] + w;
					P.push({dist[mk][u], u});	
				}	
			}
		}		
	}
	return;
}

void dfs_visit(int s, int p)
{
	vis[s] = 1;
	dsc[s] = mdsc[s] = ++tx;
	int pcn = 0;
	for(auto u : BG[s])
	{
		if((u.ff == p) && (pcn < 1))
		{
			pcn++;
			continue;
		}
		else if(vis[u.ff])
		mdsc[s] = min(mdsc[s], dsc[u.ff]);
		else
		{
			dfs_visit(u.ff, s);
			mdsc[s] = min(mdsc[s], mdsc[u.ff]);
			if(mdsc[u.ff] > dsc[s])
			bbx[u.ss] = 1;	
		}	
	}
	return;
}

void solve(int T)
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	for(int i=0;i<m;i++)
	{
		ll s,d,w;
		cin>>s>>d>>w;
		edg[i] = {{s, d}, w};
		G[s].pb({d, w});
		RG[d].pb({s, w});
	}	
	dijkstra_find(n, a, 0);
	dijkstra_find(n, b, 1);
	for(int i=0;i<m;i++)
	{
		ll s = edg[i].ff.ff;
		ll d = edg[i].ff.ss;
		ll w = edg[i].ss;
		if(dist[0][s] + w + dist[1][d] == dist[0][b])
		{
			BG[s].pb({d, i});
			BG[d].pb({s, i});	
		}
	}
	tx = 0;
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=n;i++)
	{	
		if(!vis[i])
		dfs_visit(i, -1);
	}
	for(int i=0;i<m;i++)
	{
		ll s = edg[i].ff.ff;
		ll d = edg[i].ff.ss;
		ll w = edg[i].ss;
		if(dist[0][s] + w + dist[1][d] == dist[0][b])
		{
			if(bbx[i])
			cout<<"YES\n";
			else if(w > 1)
			cout<<"CAN 1\n";
			else cout<<"NO\n";	
		}
		else
		{
			ll df = dist[0][b] - 1 - dist[1][d] - dist[0][s];
			if(df <= 0)
			cout<<"NO\n";
			else cout<<"CAN "<<(w - df)<<"\n";	
		}
	}	
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