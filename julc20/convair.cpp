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

int ar[MV], rk[MV];
vector<PII> res;
set<PPII> ofdx;
multiset<PII> brc[MV], nbc[MV];

class dsu
{
	public: int root(int x);
			bool find_union(int x, int y);
}D;

int dsu::root(int x)
{
	return ((x == ar[x]) ? x : (ar[x] = root(ar[x])));
}

bool dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return 0;
	if(rk[rx] < rk[ry])
	swap(rx, ry);
	ar[ry] = rx;
	if(rk[rx] == rk[ry])
	rk[rx]++;
	return 1;	
}

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ar[i] = i;
		rk[i] = 0;
	}
	for(int i=0;i<m;i++)
	{
		int s,d;
		cin>>s>>d;
		int rs = D.root(s);
		int rd = D.root(d);
		if(D.find_union(s, d))
		{
			nbc[D.root(s)].ins({s, d});
			int ott = ((rs == D.root(rs)) ? rd : rs);
			for(auto &&u : brc[ott])
			brc[D.root(ott)].ins(u);
			brc[ott].clear();
			for(auto &&u : nbc[ott])
			nbc[D.root(ott)].ins(u);
			nbc[ott].clear();	
		}
		else brc[D.root(s)].ins({s, d});
	}	
	for(int i=1;i<=n;i++)
	{
		if(i == D.root(i))
		ofdx.ins({{-(int)brc[D.root(i)].sz(), -(int)nbc[D.root(i)].sz()}, D.root(i)});
	}
	int uy = 0;
	while((int)ofdx.sz() > 1)
	{
		PPII px1 = *ofdx.begin();
		ofdx.erase(ofdx.begin());
		PPII px2 = *ofdx.begin();
		ofdx.erase(ofdx.begin());
		px1.ff.ff = -px1.ff.ff;
		px1.ff.ss = -px1.ff.ss;
		px2.ff.ff = -px2.ff.ff;
		px2.ff.ss = -px2.ff.ss;
		if(px1.ff.ff && px2.ff.ff)
		{
			PII pf1 = *brc[px1.ss].begin();
			brc[px1.ss].erase(brc[px1.ss].begin());
			PII pf2 = *brc[px2.ss].begin();
			brc[px2.ss].erase(brc[px2.ss].begin());
			int rn1 = D.root(px1.ss);
			int rn2 = D.root(px2.ss);
			D.find_union(px1.ss, px2.ss);
			int ott = ((rn1 == D.root(rn1)) ? rn2 : rn1);
			for(auto &&u : brc[ott])
			brc[D.root(ott)].ins(u);
			brc[ott].clear();
			for(auto &&u : nbc[ott])
			nbc[D.root(ott)].ins(u);
			nbc[ott].clear();	
			brc[D.root(ott)].ins({pf1.ss, pf2.ss});
			nbc[D.root(ott)].ins({pf1.ff, pf2.ff});
			ofdx.ins({{-(int)brc[D.root(ott)].sz(), -(int)nbc[D.root(ott)].sz()}, D.root(ott)});
		}
		else if(!px1.ff.ff && !px2.ff.ff)
		{
			int rn1 = D.root(px1.ss);
			int rn2 = D.root(px2.ss);
			D.find_union(px1.ss, px2.ss);
			int ott = ((rn1 == D.root(rn1)) ? rn2 : rn1);
			for(auto &&u : nbc[ott])
			nbc[D.root(ott)].ins(u);
			nbc[ott].clear();	
			nbc[D.root(ott)].ins({px1.ss, px2.ss});
			uy += 2;
			ofdx.ins({{-(int)brc[D.root(ott)].sz(), -(int)nbc[D.root(ott)].sz()}, D.root(ott)});
		}
		else if(px2.ff.ss)
		{
			PII pf1 = *brc[px1.ss].begin();
			brc[px1.ss].erase(brc[px1.ss].begin());
			PII pf2 = *nbc[px2.ss].begin();
			nbc[px2.ss].erase(nbc[px2.ss].begin());
			int rn1 = D.root(px1.ss);
			int rn2 = D.root(px2.ss);
			D.find_union(px1.ss, px2.ss);
			int ott = ((rn1 == D.root(rn1)) ? rn2 : rn1);
			for(auto &&u : brc[ott])
			brc[D.root(ott)].ins(u);
			brc[ott].clear();
			for(auto &&u : nbc[ott])
			nbc[D.root(ott)].ins(u);
			nbc[ott].clear();	
			nbc[D.root(ott)].ins({pf1.ff, pf2.ff});
			nbc[D.root(ott)].ins({pf1.ss, pf2.ss});
			ofdx.ins({{-(int)brc[D.root(ott)].sz(), -(int)nbc[D.root(ott)].sz()}, D.root(ott)});
		}
		else
		{
			uy += 2;
			PII pf1 = *brc[px1.ss].begin();
			brc[px1.ss].erase(brc[px1.ss].begin());
			int rn1 = D.root(px1.ss);
			int rn2 = D.root(px2.ss);
			D.find_union(px1.ss, px2.ss);
			int ott = ((rn1 == D.root(rn1)) ? rn2 : rn1);
			nbc[D.root(ott)].ins({pf1.ff, px2.ss});	
			if((int)ofdx.sz() > 0)
			{
				PPII px2 = *ofdx.begin();
				ofdx.erase(ofdx.begin());
				px2.ff.ff = -px2.ff.ff;
				px2.ff.ss = -px2.ff.ss;
				rn1 = D.root(px1.ss);
				rn2 = D.root(px2.ss);
				D.find_union(px1.ss, px2.ss);
				ott = ((rn1 == D.root(rn1)) ? rn2 : rn1);
				nbc[D.root(ott)].ins({pf1.ss, px2.ss});
			}
			ofdx.ins({{-(int)brc[D.root(ott)].sz(), -(int)nbc[D.root(ott)].sz()}, D.root(ott)});
		}	
	}
	int xf = ofdx.begin()->ss;
	ofdx.clear();
	for(auto &&u : nbc[xf])
	res.pb(u);
	for(auto &&u : brc[xf])
	res.pb(u);	
	cout<<uy<<" "<<(int)res.sz()<<"\n";
	for(auto &&u : res)
	cout<<u.ff<<" "<<u.ss<<"\n";
	for(int i=1;i<=n;i++)
	{
		nbc[i].clear();
		brc[i].clear();
	}
	res.clear();	
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

	cin>>T;
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