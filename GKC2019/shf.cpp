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
ll arr[MV], brr[MV], memo[2][(1<<20)];

void solve(int T)
{
	int n,h;
	cin>>n>>h;	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	for(int i=0;i<n;i++)
	cin>>brr[i];
	for(int mask=0;mask<(1<<n);mask++)
	{
		ll sx1 = 0, sx2 = 0; 
		for(int i=0;i<n;i++)
		{
			if(mask & (1<<i))
			{	
				sx2 += brr[i];	
				sx1 += arr[i];
			}	
		}	
		if(sx2 >= h)
		memo[1][mask] = 1;
		else memo[1][mask] = 0;
		if(sx1 >= h)
		memo[0][mask] = 1;
		else memo[0][mask] = 0;	
	}	
	for(int i=0;i<n;i++)
	{
		for(int mask=(1<<n)-1;mask>=0;mask--)
		{
			if(!(mask & (1<<i)))
			memo[1][mask] += memo[1][mask ^ (1<<i)];	
		}	
	}
	ll res = 0;
	for(int mask=0;mask<(1<<n);mask++)
	res += memo[0][mask] * memo[1][((1<<n)-1) ^ mask];
	cout<<"Case #"<<T<<": "<<res<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

/*#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif*/

	for(int _=1;_<=T;_++)
	solve(_);

/*#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif*/

	return 0;
}