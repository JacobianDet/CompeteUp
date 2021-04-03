#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 500001
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

int ar[MV];
ll arr[MV];

struct v3
{
	int l,r,idx;
}qry[MV];

struct x3
{
	int sx;
	int basis[20];
	x3();
	void add(int vx);
	int mval(int vx);
}res[MV], sol[MV];

x3::x3()
{
	memset(basis, 0, sizeof(basis));
	sx = 0;
}

void x3::add(int vx)
{
	for(int i=19;i>=0;i--)
	{
		if(!(vx & (1<<i))) continue;
		if(!basis[i])
		{
			basis[i] = vx;
			sx++;
			return;
		}
		vx ^= basis[i];
	}
	return;
}

int x3::mval(int vx)
{
	for(int i=19;i>=0;i--)
	{
		if(!basis[i])
		continue;
		if(!(vx & (1<<i)))
		vx ^= basis[i];	
	}
	return vx;
}

void dc_solve(VI &qzx, int l, int r)
{
	if(qzx.empty())
	return;
	VI lzx, rzx;
	if((r - l + 1) <= 20)
	{
		for(auto &&u : qzx)
		{
			for(int i=qry[u].l;i<=qry[u].r;i++)
			res[u].add(ar[i]);
		}
		return;
	}	
	int mid = (l + r) >> 1;
	x3 amma;
	for(int i=mid;i>=l;i--)
	{
		amma.add(ar[i]);
		sol[i] = amma;
	}
	amma = x3();
	for(int i=mid+1;i<=r;i++)
	{
		amma.add(ar[i]);
		sol[i] = amma;
	}
	for(auto &&u : qzx)
	{
		if(qry[u].l > mid)
		rzx.pb(u);
		else if(qry[u].r < mid)
		lzx.pb(u);
		else
		{
			for(int i=19;i>=0;i--)
			{
				res[u].add(sol[qry[u].l].basis[i]);
				res[u].add(sol[qry[u].r].basis[i]);
			}	
		}	
	}
	qzx.clear();
	dc_solve(lzx, l, mid-1);
	dc_solve(rzx, mid+1, r);
	return;
}

void solve(int T)
{
	int n = readInt();
	for(int i=1;i<=n;i++)
	ar[i] = readInt();
	int q = readInt();
	VI qzx;
	for(int i=0;i<q;i++)
	{
		qry[i].l = readInt();
		qry[i].r = readInt();
		qry[i].idx = i;
		qzx.pb(i);
	}	
	dc_solve(qzx, 1, n);
	for(int i=0;i<q;i++)
	printf("%d\n", res[i].mval(0));
	return;
}

int main(void)
{
	// FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	while(T--)
	solve(T);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}