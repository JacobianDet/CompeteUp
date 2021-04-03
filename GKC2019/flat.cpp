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
ll arr[MV];
int memo[21][21][1001], vis[21][21][1001];

int xd(int n, int k, int val, int T)
{
	if(k < 0)
	return 100000000;
	if(!n)
	return 0;
	if(vis[n][k][val] == T)
	return memo[n][k][val];
	int ans = 100000000;
	if(!val)
	{
		int nv = ar[n-1];
		bool ch = 0;
		if(nv != ar[n])
		ch = 1;
		if(!ch)
		ans = min(ans, xd(n-1, k, ar[n], T));
		else 
		{
			ans = min(ans, 1 + xd(n-1, k, nv, T));
			ans = min(ans, xd(n-1, k, ar[n], T));
		}	
	}
	else
	{
		int nv = val;
		bool ch = 0;
		if(nv != ar[n])
		ch = 1;
		if(!ch)
		ans = min(ans, xd(n-1, k, ar[n], T));
		else
		{
			ans = min(ans, 1 + xd(n-1, k, nv, T));
			ans = min(ans, xd(n-1, k-1, ar[n], T));
		}
	}
	vis[n][k][val] = T;
	memo[n][k][val] = ans;
	return ans;
}

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	int ans = xd(n, k, 0, T);
	cout<<"Case #"<<T<<": "<<ans<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	memset(vis, 0, sizeof(vis));
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