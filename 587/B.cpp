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
vector<PII> D;

bool cmpx(PII A, PII B)
{
	return (A.ff > B.ff);
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		std::cin>>x;
		D.pb(mp(x, i));
	}
	sort(D.begin(), D.end(), cmpx);
	ll sh = 0;
	for(int i=0;i<n;i++)
	sh += ((1LL*D[i].ff * 1LL*i) + 1);
	std::cout<<sh<<"\n";
	for(int i=0;i<n;i++)
	std::cout<<D[i].ss+1<<" ";
	std::cout<<"\n";
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