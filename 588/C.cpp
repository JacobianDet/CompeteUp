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
bool tab[7][7];

int xd(int ix, int n)
{
	if(ix == n+1)
	return 0;
	int mec = 0;
	for(int i=1;i<=6;i++)
	{
		ar[ix] = i;
		int ec = 0;
		VI PX;
		for(auto u : G[ix])
		{
			if(ar[u] && !tab[ar[u]][i])
			{
				ec++;
				PX.pb(u);
				tab[ar[u]][i] = 1;
				tab[i][ar[u]] = 1;
			}	
		}
		ec += xd(ix+1, n);
		mec = max(mec, ec);
		for(auto u : PX)
		{
			tab[ar[u]][i] = 0;
			tab[i][ar[u]] = 0;	
		}
		ar[ix] = 0;
	}
	return mec;	
}

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	if(n < 7)
	std::cout<<m<<"\n";
	else
	{	
		int ans = xd(1, n);
		std::cout<<ans<<"\n";
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