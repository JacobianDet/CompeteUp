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
ll arr[MV], fx[2][MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	for(int i=1;i<n;i++)
	{
		fx[0][i] += abs(arr[i] - arr[i+1]);
		if(!(i & 1))
		fx[0][i] = -fx[0][i];
		fx[0][i] += fx[0][i-1];
		fx[1][i] += abs(arr[i] - arr[i+1]);
		if(i & 1)
		fx[1][i] = -fx[1][i];
		fx[1][i] += fx[1][i-1];	
 	}
	ll mv = 0, mx = -INF;
	for(int i=1;i<n;i++)
	{
		if(mv > fx[0][i])
		mv = fx[0][i];
		mx = max(mx, (fx[0][i] - mv));
	}
	mv = 0;
	for(int i=1;i<n;i++)
	{
		if(mv > fx[1][i])
		mv = fx[1][i];	
		mx = max(mx, (fx[1][i] - mv));	
	}	
	cout<<mx<<"\n";
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