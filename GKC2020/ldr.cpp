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

int ar[MV], lid[MV], rid[MV], sze[MV], lvl[MV], P[MV][LMV];
ll arr[MV];
VI G[MV];

class sparse
{
	public: void build(int n);
			int LCA_find(int p, int q);
			int anc(int p, int dx);
}D;

void dfs_visit(int s, int p)
{
	P[s][0] = p;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];	
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

int sparse::anc(int p, int dx)
{
	int lx = 0;
	for(lx=0;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if(dx >= (1<<i))
		{
			p = P[p][i];
			dx -= (1<<i);
		}	
	}	
	return p;
}

int bs1(int nd, int k)
{
	int lo = 0;
	int hi = lvl[nd];
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(sze[D.anc(nd, mid)] >= k)
		hi = mid;
		else lo = mid + 1;	
	}
	return D.anc(nd, lo);
}

void solve(int T)
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{	
		lid[i] = 0;
		rid[i] = n;
		cin>>ar[i];
	}
	ar[0] = MOD;
	ar[n] = MOD; 
	stack<int> S;
	for(int i=1;i<n;i++)
	{
		if(S.empty())
		S.push(i);
		else
		{
			while(!S.empty() && (ar[S.top()] < ar[i]))
			S.pop();
			if(!S.empty())
			lid[i] = S.top();
			S.push(i);	
		}
	}
	while(!S.empty())	
	S.pop();
	for(int i=n-1;i>0;i--)
	{
		if(S.empty())
		S.push(i);
		else
		{
			while(!S.empty() && (ar[S.top()] < ar[i]))
			S.pop();
			if(!S.empty())
			rid[i] = S.top();
			S.push(i);	
		}	
	}
	int s = -1;
	for(int i=1;i<n;i++)
	{
		if(ar[lid[i]] < ar[rid[i]])
		G[lid[i]].pb(i);	
		else if(ar[lid[i]] > ar[rid[i]])
		G[rid[i]].pb(i);
		else s = i;	
	}	
	for(int i=1;i<n;i++)
	sort(begin(G[i]), end(G[i]));	
	dfs_visit(s, -1);
	D.build(n-1);
	cout<<"Case #"<<T<<": ";
	while(q--)
	{
		int u,k;
		cin>>u>>k;
		k--;
		int x = ((ar[u-1] < ar[u]) ? u-1 : u);
		int y = bs1(x, k);
		if(x == y)
		{
			if(x == u-1)
			cout<<u-k<<" ";
			else cout<<u+k<<" ";	
		}	
		else
		{
			if(x < y)
			cout<<(y + (k-sze[G[y][0]]))<<" ";
			else cout<<(y + 1 - (k-sze[G[y][(sz(G[y])-1)]]))<<" ";	
		}
	}
	for(int i=1;i<n;i++)
	G[i].clear();	
	cout<<"\n";
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
	for(auto _=1;_<=T;_++)
	solve(_);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cerr<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}