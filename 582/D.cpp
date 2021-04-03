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

int ar[MV], noz[MV];
ll arr[MV];
VI VF[MV];

void solve(int T)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>ar[i];
	std::sort(ar, ar+n);
	for(int i=0;i<n;i++)
	{
		int zf = ar[i];
		int div = 0;
		while(zf > 0)
		{
			noz[zf]++;
			if(noz[zf] <= k)
			arr[zf] += div;
			div++;
			zf /= 2;
		}
		noz[zf]++;
		if(noz[zf] <= k)
		arr[zf] += div;
	}
	ll ans = MOD;	
	for(int i=0;i<MV;i++)
	{
		if(noz[i] >= k)
		ans = std::min(ans, arr[i]);
	}	
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