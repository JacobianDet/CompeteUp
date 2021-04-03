#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 300001
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

int ar[MV];
ll arr[MV];
ll in[MV], out[MV], sxz[MV];
VI G[MV];

void dfs_vis1(int s, int p)
{
	in[s] = 0;
	sxz[s] = 0;
	out[s] = 0;
	int lc = 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			lc++;
			dfs_vis1(u, s);
			in[s] += in[u];
		}	
	}
	in[s] += (!lc ? 1 : 0);
	return;
}

void dfs_vis2(int s, int p)
{
	VI chd;
	ll sxm = 0, ssx = 0;
	int lc = 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			chd.pb(u);
			sxm += in[u];
			ssx += in[u] * in[u];
		}
	}
	if((s == 1) && ((int)chd.sz() == 1))
	out[s]++;
	if(!chd.sz())
	{
		sxm += in[s];
		ssx += in[s] * in[s];
	}	
	sxm += out[s];
	ssx += out[s] * out[s];
	sxz[s] = (sxm * sxm - ssx)/2;
	for(auto u : chd)
	{
		out[u] = sxm - in[u];
		dfs_vis2(u, s);
	}	
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	VL ax(n);
	for(auto &&u : ax)
	cin>>u;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_vis1(1, -1);
	dfs_vis2(1, -1);
	VL llz;
	for(int i=1;i<=n;i++)
	{
		//cout<<sxz[i]<<"\n";
		llz.pb(sxz[i]);
	}	
	sort(llz.rbegin(), llz.rend());
	sort(ax.rbegin(), ax.rend());
	ll res = 0;
	for(int i=0;i<n;i++)
	res = ((res%MOD) + (((llz[i]%MOD) * (ax[i]%MOD))%MOD))%MOD;
	cout<<res<<"\n";
	for(int i=1;i<=n;i++)
	G[i].clear();
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