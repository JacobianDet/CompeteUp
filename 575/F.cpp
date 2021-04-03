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

int ar[MV], br[MV];
ll arr[MV];
ll G[801][801];

struct t3
{
	ll s,d,w;
}E[MV];

bool cmpx(t3 A, t3 B)
{
	return (A.w < B.w);
}

void solve(int T)
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll s,d,w;
		cin>>s>>d>>w;
		E[i] = {s, d, w};
	}	
	sort(E, E+m, cmpx);
	set<ll> S;
	for(int i=0;i<min(k, m);i++)
	{
		S.ins(E[i].s);
		S.ins(E[i].d);
	}	
	VL V(S.begin(), S.end());
	for(int i=0;i<V.sz();i++)
	{	
		ar[V[i]] = i+1;
		br[i+1] = V[i];
	}	
	for(int i=1;i<=V.sz();i++)
	{
		for(int j=1;j<=V.sz();j++)
		G[i][j] = ((i == j) ? 0 : INF);	
	}	
	for(int i=0;i<min(k, m);i++)
	{
		G[ar[E[i].s]][ar[E[i].d]] = E[i].w;
		G[ar[E[i].d]][ar[E[i].s]] = E[i].w;
	}	
	for(int z=1;z<=V.sz();z++)
	{
		for(int i=1;i<=V.sz();i++)
		{
			for(int j=1;j<=V.sz();j++)
			{	
				if(G[i][z] != INF && G[z][j] != INF)
				G[i][j] = min(G[i][j], G[i][z] + G[z][j]);
			}		
		}	
	}	
	VL CH;
	for(int i=1;i<=V.sz();i++)
	{
		for(int j=i+1;j<=V.sz();j++)
		CH.pb(G[i][j]);		
	}	
	sort(CH.begin(), CH.end());
	cout<<CH[k-1]<<"\n";
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