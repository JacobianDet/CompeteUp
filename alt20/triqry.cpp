#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 2000020
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

int qry[MV], BIT[MV];
ll arr[MV];
PII qidx[MV];

struct x5
{
	int l,r,idx,qt,bidx;
};

class fentree
{
	public: void clr(int n);
			void update(int i, int n);
			int query(int i);
};

void fentree::clr(int n)
{
	for(int i=1;i<=n;i++)
	BIT[i] = 0;
	return;	
}

void fentree::update(int i, int n)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i]++;
	return;	
}

int fentree::query(int i)
{
	int res = 0;
	for( ;i>0;i-=(i & (-i)))
	res += BIT[i];
	return res;	
}

void solve(int T)
{
	int n,q;
	n = readInt();
	q = readInt();
	vector<x5> xfd1, xfd2;
	for(int i=0;i<n;i++)
	{
		int l,r;
		l = readInt();
		r = readInt();
		l *= 2;
		r *= 2;
		xfd1.pb({l, r, i, 2, -1});
		xfd2.pb({l, r, i, 1, -1});
	}	
	for(int i=0;i<q;i++)
	{
		int l,r;
		l = readInt();
		r = readInt();
		l *= 2;
		r *= 2;
		xfd1.pb({l, 0, i, 0, -1});
		xfd1.pb({(l+r)>>1, 0, i, 1, -1});
		xfd2.pb({(l+r)>>1, 0, i, 0, -1});
		xfd2.pb({r, 0, i, 2, -1});
	}
	auto cmp = [](x5 A, x5 B){ return ((A.l < B.l) || ((A.l == B.l) && (A.r < B.r)) || ((A.l == B.l) && (A.r == B.r) && (A.qt < B.qt))); };
	sort(begin(xfd1), end(xfd1), cmp);
	sort(begin(xfd2), end(xfd2), cmp);
	int idx = 1;
	for(auto &&u : xfd1)
	{
		if(u.qt == 2)
		{
			u.bidx = idx;
			idx++;
		}	
		else if(u.qt == 0)
		{	
			qry[u.idx] = 0;
			qidx[u.idx].ff = idx;
		}	
		else  
		{
			if(qidx[u.idx].ff < idx)
			qidx[u.idx].ss = idx-1;
			else qidx[u.idx].ff = qidx[u.idx].ss = 0;
		}
	}
	sort(begin(xfd1), end(xfd1), [](x5 A, x5 B){ return (((A.l - A.r) > (B.l - B.r)) || (((A.l - A.r) == (B.l - B.r)) && (A.qt > B.qt))); });
	fentree D;
	D.clr(n);
	for(auto &&u : xfd1)
	{
		if(u.qt == 1)
		continue;
		else if(u.qt == 2)
		D.update(u.bidx, n);
		else qry[u.idx] += (D.query(qidx[u.idx].ss) - D.query(qidx[u.idx].ff-1));
	}
	idx = 1;
	for(auto &&u : xfd2)
	{
		if(u.qt == 1)
		{
			u.bidx = idx;
			idx++;
		}	
		else if(u.qt == 0)
		qidx[u.idx].ff = idx;	
		else  
		{
			if(qidx[u.idx].ff < idx)
			qidx[u.idx].ss = idx-1;
			else qidx[u.idx].ff = qidx[u.idx].ss = 0;
		}	
	}
	sort(begin(xfd2), end(xfd2), [](x5 A, x5 B){ return (((A.l + A.r) < (B.l + B.r)) || (((A.l + A.r) == (B.l + B.r)) && (A.qt < B.qt))); });
	D.clr(n);
	for(auto &&u : xfd2)
	{
		if(u.qt == 0)
		continue;
		else if(u.qt == 1)
		D.update(u.bidx, n);
		else qry[u.idx] += (D.query(qidx[u.idx].ss) - D.query(qidx[u.idx].ff-1));
	}	
	for(int i=0;i<q;i++)
	{
		string s = to_string(qry[i]);
		for(auto &&u : s)
		putchar_unlocked(u);
		putchar_unlocked(' ');	
	}
	putchar_unlocked('\n');
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

	T = readInt();
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