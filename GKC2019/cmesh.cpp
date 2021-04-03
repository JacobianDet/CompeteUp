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

int ar[MV],rk[MV];
ll arr[MV];

class dsu
{
	public: int root(int x);
			bool find_union(int x, int y);
};

int dsu::root(int x)
{
	return (x == ar[x]) ? x : (ar[x] = root(ar[x]));
}

bool dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return 1;
	if(rk[rx] < rk[ry])
	{
		int tp = rx;
		rx = ry;
		ry = tp;
	}	
	ar[ry] = rx;
	if(rk[rx] == rk[ry])
	rk[rx]++;
	return 0;	
}

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	ll sx = 0, cp = n;
	for(int i=1;i<=n;i++)
	{
		ar[i] = i;
		rk[i] = 0;
	}	
	dsu Z;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		if(!Z.find_union(s, d))
		{
			sx++;	
			cp--;
		}	
	}	
	sx += 2*(cp - 1);
	std::cout<<"Case #"<<T<<": "<<sx<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	solve(t);
	return 0;
}