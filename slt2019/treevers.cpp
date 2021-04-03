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

int ar[MV];
ll zz[MV], sze[MV];
ll arr[MV];
VI G[MV];
VI disc;

bool cmpx(int A, int B)
{
	if((zz[B] * (sze[A] - zz[A])) < (zz[A] * (sze[B] - zz[B])))
	return 1;	
	else return 0;	
}

void dfs_visit(int s, int p)
{
	disc.pb(ar[s]);
	sze[s] = 1;
	zz[s] = (!ar[s]) ? 1 : 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			sze[s] += sze[u];
			zz[s] += zz[u];
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
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_visit(1, -1);
	disc.clear();
	for(int i=1;i<=n;i++)
	sort(G[i].begin(), G[i].end(), cmpx);
	dfs_visit(1, -1);
	ll zc = 0, invf = 0;
	for(int i=0;i<disc.sz();i++)
	{
		if(disc[i])
		zc++;	
		else invf += zc;		
	}
	cout<<invf<<"\n";
	for(int i=1;i<=n;i++)
	{	
		sze[i] = 0;
		zz[i] = 0;
		G[i].clear();
	}	
	disc.clear();	
	return;	
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

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