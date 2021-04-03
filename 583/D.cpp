#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 1000001
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
vector<string> SV;
bool memo[2][MV+2];

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	SV.resize(n);
	for(int i=0;i<n;i++)
	std::cin>>SV[i];
	memo[0][m] = 1;
	memo[1][m] = 1;
	int ans = 0;
	for(int i=n;i>0;i--)
	{
		for(int j=m;j>0;j--)
		{	
			if(SV[i-1][j-1] != '#')
			{	
				if(i+1 <= n)
				memo[1][j] |= memo[0][j];
				if(j+1 <= m)
				memo[1][j] |= memo[1][j+1];
			}
			else memo[1][j] = 0;
		}	
		for(int j=m;j>0;j--)
		memo[0][j] = memo[1][j];
		if((i == 2) && memo[0][1])
		ans++;
		if((i == 1) && (m >= 2) && memo[0][2])
		ans++;	
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