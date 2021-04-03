#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 1000001
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
VI V,Z;
int memo[MV][3];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<(1<<7);i++)
	{
		int x = 0;
		for(int j=0;j<7;j++)
		{
			if(i & (1<<j))
			x = 10*x + 1;
			else x = 10*x;	
		}	
		if(x)
		V.pb(x);	
	}	
	for(int x=0;x<=n;x++)
	{
		for(int i=0;i<3;i++)
		memo[x][i] = 100000000;	
	}	
	memo[0][0] = 0;
	for(int i=1,j=(int)V.sz();i<=j;i++)
	{
		for(int x=0;x<=n;x++)
		{
			memo[x][1] = min(memo[x][1], memo[x][0]);
			if(x-V[i-1] >= 0)
			{
				if(1+memo[x-V[i-1]][1] < memo[x][1])
				{
					memo[x][1] = min(memo[x][1], 1+memo[x-V[i-1]][1]);
					memo[x][2] = V[i-1];
				}
			}				
		}
		for(int x=0;x<=n;x++)
		memo[x][0] = memo[x][1];	
	}
	cout<<memo[n][0]<<"\n";
	int z = n;
	while(z > 0)
	{
		cout<<memo[z][2]<<" ";
		z -= memo[z][2];
	}
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