#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 300001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define whoami(x) cerr<<#x<<" "<<x<<"\n";
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

struct h_llint {
  static uint64_t splitmix64(uint64_t x) {    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct h_pair{
  size_t operator()(const PLL&x)const{
    return hash<ll>()(((ll)x.ff)^(((ll)x.ss)<<32));
  }
};

typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV];
ll arr[MV];
VI G[MV];
int memo[5001][5001];

struct t3
{
	int a,b,c;
}Z[MV];

int xd(int ix, int sold, int &n)
{
	if(ix == n+1)
	return 0;
	if(memo[ix][sold] != -1)
	return memo[ix][sold];
	if(Z[ix].a > sold)
	return -MOD;
	int res = -MOD, prf = 0, ct = 0;
	for(const auto& u : G[ix])
	{
		prf += Z[u].c;
		ct++;
		if(sold - ct + Z[ix].b >= 0)
		res = max(res, prf + xd(ix+1, sold - ct + Z[ix].b, n));
	}	
	res = max(res, xd(ix+1, sold + Z[ix].b, n));
	memo[ix][sold] = res;
	return res;
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	cin>>Z[i].a>>Z[i].b>>Z[i].c;
	iota(ar, ar+n+1, 0);
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		ar[d] = ((s > ar[d]) ? s : ar[d]);
	}	
	for(int i=1;i<=n;i++)
	G[ar[i]].pb(i);
	for(int i=1;i<=n;i++)
	sort(G[i].begin(), G[i].end(), [](int A, int B){ return (Z[A].c > Z[B].c); });	
	int ans = xd(1, k, n);
	if(ans < 0)
	cout<<"-1\n";	
	else cout<<ans<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}