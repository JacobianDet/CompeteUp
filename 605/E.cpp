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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV], odl[MV], edl[MV];
ll arr[MV];
VI G[MV];

void bfs_visit(int n)
{
	for(int i=1;i<=n;i++)
	{
		odl[i] = MOD;
		edl[i] = MOD;
	}	
	queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		if(ar[i] & 1)
		{
			odl[i] = 0;
			Q.push(i);
		}	
	}
	while(!Q.empty())
	{
		int s = Q.front();
		Q.pop();
		for(auto u : G[s])
		{
			if(odl[u] > odl[s] + 1)
			{
				odl[u] = odl[s] + 1;
				Q.push(u);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!(ar[i] & 1))
		{
			edl[i] = 0;
			Q.push(i);
		}
	}
	while(!Q.empty())
	{
		int s = Q.front();
		Q.pop();
		for(auto u : G[s])
		{
			if(edl[u] > edl[s] + 1)
			{
				edl[u] = edl[s] + 1;
				Q.push(u);
			}
		}
	}
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	for(int i=1;i<=n;i++)
	{
		if(i - ar[i] >= 1)
		G[i - ar[i]].pb(i);
		if(i + ar[i] <= n)
		G[i + ar[i]].pb(i);	
	}	
	bfs_visit(n);
	for(int i=1;i<=n;i++)
	{
		if(odl[i] == MOD)
		odl[i] = -1;
		if(edl[i] == MOD)
		edl[i] = -1;
		cout<<((ar[i] & 1) ? edl[i] : odl[i])<<" "; 	
	}
	cout<<"\n";
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