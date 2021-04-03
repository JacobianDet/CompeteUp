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

int ar[MV], P[MV][LMV], lvl[MV], dist[MV][101];
VI G[MV];

class sparse
{
	public: void ST_build(int n);
			int LCA_find(int p, int q);
};

void sparse::ST_build(int n)
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
	int l2 = 0;
	for(l2=1;(1<<l2)<=lvl[p];l2++);
	l2--;
	for(int i=l2;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])	
		p = P[p][i];	
	}
	if(p == q)
	return p;
	for(int i=l2;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	return P[p][0];
}

void dfs_visit(int s, int p)
{
	P[s][0] = p;
	lvl[s] = 0;
	for(int i=1;i<=100;i++)
	dist[s][i] = 0;	
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		for(int i=1;i<=100;i++)
		dist[s][i] = dist[p][i];
		dist[s][ar[s]]++;
	}
	for(auto u : G[s])
	{
		if(u != p)
		dfs_visit(u, s);	
	}	
	return;
}

void solve(int T)
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_visit(1, -1);
	sparse D;
	D.ST_build(n);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int lc = D.LCA_find(l, r);
		VI axd;
		bool ok = 1;
		for(int i=1;i<=100;i++)
		{
			int yt = dist[l][i] + dist[r][i] - 2*dist[lc][i] + (ar[lc] == i);
			if(yt > 1)
			{
				ok = 0;
				cout<<"0\n";
				break;
			}	
			else if(yt == 1)
			axd.pb(i);	
		}
		if(!ok)
		continue;	
		int fd = MV;	
		for(int i=0;i<(int)axd.sz()-1;i++)
		fd = min(fd, axd[i+1] - axd[i]);
		cout<<fd<<"\n";	
	}
	for(int i=1;i<=n;i++)
	G[i].clear();
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