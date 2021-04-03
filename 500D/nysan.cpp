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
ll ez[MV], arr[MV], sze[MV];
vector<PPLL> G[MV];

ll dfs_visit(int s, int p, int n)
{
	ll az = 0;
	sze[s]++;
	for(auto u : G[s])
	{
		if(u.ff.ff != p)
		{
			az += dfs_visit(u.ff.ff, s, n);
			sze[s] += sze[u.ff.ff];
			az += (u.ff.ss * sze[u.ff.ff] * (n - sze[u.ff.ff]));
			ez[u.ss] = sze[u.ff.ff] * (n - sze[u.ff.ff]);
		}
	}
	return az;
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<n;i++)
	{
		int s,d;
		ll w;
		std::cin>>s>>d>>w;
		arr[i] = w;
		G[s].pb(mp(mp(d, w), i));
		G[d].pb(mp(mp(s, w), i));
	}	
	ll ans = dfs_visit(1, -1, n);
	int q;
	std::cin>>q;
	while(q--)
	{
		int id;
		ll w;
		std::cin>>id>>w;
		ll df = (arr[id] - w);
		arr[id] = w;
		ans -= ez[id] * df;
		SETF();
		ld res = ((ld)6 * ans)/((ld)n * (ld)(n-1));
		std::cout<<setprecision(10)<<res<<"\n";
		UNSETF();
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