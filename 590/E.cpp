#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200005
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

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	cin>>ar[i];
	for(int i=0;i<m-1;i++)
	{
		ll a1 = ar[i];
		ll a2 = ar[i+1];
		if(a1 == a2)
		continue;
		else if(a1 > a2)
		{
			ll tp = a1;
			a1 = a2;
			a2 = tp;
		}	
		arr[1] += (a2 - a1);
		arr[a1] -= (a2 - a1);
		arr[a1] += (a2 - 1);
		arr[a1+1] -= (a2 - 1);
		arr[a1+1] += (a2 - a1 - 1);
		arr[a2] -= (a2 - a1 - 1);
		arr[a2] += a1;
		arr[a2+1] -= a1;
		arr[a2+1] += (a2 - a1);
		arr[n+1] -= (a2 - a1);
	}	
	for(int i=1;i<=n;i++)
	arr[i] += arr[i-1];
	for(int i=1;i<=n;i++)
	cout<<arr[i]<<" ";
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