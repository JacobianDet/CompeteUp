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
ll arr[MV], memo[MV][2];
int vis[MV][2];
ll n,a,b;
std::string s;

ll BALLIA(int i, bool x, int T)
{
	if(i == n)
	return b;
	if(vis[i][x] == T)
	return memo[i][x];
	ll ans = 0;
	if(!x)
	{
		if(i == n-1)
		ans = a + b + BALLIA(i+1, x, T);
		else
		{	
			if(s[i] == '0')
			ans = std::min(a + b + BALLIA(i+1, x, T), 2LL*a + b + BALLIA(i+1, 1, T));
			else ans = 1000000000000000;	
		}
	}	
	else
	{
		if(i == n-1)
		ans = 2LL*a + 2LL*b + BALLIA(i+1, 0, T);	
		else
		{
			if(s[i] == '0')
			ans = std::min(a + 2LL*b + BALLIA(i+1, x, T), 2LL*a + 2LL*b + BALLIA(i+1, 0, T));
			else ans = a + 2LL*b + BALLIA(i+1, x, T);	
		}	
	}
	vis[i][x] = T;
	memo[i][x] = ans;
	return ans;	
}

void solve(int T)
{
	std::cin>>n>>a>>b;
	std::cin>>s;
	ll tc = BALLIA(0, 0, T);	
	std::cout<<tc<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	std::cin>>T;
	while(T--)
	solve(T+1);
	return 0;
}