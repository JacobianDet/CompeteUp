#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 200001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define emp emplace
#define mp make_pair
#define ins insert
#define sz size
#define whoami(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); whi(_it, args); }

void whi(istream_iterator<string> it) { cerr<<"\n"; }

template<typename T, typename... Args>
void whi(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<" "<<a<<" "; whi(++it, args...); }

void FLASH() {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
void SETF() {cout.ios_base::setf(ios_base::fixed); cerr.ios_base::setf(ios_base::fixed);}
void UNSETF() {cout.ios_base::unsetf(ios_base::fixed); cerr.ios_base::unsetf(ios_base::fixed);}

typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<PII, int> PPII;
typedef pair<PLL, ll> PPLL;
typedef map<int, int> MII;

const int MOD = 1000000007;
const ll INF = 4e18;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
//ordered_set = order_of_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], rk[MV], sze[MV], memo[2][MV];
ll arr[MV];

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);
};

int dsu::root(int x)
{
	return ((x == ar[x]) ? x : (ar[x] = root(ar[x])));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rk[rx] < rk[ry])
	swap(rx, ry);
	ar[ry] = rx;
	if(rk[rx] == rk[ry])
	rk[rx]++;
	sze[rx] += sze[ry];
	return;	
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	dsu D;
	for(int i=1;i<=n;i++)
	{
		ar[i] = i;
		rk[i] = 0;
		sze[i] = 1;
	}
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		D.find_union(s, d);
	}	
	VI vfx(n+1);
	vector<PII> VF;
	for(int i=1;i<=n;i++)
	{
		if(i == D.root(i))
		vfx[sze[i]]++;	
	}
	for(int i=1;i<=n;i++)
	{
		if(vfx[i])
		VF.pb({i, vfx[i]});	
	}	
	sort(begin(VF), end(VF), [](PII A, PII B){ return (A.ff < B.ff); });
	int vx = (int)VF.sz();
	memo[0][0] = 0;
	for(int i=1;i<=n;i++)
	memo[0][i] = MOD;
	for(int i=1;i<=vx;i++)
	{
		vector<VI> wts(VF[i-1].ff);
		for(int j=0;j<=n;j++)
		wts[j % VF[i-1].ff].pb(j);
		for(int j=0;j<VF[i-1].ff;j++)
		{
			deque<int> D;
			for(int k=0;k<(int)wts[j].sz();k++)
			{
				while(!D.empty() && ((k - D.front()) > VF[i-1].ss))
				D.pop_front();
				while(!D.empty() && ((k - D.back()) + memo[0][wts[j][D.back()]] >= memo[0][wts[j][k]]))
				D.pop_back();
				D.push_back(k);
				memo[1][wts[j][k]] = (k - D.front()) + memo[0][wts[j][D.front()]];	
			}
		}
		for(int j=0;j<=n;j++)
		memo[0][j] = memo[1][j];	
	}	
	int me = MOD;
	for(int i=1;i<=n;i++)
	{
		int tf = i;
		bool ok = 1;
		while(tf)
		{
			ok &= (((tf%10) == 4) || ((tf%10) == 7));
			tf /= 10;
		}
		if(ok)
		me = min(me, memo[0][i]-1);	
	}	
	cout<<((me >= MOD-1) ? -1 : me)<<"\n";
	return;
}

int main(void)
{
	FLASH();
	//freopen("cowjog.in", "r", stdin);
	//freopen("cowjog.out", "w", stdout);
	int T;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	//cin>>T;
	while(T--)
	solve(T);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}