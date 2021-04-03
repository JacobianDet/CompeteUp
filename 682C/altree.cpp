#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
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
ll arr[MV], lvl[MV];
vector<PLL> G[MV];

int dfs_visit(int s, int p, ll lv)
{
	ar[s] = 1;
	int sx = 0;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			lvl[u.ff] = lvl[s] + u.ss;
			sx += dfs_visit(u.ff, s, std::min(lv, lvl[s]));
			ar[s] += ar[u.ff];
		}
	}
	if(lvl[s] - lv > arr[s])
	sx = ar[s];
	return sx;	
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	for(int i=1;i<n;i++)
	{
		ll p,c;
		std::cin>>p>>c;
		G[i+1].pb(mp(p, c));
		G[p].pb(mp(i+1, c));
	}	
	int ax = dfs_visit(1, -1, 0LL);
	std::cout<<ax<<"\n";
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