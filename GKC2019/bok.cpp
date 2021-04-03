#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 100001
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

int ar[MV], mt[MV];
ll arr[MV];

void solve(int T)
{
	memset(ar, 0, sizeof(ar));
	memset(mt, 0, sizeof(mt));
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		ar[x]++;
	}	
	for(int i=1;i<=n;i++)
	{
		for(int p=i;p<=n;p+=i)
		mt[i] += ar[p];	
	}
	ll sx = 0;
	while(q--)
	{
		int r;
		cin>>r;
		sx += (1LL*(n/r) - mt[r]);
	}
	cout<<"Case #"<<T<<": "<<sx<<"\n";
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