#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
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
string s,t;
int memo[1001][1001][11];
int ball[1001][1001];

int BALLIA(int n, int m, int k)
{
	if(k && (!n || !m))
	return -10000000;
	else if(!k)
	return 0;
	if(memo[n][m][k] != -1)
	return memo[n][m][k];
	int ans = 0;
	if(s[n-1] == t[m-1])
	{
		ans = std::max(ans, ball[n][m] + BALLIA(n-ball[n][m], m-ball[n][m], k-1));
		if(ball[n][m] > k)
		ans = std::max(ans, ball[n][m] - k + 1 + BALLIA(n-ball[n][m]+k-1, m-ball[n][m]+k-1, k-1));
		ans = std::max(ans, 1 + BALLIA(n-1, m-1, k-1));	
	}
	ans = std::max(ans, std::max(BALLIA(n-1, m, k), BALLIA(n, m-1, k)));	
	memo[n][m][k] = ans;
	return ans;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	int n,m,k;
	std::cin>>n>>m>>k;
	std::cin>>s>>t;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i-1] == t[j-1])
			ball[i][j] = 1 + ball[i-1][j-1];
			else ball[i][j] = 0;	
		}	
	}
	int ans = BALLIA(n, m, k);
	std::cout<<ans<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}