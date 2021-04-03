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

ll b[MV];
ll arr[MV];
MLL MX;
VL sm, df;

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<n;i++)
	std::cin>>b[i];
	ll tsk = 0;
	if(n == 1)
	std::cout<<"0\n";
	else
	{
		for(int i=0;i<n;i++)
		MX[arr[i]]++;	
		for(int i=0;i<n;i++)
		{
			if(MX[arr[i]] >= 2)
			{	
				sm.pb(i);
				tsk += b[i];
			}	
			else df.pb(i);	
		}
		for(auto u : df)
		{
			bool ok = 0;
			for(auto v : sm)
			{
				if((arr[u] & arr[v]) == arr[u])
				{
					ok = 1;
					break;
				}	
			}	
			if(ok)
			tsk += b[u];
		}
		std::cout<<tsk<<"\n";
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