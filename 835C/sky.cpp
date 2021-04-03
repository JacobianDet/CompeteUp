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
ll pref[120][120][11];

struct tx3
{
	int x,y,s;
}ax[MV]; 

void solve(int T)
{
	int n,q,c;
	cin>>n>>q>>c;
	memset(pref, 0, sizeof(pref));
	for(int i=0;i<n;i++)
	cin>>ax[i].x>>ax[i].y>>ax[i].s;
	for(int t=0;t<11;t++)
	{
		for(int i=0;i<n;i++)
		pref[ax[i].x][ax[i].y][t] += (ax[i].s+t)%(c+1);
	}	
	for(int t=0;t<11;t++)
	{	
		for(int i=1;i<101;i++)
		{
			for(int j=1;j<101;j++)
			pref[i][j][t] += (pref[i-1][j][t] + pref[i][j-1][t] - pref[i-1][j-1][t]);	
		}
	}	
	while(q--)
	{
		int t,x1,y1,x2,y2;
		cin>>t>>x1>>y1>>x2>>y2;
		t %= (c + 1);
		cout<<(pref[x2][y2][t] - pref[x2][y1-1][t] - pref[x1-1][y2][t] + pref[x1-1][y1-1][t])<<"\n";
	}
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