#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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
ll arr[MV], brr[MV];
ll memo[MV][3];
int vis[MV][3];
int n;

ll BALLIA(int id, int mi, int T)
{
	if(id == n)
	return 0;
	if(vis[id][mi] == T)
	return memo[id][mi];
	ll ans = 1000000000000000001;
	if(!id || (arr[id-1] + mi != arr[id]))
	ans = min(ans, BALLIA(id+1, 0, T));
	if(!id || (arr[id-1] + mi != arr[id] + 1))
	ans = min(ans, brr[id] + BALLIA(id+1, 1, T));
	if(!id || (arr[id-1] + mi != arr[id] + 2)) 
	ans = min(ans, 2*brr[id] + BALLIA(id+1, 2, T));	
	memo[id][mi] = ans;
	vis[id][mi] = T;
	return ans;
}

void solve(int T)
{
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i]>>brr[i];
	ll ans = BALLIA(0, 0, T);
	std::cout<<ans<<"\n";
	return;		
}

int main(void)
{
	FLASH();
	for(int i=0;i<MV;i++)
	{
		for(int j=0;j<3;j++)
		{
			vis[i][j] = MV;
			memo[i][j] = 0;
		}	
	}	
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}