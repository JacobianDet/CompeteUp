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
ll memo[MV][3];
PLL par[MV][3], az[MV];
int vis[MV][3];
int n;

ll xd(int idx, int st)
{
	if(idx == n)
	{
		if(!st)
		return 0;
		else return INF;
	}	
	if(vis[idx][st])
	return memo[idx][st];
	ll ans = 0;
	if(!st)
	{
		par[idx][st] = {idx+1, 1};
		ans = -az[idx].ff + xd(idx+1, 1);
	}	
	else if(st == 1)
	{
		par[idx][st] = {idx+1, 2};
		ans = xd(idx+1, 2);
	}	
	else
	{
		if(az[idx].ff + xd(idx+1, 0) < xd(idx+1, 2))
		{
			par[idx][st] = {idx+1, 0};
			ans = min(az[idx].ff + xd(idx+1, 0), xd(idx+1, 2));
		}
		else
		{
			par[idx][st] = {idx+1, 2};
			ans = min(az[idx].ff + xd(idx+1, 0), xd(idx+1, 2));
		}	
	}		
	memo[idx][st] = ans;
	vis[idx][st] = 1;
	return ans;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	memset(vis, 0, sizeof(vis));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>az[i].ff;
		az[i].ss = i;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=2;j++)
		par[i][j] = {i, j};	
	}
	sort(az, az+n, [](PLL A, PLL B){ return (A.ff < B.ff); });
	ll ans = xd(0, 0);	
	int pidx = 0, pst = 0, tc = 1;
	while(pidx != n)
	{
		ar[az[pidx].ss] = tc;
		int npi = par[pidx][pst].ff;
		int nst = par[pidx][pst].ss;
		if(nst == 0)
		tc++;
		pidx = npi;
		pst = nst;	
	}
	tc--;
	cout<<ans<<" "<<tc<<"\n";
	for(int i=0;i<n;i++)
	cout<<ar[i]<<" ";
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