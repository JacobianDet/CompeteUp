#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;

int deg[MV];
bool vis[MV];
ll ar[MV];
ll arr[MV];
VI G[MV];

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	ll wt = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		wt += ar[i];
	}	
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		deg[s]++;
		deg[d]++;
	}	
	int st;
	cin>>st;
	queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		if((i != st) && (deg[i] == 1))
		Q.push(i);	
	}	
	ll cur = 0;
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		vis[x] = 1;
		wt -= ar[x];
		cur = max(cur, arr[x] + ar[x]);
		for(auto u : G[x])
		{
			if(!vis[u])
			{
				deg[u]--;
				arr[u] = max(arr[u], arr[x] + ar[x]);
				if((u != st) && (deg[u] == 1))
				Q.push(u);	
			}
		}
	}
	cout<<(wt + cur)<<"\n";
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