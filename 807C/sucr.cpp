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

ll bs1(ll x, ll y, ll p, ll q)
{
	ll lo = 0;
	ll hi = y;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if((p*mid >= x) && (q*mid - p*mid >= y - x))
		hi = mid;
		else lo = mid + 1;	
	}
	return (q*lo - y);
}

void solve(int T)
{
	ll x,y,p,q;
	std::cin>>x>>y>>p>>q;
	if((p*y < x) || (q*y - p*y < y - x))
	std::cout<<"-1\n";
	else
	{
		ll ans = bs1(x, y, p, q);
		std::cout<<ans<<"\n";
	}	
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}