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

int ar[MV], ox[MV], rk[MV];
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
	return 0;
	if(rk[rx] < rk[ry])
	{
		int tmp = rx;
		rx = ry;
		ry = tmp;
	}	
	ar[ry] = rx;
	if(rk[ry] == rk[rx])
	rk[rx]++;
	return 1;	
}

void solve(int T)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		ar[i] = i;
		rk[i] = 0;
 	}	
 	for(int i=1;i<=n;i++)
 	ox[i] = -1;
 	int et = 0;	
 	dsu Z;
 	for(int i=1;i<=k;i++)
 	{
 		int s,d;
 		std::cin>>s>>d;
 		if(ox[s] == -1)
 		ox[s] = i;
 		else 
 		{
 			if(!Z.find_union(ox[s], i))
 			et++;
 		}	
 		if(ox[d] == -1)
 		ox[d] = i;
 		else 
 		{
 			if(!Z.find_union(ox[d], i))
 			et++;
 		}
 	}	
 	cout<<et<<"\n";
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