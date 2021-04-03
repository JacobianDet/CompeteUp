#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 100001
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

/* 0 = DARKNESS
   1 = INDIRECT INFLUENCE
   2 = DIRECT INFLUENCE*/

int ar[MV];
ll arr[MV];
VI G[MV];
ll memo[MV][3][2];

void dfs_visit(int s, int p)
{
	memo[s][0][0] = -100000000001;
	memo[s][1][0] = -100000000001;
	memo[s][1][1] = -100000000001;
	memo[s][2][0] = -100000000001;
	int ct = 0;
	ll sx0 = 0, sx10 = -100000000001, sx11 = 0, sx2 = 0;
	VL chd0, chd1, chd2;
	for(auto u : G[s])
	{
		if(u != p)
		{
			ct++;
			dfs_visit(u, s);
			sx0 += max(memo[u][0][0], memo[u][1][0]);
			sx2 += max(memo[u][1][1], memo[u][2][0]);
			chd0.pb(memo[u][0][0]);
			chd1.pb(memo[u][1][0]);
			chd2.pb(memo[u][2][0]);
		}	
	}
	bool ok = 0;
	for(int i=0;i<chd1.sz();i++)
	{
		if((chd2[i] >= chd1[i]) && (chd2[i] >= chd0[i]))
		{
			ok = 1;
			break;
		}		
	}	
	if(ok)
	{
		for(int i=0;i<chd1.sz();i++)
		sx10 += max(chd0[i], max(chd1[i], chd2[i]));	
	}	
	for(int i=0;i<chd1.sz();i++)
	sx11 += max(chd0[i], max(chd1[i], chd2[i]));
	for(int i=0;i<chd1.sz();i++)
	sx10 = max(sx10, sx11 - max(chd0[i], max(chd1[i], chd2[i])) + chd2[i]);	
	sx2 += arr[s];
	sx10 += arr[s];
	sx11 += arr[s];
	memo[s][0][0] = max(memo[s][0][0], sx0);
	if(ct > 0)
	memo[s][1][0] = max(memo[s][1][0], sx10);
	if(p != -1)
	memo[s][1][1] = max(memo[s][1][1], sx11);
	memo[s][2][0] = max(memo[s][2][0], sx2);
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_visit(1, -1);
	ll ans = max(0LL, max(memo[1][0][0], max(memo[1][1][0], memo[1][2][0])));
	cout<<"Case #"<<T<<": "<<ans<<"\n";
	for(int i=1;i<=n;i++)
	G[i].clear();	
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
/*
#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif
*/
	for(int _=1;_<=T;_++)
	solve(_);
/*
#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif
*/
	return 0;
}