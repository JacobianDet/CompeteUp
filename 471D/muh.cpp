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

int ar[MV], pt[MV], lcp[MV];
ll arr[MV];

void solve(int T)
{
	int n,w;
	std::cin>>n>>w;
	for(int i=0;i<n;i++)
	std::cin>>ar[i];
	for(int i=0;i<w;i++)
	std::cin>>pt[i];
	if(w == 1)
	std::cout<<n<<"\n";
	else
	{
		for(int i=0;i<n-1;i++)
		ar[i] -= ar[i+1];
		for(int i=0;i<w-1;i++)
		pt[i] -= pt[i+1];
		for(int i=1;i<w-1;i++)
		{
			int j = lcp[i-1];
			while(j && (pt[i] != pt[j]))
			j = lcp[j-1];
			if(pt[i] == pt[j])
			j++;
			lcp[i] = j;	
		} 	
		int pf = 0;
		ll ans = 0;
		for(int i=0;i<n-1;i++)
		{
			int j = pf;
			while(j && (ar[i] != pt[j]))
			j = lcp[j-1];
			if(ar[i] == pt[j])
			j++;
			if(j == w-1)
			{	
				ans++;
				pf = lcp[j-1];
			}
			else pf = j;		
		}
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