#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 200001
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

int ar[MV];
ll arr[MV], BIT[2][2][MV];

class fentree
{
	public: void update(int i, int n, int t1, int t2, ll v);
			ll query(int i, int t1, int t2);
};

void fentree::update(int i, int n, int t1, int t2, ll v)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[t1][t2][i] += v;
	return;	
}

ll fentree::query(int i, int t1, int t2)
{
	ll res = 0;
	for( ;i>0;i-=(i & (-i)))
	res += BIT[t1][t2][i];
	return res;	
}

void solve(int T)
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{	
		BIT[0][0][i] = 0;
		BIT[1][0][i] = 0;
		BIT[0][1][i] = 0;
		BIT[1][1][i] = 0;
		cin>>arr[i];
	}	
	fentree D;
	for(int i=1;i<=n;i+=2)
	{
		D.update(i, n, 0, 0, i*arr[i]);
		D.update(i, n, 0, 1, arr[i]);
	}	
	for(int i=2;i<=n;i+=2)
	{
		D.update(i, n, 1, 0, i*arr[i]);
		D.update(i, n, 1, 1, arr[i]);
	}
	ll tx = 0;
	while(q--)
	{
		char c;
		cin>>c;
		if(c == 'U')
		{
			int idx;
			ll v;
			cin>>idx>>v;
			if(idx & 1)
			{
				D.update(idx, n, 0, 0, -idx*arr[idx]);
				D.update(idx, n, 0, 1, -arr[idx]);
				arr[idx] = v;
				D.update(idx, n, 0, 0, idx*arr[idx]);
				D.update(idx, n, 0, 1, arr[idx]);
			}
			else
			{
				D.update(idx, n, 1, 0, -idx*arr[idx]);
				D.update(idx, n, 1, 1, -arr[idx]);
				arr[idx] = v;
				D.update(idx, n, 1, 0, idx*arr[idx]);
				D.update(idx, n, 1, 1, arr[idx]);
			}
		}
		else
		{
			int lx,rx;
			cin>>lx>>rx;
			ll s1 = (D.query(rx, 0, 0) - D.query(lx-1, 0, 0)) - (1LL*lx-1) * (D.query(rx, 0, 1) - D.query(lx-1, 0, 1));
			ll s2 = (D.query(rx, 1, 0) - D.query(lx-1, 1, 0)) - (1LL*lx-1) * (D.query(rx, 1, 1) - D.query(lx-1, 1, 1));
			if(lx & 1)
			tx += (s1-s2);
			else tx += (s2-s1);	
		}
	}
	cout<<"Case #"<<T<<": "<<tx<<"\n";
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