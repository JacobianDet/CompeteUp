#include <bits/stdc++.h>
using namespace std;
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

int ar[MV], lvl[MV], par[MV], vis[MV];
ll arr[MV];
MPII VX;
VI G[MV];

struct ffz
{
	PPII gz;
	PII lz;
};

ffz dfs_vis1(int s, int p)
{
	par[s] = p;
	PPII gm={{0,0},0};
	PII h1={0,0}, h2={0,0};
	for(auto u : G[s])
	{
		if(u != p)
		{
			lvl[u] = 1 + lvl[s];
			ffz T = dfs_vis1(u, s);
			if(T.gz.ss > gm.ss)
			gm = T.gz;
			if(T.lz.ff > h1.ff)
			{
				h2 = h1;
				h1 = T.lz;
			}	
			else if((T.lz.ff <= h1.ff) && (T.lz.ff > h2.ff))
			h2 = T.lz;	
		}
	}
	if(gm.ss < (h1.ff + h2.ff))
	{
		gm.ss = h1.ff + h2.ff;
		gm.ff.ff = (!h1.ss ? s : h1.ss);
		gm.ff.ss = (!h2.ss ? s : h2.ss);
	}	
	if(!h1.ss)
	h1.ss = s;
	h1.ff++;
	return {gm, h1};	
}

PII dfs_vis2(int s)
{
	vis[s] = 1;
	PII mx = {0,0};
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			PII tx = dfs_vis2(u);
			if(tx.ff+1 > mx.ff)
			mx = {tx.ff+1, tx.ss};	
		}	
	}
	if(!mx.ss)
	mx.ss = s;
	return mx;	
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		VX[{s, d}] = 1;
		VX[{d, s}] = 1;
		G[s].pb(d);
		G[d].pb(s);
	}	
	ffz D = dfs_vis1(1, 0);
	int a = D.gz.ff.ff, b = D.gz.ff.ss;
	if(lvl[a] < lvl[b])
	swap(a, b);
	VI srx;
	srx.pb(a);
	srx.pb(b);
	while(lvl[a] > lvl[b])
	{
		int p1 = par[a];
		srx.pb(p1);
		VX.erase({p1, a});
		VX.erase({a, p1});
		a = p1;
	}
	while(a != b)
	{
		int p1 = par[a], p2 = par[b];
		VX.erase({p1, a});
		VX.erase({a, p1});
		srx.pb(p1);
		srx.pb(p2);
		a = p1;
		VX.erase({p2, b});
		VX.erase({b, p2});
		b = p2;
	}
	for(int i=1;i<=n;i++)
	G[i].clear();
	for(auto u : VX)
	{
		//cout<<u.ff.ff<<" "<<u.ff.ss<<"\n";
		G[u.ff.ff].pb(u.ff.ss);
	}	
	PII mz = {0,0};
	for(auto u : srx)
	{
		if(!vis[u])
		{
			PII xz = dfs_vis2(u);
			if(mz.ff <= xz.ff)
			mz = xz;	
		}
	}
	cout<<(D.gz.ss + mz.ff)<<"\n"<<D.gz.ff.ff<<" "<<D.gz.ff.ss<<" "<<mz.ss<<"\n";
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