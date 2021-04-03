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
int memo[101][10001];

int BALLIA(int i, int x, int n)
{
	if(x < 0)
	return -10000000;
	else if(!i)
	return 0;
	if(memo[i][x] != -1)
	return memo[i][x];
	int ans = std::max(BALLIA(i-1, x, n), 1 + BALLIA(i-1, x - (n-i+1)*ar[i], n));
	memo[i][x] = ans;
	return ans;	
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	int n,x;
	std::cin>>n>>x;
	for(int i=1;i<=n;i++)
	std::cin>>ar[i];
	int ans = BALLIA(n, x, n);
	std::cout<<ans<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}