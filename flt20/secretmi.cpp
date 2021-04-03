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

int ar[MV];
ll arr[MV];
vector<PII> G[MV];
int dist[201][201], dd[201][201];

void dijkstra_find(int s, int n)
{
	for(int i=1;i<=n;i++)
	dist[s][i] = MOD;
	priority_queue<PII, vector<PII>, greater<PII> > P;
	P.push({0, s});
	dist[s][s] = 0;
	while(!P.empty())
	{
		PII px = P.top();
		P.pop();
		for(auto u : G[px.ss])
		{
			if(dist[s][u.ff] > u.ss + dist[s][px.ss])
			{
				dist[s][u.ff] = u.ss + dist[s][px.ss];
				P.push({dist[s][u.ff], u.ff});
			}	
		}	
	}
	return;	
}

void solve(int T)
{
	int n,m,l;
	cin>>n>>m>>l;
	for(int i=0;i<l;i++)
	cin>>ar[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		dd[i][j] = MOD;	
	}
	for(int i=1;i<=n;i++)
	dd[i][i] = 0;	
	for(int i=0;i<m;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		G[s].pb({d, w});
		G[d].pb({s, w});
		dd[s][d] = min(dd[s][d], w);
		dd[d][s] = min(dd[d][s], w);
	}	
	for(int i=1;i<=n;i++)
	dijkstra_find(i, n);
	bool ok = 1;
	for(int i=1;i<l;i++)
	{
		if(dd[ar[i-1]][ar[i]] != dist[ar[i-1]][ar[i]])
		{
			ok = 0;
			break;
		}	
	}	
	if(!ok)
	cout<<"-1\n";
	else
	{	
		int pt = ar[0], ct = 1, dst = 0;
		for(int i=1;i<l;i++)
		{
			dst += dd[ar[i-1]][ar[i]];
			if(dist[pt][ar[i]] == dst)
			continue;
			else
			{
				pt = ar[i-1];
				dst = dd[ar[i-1]][ar[i]];
				ct++;
			}	
		}
		cout<<ct+1<<"\n";
	}	
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