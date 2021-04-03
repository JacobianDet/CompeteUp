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
ll tab[1001][1001];

ll bs1(ll x)
{
	ll lo = 1;
	ll hi = 1000000001;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(mid * mid < x)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		std::cin>>tab[i][j];	
	}	
	ll sqx = (tab[2][0] * tab[1][0])/tab[2][1];
	ll x = bs1(sqx);
	std::cout<<x<<" ";	
	for(int i=1;i<n;i++)
	std::cout<<(tab[i][0]/x)<<" ";	
	std::cout<<"\n";
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