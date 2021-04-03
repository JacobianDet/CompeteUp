#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 400001
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
//ordered_set = order_by_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], qz[MV], BIT[MV];
ll arr[MV];

struct ev
{
	int co, h, idx, ind;
};

class fentree
{
	public: void update(int i, int n, int v);
			int query(int i);
};

void fentree::update(int i, int n, int v)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i] += v;
	return;	
}

int fentree::query(int i)
{
	int ans = 0;
	for( ;i>0;i-=(i & (-i)))
	ans += BIT[i];
	return ans;	
}

void solve(int T)
{
	int n,q;
	cin>>n>>q;
	SL xzf;
	for(int i=1;i<=n;i++)
	{	
		cin>>ar[i];
		xzf.ins(ar[i]);
	}	
	vector<ev> Z;
	for(int i=1;i<n;i++)
	{
		Z.pb({i, i, MOD, 1});
		// Z.pb({i+1, i, MOD, -1});
	}
	for(int i=0;i<q;i++)
	{
		int x1,x2,y;
		cin>>x1>>x2>>y;
		xzf.ins(y);
		Z.pb({x1, y, i, 1});
		Z.pb({x2, y, i, -1});
	}
	int x = 0;
	UMLL xcf;
	for(auto u : xzf)
	xcf[u] = (++x);
	fentree D;
	sort(Z.begin(), Z.end(), [](ev A, ev B){ return ((A.co < B.co) || ((A.co == B.co) && (A.ind < B.ind)) || ((A.co == B.co) && (A.ind == B.ind) && (A.idx < B.idx))); });
	for(auto u : Z)
	{
		if(u.idx == MOD)
		{
			if(u.ind == 1)
			{
				int m1 = min(xcf[ar[u.h]], xcf[ar[u.h+1]]);
				int m2 = max(xcf[ar[u.h]], xcf[ar[u.h+1]])+1;
				D.update(m1, x, 1);
				D.update(m2, x, -1);
			}	
		}
		else
		{
			int z = xcf[u.h];
			if(u.ind == 1)
			qz[u.idx] -= D.query(z);
			else qz[u.idx] += D.query(z);	
		}
	}
	for(int i=0;i<=x;i++)
	BIT[i] = 0;	
	for(int i=0;i<q;i++)
	{
		cout<<qz[i]<<"\n";
		qz[i] = 0;
	}	
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

	cin>>T;
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