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

int ar[2][MV], indeg[2][MV];
ll arr[MV];
VI G[MV];

void bfs_vis1(int n)
{
	priority_queue<int> Q;
	for(int i=n;i>0;i--)
	{
		if(!indeg[0][i])
		Q.push(i);	
	}
	int vx = 1;
	while(!Q.empty())
	{
		int s = Q.top();
		Q.pop();
		// cout<<s<<" ";
		ar[0][s] = vx;
		vx++;
		VI gf;
		for(auto u : G[s])
		gf.pb(u);
		reverse(gf.begin(), gf.end());
		for(auto u : gf)
		{
			indeg[0][u]--;
			if(!indeg[0][u])
			Q.push(u);
		}
	}
	return;
}

void bfs_vis2(int n)
{
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i=1;i<=n;i++)
	{
		if(!indeg[1][i])
		Q.push(i);	
	}
	int vx = 1;
	while(!Q.empty())
	{
		int s = Q.top();
		Q.pop();
		// cout<<s<<" ";
		ar[1][s] = vx;
		vx++;
		VI gf;
		for(auto u : G[s])
		gf.pb(u);
		// reverse(gf.begin(), gf.end());
		for(auto u : gf)
		{
			indeg[1][u]--;
			if(!indeg[1][u])
			Q.push(u);
		}
	}
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<(int)s.sz();i++)
	{
		if(s[i] == '<')
		{
			indeg[0][(i+2)]++;
			indeg[1][(i+2)]++;
			G[(i+1)].pb((i+2));
		}	
		else
		{
			indeg[0][(i+1)]++;
			indeg[1][(i+1)]++;
			G[(i+2)].pb((i+1));
		}	
	}
	bfs_vis1(n);
	bfs_vis2(n);
	// for(int i=0;i<2;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	cout<<indeg[i][j]<<" ";
	// 	cout<<"\n";	
	// }	
	for(int i=1;i<=n;i++)
	{
		indeg[0][i] = 0;
		indeg[1][i] = 0;
		G[i].clear();
	}	
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<ar[i][j]<<" \n"[j == n];
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