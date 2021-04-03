#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define MV 300001
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
ll arr1[MV], arr2[MV];
ll factx[MV];
MPLL arr3;

void factup(void)
{
	factx[0] = 1;
	for(ll i=1;i<MV;i++)
	factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
	return;	
}

void solve(int T)
{
	factup();
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll a,b;
		std::cin>>a>>b;
		arr1[a]++;
		arr2[b]++;
		arr3[mp(a, b)]++;
	}
	ll ax = 1;
	for(int i=1;i<=n;i++)
	ax = ((ax%MOD) * (factx[arr1[i]]%MOD))%MOD;
	ll bx = 1;
	for(int i=1;i<=n;i++)
	bx = ((bx%MOD) * (factx[arr2[i]]%MOD))%MOD;
	ll cx = 1;
	PLL p = (*arr3.begin()).ff;
	bool ok = 1;
	for(auto u : arr3)
	{	
		cx = ((cx%MOD) * (factx[u.ss]%MOD))%MOD;
		if(p.ff > u.ff.ff || p.ss > u.ff.ss)
		ok = 0;
		p = u.ff;
	}
	ll fx = 0;
	if(ok)	
	fx = ((((factx[n]%MOD) - (((ax%MOD) + (bx%MOD))%MOD) + MOD)%MOD) + (cx%MOD))%MOD;
	else fx = (((factx[n]%MOD) - (((ax%MOD) + (bx%MOD))%MOD) + MOD)%MOD)%MOD;
	cout<<fx<<"\n";
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