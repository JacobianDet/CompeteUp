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
int memo[201][201][401];
string s,t;
int n,m;

struct t3
{
	int ix,jx,psrx;
}par[201][201][401];

int xd(int i, int j, int psr)
{
	if((i == n) && (j == m))
	return psr;
	if(memo[i][j][psr] != -1)
	return memo[i][j][psr];
	int ans = MOD;
	if((i < n) && (j < m))
	{
		if((s[i] == '(') && (t[j] == '('))
		{
			ans = min(ans, 1 + xd(i+1, j+1, psr+1));
			ans = min(ans, 1 + xd(i, j+1, psr+1));
			ans = min(ans, 1 + xd(i+1, j, psr+1));
			if(ans == 1 + xd(i+1, j+1, psr+1))
			par[i][j][psr] = {i+1, j+1, psr+1};
			else if(ans == 1 + xd(i, j+1, psr+1))
			par[i][j][psr] = {i, j+1, psr+1};
			else par[i][j][psr] = {i+1, j, psr+1};
		}	
		else if((s[i] == '(') && (t[j] == ')'))
		{
			if(psr > 0)
			ans = min(ans, 1 + xd(i, j+1, psr-1));
			else ans = min(ans, 1 + xd(i, j, psr+1));
			ans = min(ans, 1 + xd(i+1, j, psr+1));	
			if(ans == 1 + xd(i+1, j, psr+1))
			par[i][j][psr] = {i+1, j, psr+1};
			else
			{
				if(psr > 0)
				par[i][j][psr] = {i, j+1, psr-1};
				else par[i][j][psr] = {i, j, psr+1};	
			}	
		}
		else if((s[i] == ')') && (t[j] == '('))
		{
			if(psr > 0)
			ans = min(ans, 1 + xd(i+1, j, psr-1));
			else ans = min(ans, 1 + xd(i, j, psr+1));
			ans = min(ans, 1 + xd(i, j+1, psr+1));	
			if(ans == 1 + xd(i, j+1, psr+1))
			par[i][j][psr] = {i, j+1, psr+1};
			else
			{
				if(psr > 0)
				par[i][j][psr] = {i+1, j, psr-1};
				else par[i][j][psr] = {i, j, psr+1};	
			}	
		}
		else
		{
			if(psr > 0)
			{
				ans = min(ans, 1 + xd(i+1, j+1, psr-1));
				ans = min(ans, 1 + xd(i+1, j, psr-1));
				ans = min(ans, 1 + xd(i, j+1, psr-1));
				if(ans == 1 + xd(i+1, j+1, psr-1))
				par[i][j][psr] = {i+1, j+1, psr-1};
				else if(ans == 1 + xd(i, j+1, psr-1))
				par[i][j][psr] = {i, j+1, psr-1};
				else par[i][j][psr] = {i+1, j, psr-1};
			}
			else 
			{
				ans = min(ans, 1 + xd(i, j, psr+1));
				par[i][j][psr] = {i, j, psr+1};
			}		
		}
	}	
	else if(i == n)
	{
		if(t[j] == '(')
		{
			ans = min(ans, 1 + xd(i, j+1, psr+1));
			par[i][j][psr] = {i, j+1, psr+1};
		}	
		else
		{
			if(psr > 0)
			{
				ans = min(ans, 1 + xd(i, j+1, psr-1));
				par[i][j][psr] = {i, j+1, psr-1};
			}	
			else 
			{
				ans = min(ans, 1 + xd(i, j, psr+1));
				par[i][j][psr] = {i, j, psr+1};
			}		
		}	
	}
	else
	{
		if(s[i] == '(')
		{
			ans = min(ans, 1 + xd(i+1, j, psr+1));
			par[i][j][psr] = {i+1, j, psr+1};
		}	
		else
		{
			if(psr > 0)
			{
				ans = min(ans, 1 + xd(i+1, j, psr-1));
				par[i][j][psr] = {i+1, j, psr-1};
			}	
			else 
			{
				ans = min(ans, 1 + xd(i, j, psr+1));
				par[i][j][psr] = {i, j, psr+1};
			}		
		}	
	}
	memo[i][j][psr] = ans;
	return ans;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	cin>>s>>t;
	n = (int)s.size();
	m = (int)t.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int psr=0;psr<=400;psr++)
			par[i][j][psr] = {i, j, psr};	
		}	
	}
	int res = xd(0, 0, 0);
	string ans = "";
	int pix = 0, pjx = 0, ppsrx = 0;
	while((pix != n) || (pjx != m))
	{
		int nix = par[pix][pjx][ppsrx].ix;
		int njx = par[pix][pjx][ppsrx].jx;
		int npsrx = par[pix][pjx][ppsrx].psrx;
		if(ppsrx < npsrx)
		ans += '(';
		else ans += ')';
		pix = nix;
		pjx = njx;
		ppsrx = npsrx;	
	}
	for(int i=0;i<ppsrx;i++)
	ans += ')';
	cout<<ans<<"\n";	
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