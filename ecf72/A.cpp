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

void solve(int T)
{
	ll s,i,e;
	std::cin>>s>>i>>e;
	ll z = (i+e-s)/2;
	if(i+e-s < 0)
	z = -1; 	
	std::cout<<std::max(0LL, e-z)<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}