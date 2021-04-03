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

void solve(int T)
{
	int q;
	std::cin>>q;
	while(q--)
	{
		ll n,m;
		std::cin>>n>>m;
		if(n < m)
		std::cout<<"0\n";
		else
		{
			int dx = m%10;
			VL Z;
			for(int i=1;i<10;i++)
			Z.pb(((m%10) * ((ll)i%10))%10);
			ll dv = n/m;
			ll sx = 0;
			for(auto u : Z)
			sx += u;
			ll tx = dv/10;
			ll ans = sx * tx;
			tx = dv - tx*10;
			for(int i=0;i<tx;i++)
			ans += Z[i];
			std::cout<<ans<<"\n";	
		}	
	}
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