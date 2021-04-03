#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

struct custom_hash {
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

int ar[MV];
ll arr[MV];

ll fx(ll x, ll n)
{
	ll tot = 0;
	ll lb = x;
	ll rb = ((x & 1) ? x : x + 1);
	while(rb < n)
	{
		//cout<<lb<<" "<<rb<<"\n";
		tot += (rb - lb + 1);
		lb <<= 1LL;
		rb = ((rb << 1LL) | 1LL);
		//cout<<lb<<" "<<rb<<"\n";
	}	
	if(lb <= n)
	tot += (n - lb + 1);	
	return tot;
}	

ll bs2(ll n, ll k)
{
	ll lo = 1;
	ll hi = n/2;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(fx(2*mid, n) >= k)
		lo = mid;
		else hi = mid - 1;	
	}
	ll res = 0;
	if(fx(2*lo, n) >= k)
	res = 2*lo;	
	lo = 1;
	hi = (n+1)/2;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		//cout<<2*mid-1<<" "<<fx(2*mid-1, n)<<"\n";
		if(fx(2*mid-1, n) >= k)
		lo = mid;
		else hi = mid - 1;	 
	}
	//cout<<2*lo-1<<" "<<fx(2*lo-1, n)<<"\n";
	if(fx(2*lo-1, n) >= k)
	res = max(res, 2*lo-1);
	return res;
}

void solve(int T)
{
	ll n,k;
	cin>>n>>k;
	ll res = bs2(n,k);
	cout<<res<<"\n";
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