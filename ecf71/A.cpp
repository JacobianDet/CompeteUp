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
	int b,p,f,h,c;
	std::cin>>b>>p>>f>>h>>c;
	if(h > c)
	{
		int x = min(b/2, p);
		int y = min((b - 2*x)/2, f);
		cout<<x*h + y*c<<"\n";
	}	
	else
	{
		int y = min(b/2, f);
		int x = min((b - 2*y)/2, p);
		cout<<x*h + y*c<<"\n";
	}
	return;
}

int main(void)
{
	FLASH();
	int T;
	std::cin>>T;
	while(T--)
	solve(T);
	return 0;
}