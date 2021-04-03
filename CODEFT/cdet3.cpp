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

int ar[MV], sze[MV], disc[MV], cord[MV];
ll BIT[MV];
ll arr[MV];
VI G[MV];
int tx;

class fentree
{
	public: void build(int n);
			void update(int i, int n, ll val);
			ll query(int i);
};

void fentree::build(int n)
{
	for(int i=1;i<=n;i++)
	BIT[i] = 0;
	return;	
}

void fentree::update(int i, int n, ll val)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i] += val;
	return;	
}

ll fentree::query(int i)
{
	ll ans = 0;
	for( ;i>0;i-=(i & (-i)))
	ans += BIT[i];
	return ans;	
}

struct t3
{
	int tp, nd;
	ll val;
};

bool cmpx(t3 A, t3 B)
{
	if(A.val < B.val)
	return 1;
	else if((A.val == B.val) && (A.tp < B.tp))
	return 1;
	else return 0;	
}

void dfs_visit(int s, int p)
{
	tx++;
	disc[s] = tx;
	cord[tx] = s;
	sze[s] = 1;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			sze[s] += sze[u];
		}		
	}
	return;
}

void solve(int T)
{
	tx = 0;
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	dfs_visit(1, -1);
	vector<t3> Z;
	for(int i=1;i<=n;i++)
	{
		Z.pb({1, i, arr[i]});
		Z.pb({2, i, arr[i]});
	}	
	sort(Z.begin(), Z.end(), cmpx);
	fentree D;
	D.build(n);
	ll ans = 0;
	for(auto u : Z)
	{
		if(u.tp == 1)
		ans += (D.query(disc[u.nd] + sze[u.nd] - 1) - D.query(disc[u.nd] - 1));	
		else D.update(disc[u.nd], n, u.val);
	}
	cout<<ans<<"\n";
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