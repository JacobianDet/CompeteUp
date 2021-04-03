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

int ar[MV], grid[2001][2001];
ll arr[MV];

void solve(int T)
{
	int n;
	std::cin>>n;
	int x = 0;
	for(int i=0;i<n/2;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			grid[i][j] = 4*x;
			grid[i][j+n/2] = 4*x + 1;
			grid[i+n/2][j] = 4*x + 2;
			grid[i+n/2][j+n/2] = 4*x + 3;
			x++;
		}	
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		std::cout<<grid[i][j]<<" ";
		std::cout<<"\n";
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