#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
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
PII dax[101];

void solve(int T)
{
	int n,p1,p2,p3,t1,t2;
	std::cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=0;i<n;i++)
	std::cin>>dax[i].ff>>dax[i].ss;
	int ans = 0;
	for(int i=1;i<n;i++)
	{
		if((dax[i].ff - dax[i-1].ss) <= t1)
		ans += (dax[i].ff - dax[i-1].ff)*p1;
		else if((dax[i].ff - dax[i-1].ss) <= (t1 + t2))
		ans += (dax[i-1].ss + t1 - dax[i-1].ff)*p1 + (dax[i].ff - (dax[i-1].ss + t1))*p2;
		else ans += (dax[i-1].ss + t1 - dax[i-1].ff)*p1 + t2*p2 + (dax[i].ff - (dax[i-1].ss + t1 + t2))*p3;	
	}
	ans += (dax[n-1].ss - dax[n-1].ff)*p1;	
	std::cout<<ans<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}