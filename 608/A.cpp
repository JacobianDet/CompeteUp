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
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	ll tot = 0;
	if(e > f)
	{
		int x = min(a,d);
		tot += 1LL*e*x;
		d -= x;
		a -= x;
		int y = min(d, min(b,c));
		tot += 1LL*f*y;
		d -= y;
		b -= y;
		c -= y;
	}
	else
	{
		int y = min(d, min(b,c));
		tot += 1LL*f*y;
		d -= y;
		b -= y;
		c -= y;
		int x = min(a,d);
		tot += 1LL*e*x;
		d -= x;
		a -= x;
	}
	cout<<tot<<"\n";
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