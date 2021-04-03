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
VI G[MV];

struct t3
{
	int s,d,dist;
}tx[MV];

bool cmpx(t3 A, t3 B)
{
	return (A.dist > B.dist);
}

void dfs_visit(int s, int p)
{
	for(auto u : G[s])
	{
		if(u != p)
		{
			std::cout<<s<<" "<<u<<"\n";
			dfs_visit(u, s);
		}	
	}
	return;
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		int d;
		std::cin>>d;
		tx[i] = {(i<<1)-1, (i<<1), d};
	}	
	sort(tx+1, tx+n+1, cmpx);
	for(int i=1;i<n;i++)
	{
		G[tx[i].s].pb(tx[i+1].s);
		G[tx[i+1].s].pb(tx[i].s);
		ar[i] = tx[i].s;
	}
	ar[n] = tx[n].s;
	int ml = n;
	for(int i=1;i<=n;i++)
	{
		int dx = i + tx[i].dist - 1;
		G[ar[dx]].pb(tx[i].d);
		G[tx[i].d].pb(ar[dx]);
		if(dx == ml)
		ar[++ml] = tx[i].d;
	}	
	dfs_visit(1, -1);
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