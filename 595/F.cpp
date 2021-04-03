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
int memo[205][205], suff[205][205], sx[205];
VI G[MV];

void dfs_visit(int s, int p, int k)
{
	VI chd;
	for(auto u : G[s])
	{
		if(u != p)
		{	
			chd.pb(u);
			dfs_visit(u, s, k);
		}		
	}
	memset(sx, 0, sizeof(sx));
	for(int h=0;h<=201;h++)
	{
		for(int i=0,j=(int)chd.sz();i<j;i++)
		sx[h] += suff[chd[i]][h];	
	}	
	for(int i=0,j=(int)chd.sz();i<j;i++)
	{
		for(int h=1;h<=201;h++)
		{
			if(h <= k/2)
			{
				int rh = (k - h);			
				memo[s][h] = max(memo[s][h], sx[rh] - suff[chd[i]][rh] + suff[chd[i]][h-1]);
			}
			else memo[s][h] = max(memo[s][h], sx[h-1]);
		}	
	}	
	for(int h=k+1;h<=201;h++)
	memo[s][0] = max(memo[s][0], memo[s][h] + ar[s]);
	for(int h=201;h>=0;h--)
	suff[s][h] = max(memo[s][h], suff[s][h+1]);
	return;	
}

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_visit(1, -1, k);
	int mx = 0;
	for(int i=0;i<=201;i++)
	mx = max(mx, memo[1][i]);
	cout<<mx<<"\n";
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