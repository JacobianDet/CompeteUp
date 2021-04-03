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

int ar[MV], jp[MV];
ll arr[MV], lvl[MV];
PLL bss[MV];
vector<PLL> G[MV];

int bs2(int nod)
{
	int lo = 0;
	int hi = ar[nod]-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(lvl[nod] - bss[mid].ff > arr[nod])
		lo = mid;
		else hi = mid - 1;
	}
	if((lo > hi) || (lvl[nod] - bss[lo].ff <= arr[nod]))
	lo--;
	return lo;
}

void dfs_visit(int s, int p)
{
	int ps = bs2(s);
	jp[p]++;
	if(ps != -1)
	jp[bss[ps].ss]--;
	else jp[0]--;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			ar[u.ff] = ar[s] + 1;
			lvl[u.ff] = lvl[s] + u.ss;
			bss[ar[s]] = mp(lvl[s], s);
			dfs_visit(u.ff, s);
			jp[s] += jp[u.ff];
		}
	}
	return;
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
	dfs_visit(1, 0);
	for(int i=1;i<=n;i++)
	std::cout<<jp[i]<<" ";
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