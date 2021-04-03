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
ll arr[MV];
VI G[MV];
MLL az[MV];

ll dfs_visit(int s, int p)
{
	ll ans = 0;
	if(p != -1)
	{
		for(auto u : az[p])
		az[s][std::__gcd(arr[s], u.ff)] += u.ss;	
	}
	az[s][arr[s]]++;
	for(auto u : az[s])
	ans += (u.ff * u.ss)%MOD;
	if(ans >= MOD)
	ans -= MOD;	
	for(auto u : G[s])
	{
		if(u != p)
		{	
			ans += dfs_visit(u, s)%MOD;
			if(ans >= MOD)
			ans -= MOD;
		}	
	}
	return ans;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];	
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	ll ans = dfs_visit(1, -1);
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