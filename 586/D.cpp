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
VL Z[64];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		ll xl;
		cin>>xl;
		int ct = 0;
		ll t = xl;
		while(!(t % 2))
		{
			ct++;
			t /= 2;
		}
		Z[ct].pb(xl);
	}
	int mx = 0, px = -1;
	for(int i=0;i<64;i++)
	{
		if((px == -1) || (mx < (int)Z[i].sz()))
		{	
			mx = max(mx, (int)Z[i].sz());
			px = i;
		}
	}		
	cout<<(n - mx)<<"\n";
	for(int i=0;i<64;i++)
	{
		if(i != px)
		{
			for(auto u : Z[i])
			cout<<u<<" ";	
		}	
	}	
	cout<<"\n";
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