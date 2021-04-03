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
#define sz(x) (int)x.size()
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

int readInt (void) {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int sze[MV], mxt[MV], nv[MV], lg[MV];
bool isCrtd[MV];
vector<PII> G[MV];
VI wtx;	
PII ST[MV][LMV];
vector<PPII> upa;
PII fpr;

class sparse
{
	public: void build(int n);
			PII query(int l, int r);
}D;

void sparse::build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;(i + (1<<j))<=n+1;i++)
		{	
			if(ST[i][j-1].ff < ST[i + (1<<(j-1))][j-1].ff)
			ST[i][j] = ST[i + (1<<(j-1))][j-1];
			else ST[i][j] = ST[i][j-1];
		}		
	}	
	return;
}

PII sparse::query(int l, int r)
{
	int j = lg[r - l + 1];
	PII mx = ST[l][j];
	if(mx.ff < ST[r - (1<<j) + 1][j].ff)
	mx = ST[r - (1<<j) + 1][j];
	return mx;
}

void dfs_vis2(int s, int p)
{
	sze[s] = 1;
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff])
		{
			dfs_vis2(u.ff, s);
			sze[s] += sze[u.ff];
		}	
	}
	return;
}

PII cent_find(int s, int p, int rt)
{
	PII centroid = {0, MV};
	int msz = 0;
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff] && (sze[s] > sze[rt]/2))
		{
			PII px = cent_find(u.ff, s, rt);
			if(centroid.ss > px.ss)
			centroid = px;
			msz = max(msz, sze[u.ff]);	
		}	
	}
	msz = max(msz, sze[rt] - sze[s]);
	if(centroid.ss > msz)
	centroid = {s, msz};
	return centroid;	
}

int dfs_sol2(int s, int p, int mdn, int vlx, int ht)
{
	int mht = ht;
	upa.pb({{vlx, ht}, s});
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff])
		mht = max(mht, dfs_sol2(u.ff, s, mdn, vlx + ((u.ss >= mdn) ? 1 : -1), ht + 1));	
	}
	return mht;
}

bool dfs_sol1(int s, int compsz, int mdn, int l, int r)
{	
	bool ok = 0;
	int pmht = 0, mht = 0;
	for(auto u : G[s])
	{
		if(isCrtd[u.ff] || ok)
		continue;
		mht = max(mht, dfs_sol2(u.ff, s, mdn, ((u.ss >= mdn) ? 1 : -1), 1));
		for(auto &&e : upa)
		{
			if((e.ff.ss >= l) && (e.ff.ss <= r) && (e.ff.ff >= 0))
			{
				ok = 1;
				fpr = {s, e.ss};
			}
			int lx = l - e.ff.ss;
			int rx = r - e.ff.ss;
			if((rx < 1) || (lx > pmht))
			continue;
			lx = max(lx, 1);
			rx = min(rx, pmht);
			if(lx > rx)
			continue;	
			PII yt = D.query(lx, rx);
			if((e.ff.ff + yt.ff) >= 0)
			{
				ok = 1;
				fpr = {e.ss, yt.ss};
			}		
		}
		for(auto &&e : upa)
		{
			if(mxt[e.ff.ss] < e.ff.ff)
			{
				mxt[e.ff.ss] = max(mxt[e.ff.ss], e.ff.ff);
				nv[e.ff.ss] = e.ss;
				ST[e.ff.ss][0] = {mxt[e.ff.ss], nv[e.ff.ss]};
  			}	
		}
		D.build(mht);
		upa.clear();
		pmht = mht;		
	}
	for(int i=1;i<compsz;i++)
	{	
		mxt[i] = -MV;
		nv[i] = -1;
		ST[i][0] = {mxt[i], nv[i]};
	}
	D.build(compsz);
	return ok;
}

bool dfs_vis1(int s, int mdn, int l, int r)
{
	dfs_vis2(s, -1);
	PII centroid = cent_find(s, -1, s);
	bool ok = 0;
	ok |= dfs_sol1(centroid.ff, sze[s], mdn, l, r);
	isCrtd[centroid.ff] = 1;
	for(auto u : G[centroid.ff])
	{
		if(!isCrtd[u.ff] && !ok)
		ok |= dfs_vis1(u.ff, mdn, l, r);	
	}
	return ok;
}

int bs2(int n, int l, int r)
{
	int lo = 0;
	int hi = sz(wtx)-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		fpr = {-1, -1};	
		for(int i=1;i<=n;i++)
		isCrtd[i] = 0;	
		if(dfs_vis1(1, wtx[mid], l, r))
		lo = mid;		
		else hi = mid - 1;	
	}
	return lo;
}

void solve(int T)
{
	int n,l,r;
	n = readInt();
	l = readInt();
	r = readInt();
	for(int i=0;i<n-1;i++)
	{
		int s,d,w;
		s = readInt();
		d = readInt();
		w = readInt();
		G[s].pb({d, w});
		G[d].pb({s, w});
		wtx.pb(w);
	}	
	lg[1] = 0;
	ST[1][0] = {-MV, -1};
	mxt[1] = -MV;
	nv[1] = -1;
	for(int i=2;i<MV;i++)
	{
		lg[i] = lg[i>>1] + 1;
		mxt[i] = -MV;
		nv[i] = -1;
		ST[i][0] = {-MV, -1};
	}	
	D.build(n);	
	sort(begin(wtx), end(wtx));
	wtx.resize(unique(begin(wtx), end(wtx)) - begin(wtx));
	int vl = bs2(n, l, r);
	fpr = {-1, -1};
	for(int i=1;i<=n;i++)
	isCrtd[i] = 0;	
	bool x = dfs_vis1(1, wtx[vl], l, r);
	string st = to_string(fpr.ff) + " " + to_string(fpr.ss);
	for(auto &&u : st)
	putchar(u);
	putchar('\n');	
	return;
}

int main(void)
{
	// FLASH();
	//freopen("cowjog.in", "r", stdin);
	//freopen("cowjog.out", "w", stdout);
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	//cin>>T;
	while(T--)
	solve(T);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}