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

int ar[MV], rk[MV];
ll arr[MV], sze[MV];

struct qry
{
	int tp, s, d, w;
};

vector<qry> Q;

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);
};

int dsu::root(int x)
{
	return (x == ar[x]) ? x : (ar[x] = root(ar[x]));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rk[rx] < rk[ry])
	{
		int tp = ry;
		ry = rx;
		rx = tp;
	}	
	ar[ry] = rx;
	sze[rx] += sze[ry];
	if(rk[rx] == rk[ry])
	rk[rx]++;
	return; 
}

bool cmpx(qry A, qry B)
{
	if(A.w < B.w)
	return 1;
	else if((A.tp < B.tp) && (A.w == B.w))
	return 1;
	else return 0;
}

void solve(int T)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int s,d,w;
		std::cin>>s>>d>>w;
		Q.pb({0, s, d, w});
	}	
	for(int i=0;i<m;i++)
	{
		int w;
		std::cin>>w;
		Q.pb({1, i, -1, w});
	}	
	std::sort(Q.begin(), Q.end(), cmpx);
	dsu Z;
	for(int i=1;i<=n;i++)
	{
		ar[i] = i;
		sze[i] = 1LL;
		rk[i] = 0;
	}
	ll ax = 0;
	for(auto u : Q)
	{
		if(!u.tp)
		{	
			if(Z.root(u.s) != Z.root(u.d))
			ax += sze[Z.root(u.s)] * sze[Z.root(u.d)];
			Z.find_union(u.s, u.d);
		}	
		else arr[u.s] = ax;
	}
	for(int i=0;i<m;i++)
	std::cout<<arr[i]<<" ";
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