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
int memo[13][99];

/*int xd(int n, int k)
{
	if(!k)
	return 1;
	else if(!n)
	return 0;
	if(memo[n][k] != -1)
	return memo[n][k];
	int ans = 0;
	for(int i=0;(k-i>=0 && i<n);i++)
	ans += xd(n-1, k-i);	
	memo[n][k] = ans;
	return ans;
}*/

void solve(int T)
{
	memset(memo, 0, sizeof(memo));
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	memo[0][i] = 0;
	for(int i=1;i<=n;i++)
	memo[i][0] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(j <= (i * (i-1))/2)
			{	
				memo[i][j] = memo[i-1][j];
				if(j >= i)
				memo[i][j] -= memo[i-1][j-i];
			}
			memo[i][j] += memo[i][j-1];
			//cout<<i<<" "<<j<<" "<<memo[i][j]<<"\n";	
		}	
	}	
	/*int ans = xd(n, k);
	cout<<ans<<"\n";*/
	if(k > 0)
	cout<<memo[n][k] - memo[n][k-1]<<"\n";
	else cout<<memo[n][k]<<"\n";
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