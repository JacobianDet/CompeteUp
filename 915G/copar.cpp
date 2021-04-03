#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 2000001
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

int ar[MV], lo[MV], mu[MV], f[MV], mexp[MV];

void siever(int yt)
{
	for(int i=1;i<=yt;i++)
	{
		lo[i] = i;
		mu[i] = 1;
	}	
	for(int p=2;p*p<=yt;p++)
	{
		if(lo[p] == p)
		{
			for(int i=p*p;i<=yt;i+=((p == 2) ? p : 2*p))
			{
				if(lo[i] == i)
				lo[i] = p;	
			}	
		}
	}
	for(int i=2;i<=yt;i++)
	{
		if(lo[i/lo[i]] == lo[i])
		mu[i] = 0;
		else mu[i] = -1 * mu[i/lo[i]];	
	}	
	return;	
}

int modexp(int a, int n)
{
	int res = 1;
	while(n)
	{
		if(n & 1)
		res = ((1LL*res%MOD) * (1LL*a%MOD))%MOD;
		a = ((1LL*a%MOD) * (1LL*a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

void solve(int T)
{
	int n = readInt();
	int k = readInt();
	siever(k);
	for(int i=1;i<=k;i++)
	mexp[i] = modexp(i, n);	
	int rz = 0, uz = 0;
	for(int i=1;i<=k;i++)
	{
		VI dv;
		int tu = i;
		while(tu > 1)
		{
			int u = lo[tu];
			while(!(tu % u))
			tu /= u;
			dv.pb(u);
		}
		int sx = (int)dv.sz();
		for(int mask=0;mask<(1<<sx);mask++)
		{
			int u = 1;
			for(int j=0;j<sx;j++)
			{
				if(mask & (1<<j))
				u *= dv[j];	
			}	
			int vz = (MOD + mu[u])%MOD;
			uz = (1LL*uz - (1LL*vz * f[u]) + MOD)%MOD;
			f[u] = mexp[i/u];
			uz = (1LL*uz + (1LL*vz * f[u]))%MOD;
		}	
		rz = (1LL*rz + (uz ^ i))%MOD;
	}
	string vd = to_string(rz);
	for(auto &&u : vd)
	putchar(u);
	putchar('\n');	
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

	//cin>>T;
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