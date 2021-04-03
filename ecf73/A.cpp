#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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

int ar[MV];
ll arr[MV];
bool memo[101][2049];
int vis[101][2049];
VI D;

bool BALLIA(int id, int sx, int T)
{
	if(sx < 0)
	return 0;
	else if(id == (int)D.sz())
	{
		if(!sx)
		return 1;
		else return 0;	
	}	
	if(vis[id][sx] == T)
	return memo[id][sx];
	bool ans = BALLIA(id+1, sx, T) | BALLIA(id+1, sx-D[id], T);
	memo[id][sx] = ans;
	vis[id][sx] = T;
	return ans;	
}

void solve(int T)
{
	D.clear();
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		std::cin>>x;
		if(x <= 2048)
		D.pb(x);	
	}
	n = D.sz();
	bool ans = BALLIA(0, 2048, T);
	std::cout<<(ans ? "YES" : "NO")<<"\n";
	return;
}

int main(void)
{
	FLASH();
	for(int i=0;i<101;i++)
	{
		for(int x=0;x<2049;x++)
		{
			memo[i][x] = 0;
			vis[i][x] = 2049;
		}	
	}
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}