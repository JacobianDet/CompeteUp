#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 505
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

int ar[MV], br[MV], memo[MV][MV], par[MV][MV];
ll arr[MV];

void solve(int T)
{
	int n,m;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>ar[i];
	std::cin>>m;
	for(int i=1;i<=m;i++)
	std::cin>>br[i];
	memo[0][0] = 0;
	for(int i=1;i<=n;i++)
	{
		memo[i][0] = 0;
		for(int j=1;j<=m;j++)
		{
			if(ar[i] != br[j])
			{
				memo[i][j] = memo[i][j-1];
				par[i][j] = par[i][j-1];
			}
			else
			{
				memo[i][j] = 1;
				par[i][j] = 0;
				for(int k=i-1;k>0;k--)
				{
					if((ar[k] < ar[i]) && (memo[k][j-1] >= memo[i][j]))
					{
						memo[i][j] = 1 + memo[k][j-1];
						par[i][j] = k;
					}	
				}
			}
		}
	}
	int ans = 0, pos = 0;
	for(int i=1;i<=n;i++)
	{
		if(ans < memo[i][m])
		{
			ans = memo[i][m];
			pos = i;
		}
	}
	int x = m;
	VI res;
	for(int _=ans;_;--_)
	{
		while(ar[pos] != br[x])
		x--;
		res.pb(ar[pos]);
		pos = par[pos][x];
		x--;	
	}
	std::reverse(res.begin(), res.end());
	std::cout<<ans<<"\n";
	for(auto u : res)
	std::cout<<u<<" ";
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