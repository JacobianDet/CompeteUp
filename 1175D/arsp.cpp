#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 300001
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

void solve(int T)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		std::cin>>arr[i];
		arr[i] += arr[i-1];
	}
	ll sx = arr[n];
	sort(arr+1, arr+n+1);
	ll ans = 0;
	bool c1 = 0;
	for(int i=1,j=1;(i<=n && j<k);i++)
	{
		if(arr[i] == sx)
		{
			if(c1)
			{
				j++;
				ans += arr[i];
			}	
			else c1 = 1;	
		}	
		else 
		{
			j++;
			ans += arr[i];
		}
	}		
	ans = (1LL*k*sx - ans);
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