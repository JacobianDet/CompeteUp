#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MV 100001
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
	ch = getchar_unlocked();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
 
int par[MV], sze[MV], lvl[MV], lcl[MV], P[MV][LMV];
bool mk[MV], isCrtd[MV];
int ar[MV], dst[MV];
vector<PII> G[MV];
VI CG[MV];
vector<PPII> LX[MV];
multiset<int> tnx[MV], tdx[MV], upa;
vector<multiset<int> > tzx[MV];
 
void dfs_vis1(int s, int p)
{
	lvl[s] = 0;
	P[s][0] = p;
	if(p != -1)
	lvl[s] = 1 + lvl[p];
	for(auto u : G[s])
	{
		if(u.ff != p)
		{	
			dst[u.ff] = u.ss + dst[s];
			dfs_vis1(u.ff, s);		
		}	
	}
	return;	
}
 
void dfs_vis3(int s, int p)
{
	sze[s] = 1;
	for(auto u : G[s])
	{
		if((u.ff != p) && !isCrtd[u.ff])
		{
			dfs_vis3(u.ff, s);
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
		if((u.ff != p) && !isCrtd[u.ff] && (sze[u.ff] > sze[rt]/2))
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
 
void dfs_vis2(int s, int p)
{
	dfs_vis3(s, -1);
	PII centroid = cent_find(s, -1, s);
	par[centroid.ff] = p;
	lcl[centroid.ff] = 0;
	if(p != -1)
	{	
		lcl[centroid.ff] = 1 + lcl[p];
		CG[p].pb(centroid.ff);	
	}	
	isCrtd[centroid.ff] = 1;
	for(auto u : G[centroid.ff])
	{
		if(!isCrtd[u.ff])
		dfs_vis2(u.ff, centroid.ff);	
	}
	return;
}
 
class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
}D;
 
class CDS
{
	int yt;
	public: CDS(): yt(-MOD){};
			void CDT_prep1(int s);
			void CDT_prep2(int s, int rt, int cp);
			void update(int u, int ty);
			int query();
};
 
void CDS::CDT_prep2(int s, int rt, int cp)
{
	LX[s].pb({{lcl[rt], rt}, cp});
	int dx = dst[s] + dst[rt] - 2*dst[D.LCA_find(s, rt)];
	upa.ins(dx);
	for(auto u : CG[s])
	CDT_prep2(u, rt, cp);
	return;	
}
 
void CDS::CDT_prep1(int s)
{
	int m1 = -MOD, m2 = -MOD;
	ar[s] = -MOD;
	int uy = 0;
	for(auto u : CG[s])
	{
		CDT_prep1(u);
		CDT_prep2(u, s, uy);
		tzx[s].pb(upa);
		upa.clear();
		int vv = *tzx[s][uy].rbegin();
		tnx[s].ins(vv);
		tdx[s].ins(ar[u]);
		if(m1 < vv)
		{
			m2 = m1;
			m1 = vv;
		}	
		else if((m1 >= vv) && (m2 <= vv))
		m2 = vv;	
		ar[s] = max(ar[s], ar[u]);
		uy++;
	}
	tzx[s].pb({0});
	LX[s].pb({{lcl[s], s}, uy});
	int vv = *tzx[s][uy].rbegin();
	tnx[s].ins(vv);
	tdx[s].ins(0);
	if(m1 < vv)
	{
		m2 = m1;
		m1 = vv;
	}	
	else if((m1 >= vv) && (m2 <= vv))
	m2 = vv;
	ar[s] = max(ar[s], 0);
	ar[s] = max(ar[s], m1 + m2);
	yt = max(yt, ar[s]);
	return;
}
 
void CDS::update(int u, int ty)
{
	yt = -MOD;
	int x = u;
	int pp = -MOD;
	if(ty)
	pp = -MOD;
	else pp = 0;	
	while(x != -1)
	{
		if(ty)
		{
			int ut = (lower_bound(begin(LX[u]), end(LX[u]), mp(mp(lcl[x], x), -MOD)))->ss;
			int mz = *tzx[x][ut].rbegin();
			int dt = dst[x] + dst[u] - 2*dst[D.LCA_find(x, u)];
			tzx[x][ut].erase(tzx[x][ut].find(-MOD));
			tzx[x][ut].ins(dt);
			int zz = *tzx[x][ut].rbegin();
			if(tnx[x].find(mz) != tnx[x].end())
			tnx[x].erase(tnx[x].find(mz));
			tnx[x].ins(zz);	
			int ct = 2;
			int m1 = -MOD, m2 = -MOD;
			for(auto rit = tnx[x].rbegin();((rit != tnx[x].rend()) && (ct > 0));++rit, --ct)
			{
				if(m1 == -MOD)
				m1 = *rit;
				else m2 = *rit;	
			}	
			tdx[x].erase(tdx[x].find(pp));
			if(ut < sz(CG[x]))
			tdx[x].ins(ar[CG[x][ut]]);
			else
			{
				if(mk[x])
				tdx[x].ins(0);
				else tdx[x].ins(-MOD);	
			}
			pp = ar[x];
			ar[x] = -MOD;
			zz = *tdx[x].rbegin();
			ar[x] = max({ar[x], m1 + m2, zz});
			yt = max(yt, ar[x]);
		}
		else
		{
			int ut = (lower_bound(begin(LX[u]), end(LX[u]), mp(mp(lcl[x], x), -MOD)))->ss;
			int mz = *tzx[x][ut].rbegin();
			int dt = dst[x] + dst[u] - 2*dst[D.LCA_find(x, u)];
			tzx[x][ut].erase(tzx[x][ut].find(dt));
			tzx[x][ut].ins(-MOD);
			int zz = *tzx[x][ut].rbegin();
			if(tnx[x].find(mz) != tnx[x].end())
			tnx[x].erase(tnx[x].find(mz));
			tnx[x].ins(zz);
			int ct = 2;
			int m1 = -MOD, m2 = -MOD;
			for(auto rit = tnx[x].rbegin();((rit != tnx[x].rend()) && (ct > 0));++rit, --ct)
			{
				if(m1 == -MOD)
				m1 = *rit;
				else m2 = *rit;	
			}	
			tdx[x].erase(tdx[x].find(pp));
			if(ut < sz(CG[x]))
			tdx[x].ins(ar[CG[x][ut]]);
			else
			{
				if(mk[x])
				tdx[x].ins(0);
				else tdx[x].ins(-MOD);	
			}
			pp = ar[x];
			ar[x] = -MOD;
			zz = *tdx[x].rbegin();
			ar[x] = max({ar[x], m1 + m2, zz});
			yt = max(yt, ar[x]);
		}
		x = par[x];	
	}
	return;	
}
 
int CDS::query()
{
	return yt;
}
 
void sparse::build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			P[i][j] = -1;
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];
		}	
	}
	return;
}
 
int sparse::LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tp = p;
		p = q;
		q = tp;
	}
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];
	}	
	if(p == q)
	return p;
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	return P[p][0];
}
 
void solve(int T)
{
	int n = readInt();
	for(int i=0;i<n-1;i++)
	{
		int s = readInt();
		int d = readInt();
		int w = readInt();
		G[s].pb({d, w});
		G[d].pb({s, w});
	}	
	for(int i=1;i<=n;i++)
	{	
		mk[i] = 1;
		ar[i] = -MOD;
		par[i] = -1;
	}		
	dfs_vis1(1, -1);
	dfs_vis3(1, -1);
	PII centroid = cent_find(1, -1, 1);
	dfs_vis2(1, -1);		
	D.build(n);
	CDS F;
	F.CDT_prep1(centroid.ff);
	for(int i=1;i<=n;i++)
	sort(begin(LX[i]), end(LX[i]));	
	int q = readInt();
	while(q--)
	{
		char t = getchar_unlocked();
		getchar_unlocked();
		if(t == 'C')
		{	
			int v = readInt();
			mk[v] ^= 1;
			F.update(v, mk[v]);
		}	
		else
		{
			int yt = F.query();
			if(yt == -MOD)
			{
				string ff = "They have disappeared.";
				for(auto &&u : ff)
				putchar_unlocked(u);
				putchar_unlocked('\n');	
			}	
			else
			{
				string ff = to_string(yt);
				for(auto &&u : ff)
				putchar_unlocked(u);
				putchar_unlocked('\n');
			}	
		}	
	}
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