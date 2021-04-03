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

void solve(int T)
{
	int n,l,r;
	std::cin>>n>>l>>r;
	ll ls = 0, rs = 0;
	int x = l-1;
	while(x)
	{
		ls += 1LL<<x;
		x--;
	}
	for(int i=0;i<(n-l+1);i++)
	ls += 1LL;
	x = 0;
	while(x < r-1)
	{
		rs += 1LL<<x;
		x++;
	}	
	for(int i=0;i<(n-r+1);i++)
	rs += (1LL<<x);
	std::cout<<ls<<" "<<rs<<"\n";
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