#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 500001
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

int ar[MV], rx[711][711];
ll arr[MV];

void solve(int T)
{
	int q;
	std::cin>>q;
	while(q--)
	{
		int t,x,y;
		std::cin>>t>>x>>y;
		if(t == 1)
		{	
			ar[x] += y;
			for(int i=1;i<711;i++)
			rx[i][x%i] += y;
		}
		else
		{
			if(x < 711)
			std::cout<<rx[x][y]<<"\n";
			else
			{
				int ax = 0;
				for(int i=y;i<MV;i+=x)
				ax += ar[i];
				std::cout<<ax<<"\n";	
			}	
		}
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