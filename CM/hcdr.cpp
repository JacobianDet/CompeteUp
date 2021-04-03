#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 3000001
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
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], cord[MV], indeg[MV];
ll arr[MV];
VI G[MV], RG[MV];
MPII use;
PII E[MV];
bool vis[MV];
VI SCC[MV];
VI fin;

void dfs_vis1(int s)
{
	vis[s] = 1;
	for(auto u : G[s])
	{
		if(!vis[u])
		dfs_vis1(u);	
	}
	fin.pb(s);
	return;
}

void dfs_vis2(int s, int x)
{
	vis[s] = 1;
	cord[s] = x;
	SCC[x].pb(s);
	for(auto u : RG[s])
	{
		if(!vis[u])
		dfs_vis2(u, x);	
	}
	return;
}

bool bfs_visit(int n)
{
	queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		if(!indeg[i])
		Q.push(i);	
	}	
	bool ok = 1;
	while(!Q.empty())
	{
		int sxz = (int)Q.sz();
		if(sxz > 1)
		{
			ok = 0;
			break;
		}
		for(int i=0;i<sxz;i++)
		{
			int s = Q.front();
			Q.pop();
			for(auto u : G[s])
			{
				indeg[u]--;
				if(!indeg[u])
				Q.push(u);	
			}
		}
	}
	return ok;
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		E[i] = {s, d};
		if(s == d)
		continue;	
		G[s].pb(d);
		RG[d].pb(s);
	}
	memset(vis, 0, sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs_vis1(i);	
	}
	reverse(fin.begin(), fin.end());
	int x = 0;
	memset(vis, 0, sizeof(vis));
	for(auto u : fin)
	{
		if(!vis[u])
		{
			x++;
			dfs_vis2(u, x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		vis[i] = 0;
		RG[i].clear();
	}	
	for(int i=0;i<m;i++)
	{
		int s = cord[E[i].ff], d = cord[E[i].ss];
		if((s == d) || (use.find({s,d}) != use.end()))
		continue;
		use[{s, d}] = 1;
		G[s].pb(d);	
		indeg[d]++;
	}
	bool ok = bfs_visit(x);
	if(ok)
	cout<<"YES\n";
	else cout<<"NO\n";
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