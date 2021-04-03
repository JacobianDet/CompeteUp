#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
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
ll arr[MV], factx[MV], invf[MV];

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

void factup(void)
{
	factx[0] = 1;
	invf[0] = 1;
	for(ll i=1;i<MV;i++)
	{	
		factx[i] = ((factx[i-1]%MOD) * (i%MOD))%MOD;
		invf[i] = modexp(factx[i], MOD-2)%MOD;
	}
	return;	
}

void solve(int T)
{
	ll n,m,k;
	std::cin>>n>>m>>k;
	ll sx = 0;
	for(ll i=0;i<k;i++)
	{
		ll nc = ((factx[n]%MOD) * (((invf[n-i]%MOD) * (invf[i]%MOD))%MOD))%MOD;
		sx = (((sx%MOD) + (((nc%MOD) * (modexp(m-1, n-i)%MOD))%MOD))%MOD);
	}	
	ll ans = ((modexp(m, n)%MOD) - (sx%MOD) + MOD)%MOD;
	std::cout<<ans<<"\n";
	return;
}

int main(void)
{
	FLASH();
	factup();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}