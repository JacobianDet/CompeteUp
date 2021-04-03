#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 1000001
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
int memo[MV][5][5];
int m;

int xd(int idx, int p1, int p2)
{
	if(idx == m+1)
	return 0;
	if(memo[idx][p1][p2] != -1)
	return memo[idx][p1][p2];
	int ans = 0;
	int x = ar[idx]/3;
	int r = ar[idx]%3;
	ans = max(ans, x + xd(idx+1, r, p1));
	int v = 0;
	if(!x)
	v = 0;
	else if(x < 2)
	v = 3;
	else v = 6;	
	for(int i=r;i<=min(6, r+v);i++)
	{
		int m = min(p1, min(p2, i));
		int sx = 0;
		if(i == r)
		sx = 0;	
		else if(i - r <= 3)
		sx = 1;
		else sx = 2;	
		if(i-m <= 4)
		ans = max(ans, x + m - sx + xd(idx+1, i-m, p1-m));
		if(i <= 4)
		ans = max(ans, x - sx + xd(idx+1, i, p1));
	}	
	memo[idx][p1][p2] = ans;
	return ans;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	int n;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		ar[t]++;
	}
	int ans = xd(1, 0, 0);
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