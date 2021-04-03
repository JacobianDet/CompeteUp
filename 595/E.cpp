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

int ar[MV], br[MV];
ll arr[MV];
int memo[MV][2];
int c;

int xd(int n, int l)
{
	if(n == 1)
	return 0;
	if(memo[n][l] != -1)
	return memo[n][l];
	int ans = 0;
	if(!l)
	ans = min(ar[n-1] + xd(n-1, l), c + br[n-1] + xd(n-1, l^1));
	else ans = min(ar[n-1] + xd(n-1, l^1), br[n-1] + xd(n-1, l));
	memo[n][l] = ans;
	return ans;	
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	int n;
	cin>>n>>c;
	for(int i=1;i<n;i++)
	cin>>ar[i];
	for(int i=1;i<n;i++)
	cin>>br[i];
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<2;j++)
		memo[i][j] = xd(i, j);	
	}	
	for(int i=1;i<=n;i++)
	cout<<memo[i][0]<<" ";
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