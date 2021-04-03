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

/* xd(i, 0) = Minimum cost to connect nodes 1 to i to net without setup on i
   xd(i, 1) = Minimum cost to connect nodes 1 to i to net via setup(lan or router)*/

int ar[MV];
ll arr[MV];
ll memo[MV][2];

void solve(int T)
{
	int n,k;
	std::string s;
	std::cin>>n>>k;
	std::cin>>s;
	std::queue<int> Q;
	for(int i=1;i<=n;i++)
	{
		memo[i][0] = INF;
		memo[i][1] = min(memo[i-1][0], memo[i-1][1]) + i;
		if(!Q.empty() && Q.front() < i-k) Q.pop();
		if(!Q.empty())
		memo[i][0] = memo[Q.front()][1];
		if(s[i-1] == '1')
		{
			memo[i][1] = min(memo[i][1], min(memo[max(0, i-k-1)][0], memo[max(0, i-k-1)][1]) + i);
			Q.push(i);
		}	
	}
	std::cout<<min(memo[n][0], memo[n][1])<<"\n";
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