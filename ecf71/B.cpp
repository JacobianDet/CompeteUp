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
ll arr[MV];
int A[50][50], AX[50][50], B[50][50];

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{	
			std::cin>>A[i][j];
			AX[i][j] = A[i][j];
		}		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		A[i][j] += (A[i-1][j] + A[i][j-1] - A[i-1][j-1]);	
	}
	vector<PII> Z;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if((A[i+1][j+1] - A[i-1][j+1] - A[i+1][j-1] + A[i-1][j-1]) == 4)
			Z.pb(mp(i, j));
		}
	}
	for(auto u : Z)
	{
		B[u.ff+1][u.ss+1] |= 1;
		B[u.ff+1][u.ss] |= 1;
		B[u.ff][u.ss+1] |= 1;
		B[u.ff][u.ss] |= 1;
	}
	bool ok = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(AX[i][j] != B[i][j])
			{
				ok = 0;
				break;
			}
		}	
		if(!ok)
		break;	
	}
	if(ok)
	{
		std::cout<<Z.sz()<<"\n";
		for(auto u : Z)
		std::cout<<u.ff<<" "<<u.ss<<"\n";
	}
	else std::cout<<"-1\n";
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