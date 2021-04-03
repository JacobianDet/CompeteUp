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

void solve(int T)
{
	int n,k,p;
	cin>>n>>k>>p;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	if(p)
	{
		int mn = 1000000001;
		for(int i=0;i<n;i++)
		{
			if(mn > ar[i])
			mn = ar[i];	
		}	
		if(k & 1)
		cout<<mn<<"\n";
		else
		{
			int gn = 1000000001;
			for(int i=0;i<n;i++)
			{
				int imx = 0;
				if(i-1 >= 0)
				imx = max(imx, ar[i-1]);
				if(i+1 <= n-1)
				imx = max(imx, ar[i+1]);
				gn = min(gn, imx);	
			}
			cout<<gn<<"\n";
		}	
	}	
	else
	{
		int mn = 0;
		for(int i=0;i<n;i++)
		{
			if(mn < ar[i])
			mn = ar[i];	
		}	
		if(k & 1)
		cout<<mn<<"\n";
		else
		{
			int gn = 0;
			for(int i=0;i<n;i++)
			{
				int imx = 1000000001;
				if(i-1 >= 0)
				imx = min(imx, ar[i-1]);
				if(i+1 <= n-1)
				imx = min(imx, ar[i+1]);
				gn = max(gn, imx);	
			}
			cout<<gn<<"\n";
		}		
	}
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