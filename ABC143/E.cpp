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

int ar[MV];
ll arr[MV];
ll G[301][301], GX[301][301];

void solve(int T)
{
	int n,m,l;
	cin>>n>>m>>l;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i != j)
			{
				G[i][j] = INF;
				G[j][i] = INF;
				GX[i][j] = INF;
				GX[j][i] = INF;
			}	
		}	
	}
	for(int i=0;i<m;i++)
	{
		int s,d;
		ll w;
		cin>>s>>d>>w;
		G[s][d] = w;
		G[d][s] = w;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(G[i][k] != INF || G[k][j] != INF)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);	
			}
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i != j)
			{
				if(G[i][j] <= l)
				GX[i][j] = 1;
			}	
		}	
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(GX[i][k] != INF || GX[k][j] != INF)
				GX[i][j] = min(GX[i][j], GX[i][k] + GX[k][j]);	
			}	
		}	
	}
	int q;
	cin>>q;
	while(q--)
	{
		int st,dt;
		cin>>st>>dt;
		if(GX[st][dt] == INF)
		cout<<"-1\n";	
		else cout<<GX[st][dt]-1<<"\n";
	}	
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

/*#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif*/

	while(T--)
	solve(T);

/*#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif*/

	return 0;
}