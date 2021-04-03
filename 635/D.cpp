#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<62)
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

int ar[3];
ll amk[3][MV];
ll arr[MV];

ll bs1(int ty, ll nx, ll df)
{
	ll lo = 0;
	ll hi = nx-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(amk[ty][mid] >= df)
		hi = mid;
		else lo = mid + 1;	
	}
	if(amk[ty][lo] >= df)
	lo = amk[ty][lo];
	else lo = -1;
	return lo;	
}

ll bs2(int ty, ll nx, ll df)
{
	ll lo = 0;
	ll hi = nx-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(amk[ty][mid] <= df)
		lo = mid;
		else hi = mid - 1;	
	}
	if(amk[ty][lo] <= df)
	lo = amk[ty][lo];
	else lo = -1;
	return lo;	
}

ll rfz(ll t1, ll t2, ll t3)
{
	ll vf = INF;
	for(int i=0;i<ar[t1];i++)
	{	
		ll a1 = amk[t1][i], by1 = -1, by2 = -1, cy1 = -1, cy2 = -1, cy3 = -1, cy4 = -1, cy5 = -1, cy6 = -1;
		by1 = bs1(t2, ar[t2], a1);
		by2 = bs2(t2, ar[t2], a1);
		cy1 = bs1(t3, ar[t3], a1);
		cy2 = bs2(t3, ar[t3], a1);
		if(by1 != -1)
		cy3 = bs1(t3, ar[t3], by1);
		if(by1 != -1)
		cy4 = bs2(t3, ar[t3], by1);
		if(by2 != -1)
		cy5 = bs1(t3, ar[t3], by2);
		if(by2 != -1)
		cy6 = bs2(t3, ar[t3], by2);
		if((by1 != -1) && (cy1 != -1))
		vf = min(vf, (a1 - by1) * (a1 - by1) + (a1 - cy1) * (a1 - cy1) + (by1 - cy1) * (by1 - cy1));
		if((by1 != -1) && (cy2 != -1))
		vf = min(vf, (a1 - by1) * (a1 - by1) + (a1 - cy2) * (a1 - cy2) + (by1 - cy2) * (by1 - cy2));
		if((by1 != -1) && (cy3 != -1))
		vf = min(vf, (a1 - by1) * (a1 - by1) + (a1 - cy3) * (a1 - cy3) + (by1 - cy3) * (by1 - cy3));
		if((by1 != -1) && (cy4 != -1))
		vf = min(vf, (a1 - by1) * (a1 - by1) + (a1 - cy4) * (a1 - cy4) + (by1 - cy4) * (by1 - cy4));
		if((by1 != -1) && (cy5 != -1))
		vf = min(vf, (a1 - by1) * (a1 - by1) + (a1 - cy5) * (a1 - cy5) + (by1 - cy5) * (by1 - cy5));
		if((by1 != -1) && (cy6 != -1))
		vf = min(vf, (a1 - by1) * (a1 - by1) + (a1 - cy6) * (a1 - cy6) + (by1 - cy6) * (by1 - cy6));
		if((by2 != -1) && (cy1 != -1))
		vf = min(vf, (a1 - by2) * (a1 - by2) + (a1 - cy1) * (a1 - cy1) + (by2 - cy1) * (by2 - cy1));
		if((by2 != -1) && (cy2 != -1))
		vf = min(vf, (a1 - by2) * (a1 - by2) + (a1 - cy2) * (a1 - cy2) + (by2 - cy2) * (by2 - cy2));
		if((by2 != -1) && (cy3 != -1))
		vf = min(vf, (a1 - by2) * (a1 - by2) + (a1 - cy3) * (a1 - cy3) + (by2 - cy3) * (by2 - cy3));
		if((by2 != -1) && (cy4 != -1))
		vf = min(vf, (a1 - by2) * (a1 - by2) + (a1 - cy4) * (a1 - cy4) + (by2 - cy4) * (by2 - cy4));
		if((by2 != -1) && (cy5 != -1))
		vf = min(vf, (a1 - by2) * (a1 - by2) + (a1 - cy5) * (a1 - cy5) + (by2 - cy5) * (by2 - cy5));
		if((by2 != -1) && (cy6 != -1))
		vf = min(vf, (a1 - by2) * (a1 - by2) + (a1 - cy6) * (a1 - cy6) + (by2 - cy6) * (by2 - cy6));
	}
	return vf;
}

void solve(int T)
{
	cin>>ar[0]>>ar[1]>>ar[2];
	for(int i=0;i<ar[0];i++)
	cin>>amk[0][i];
	for(int i=0;i<ar[1];i++)
	cin>>amk[1][i];
	for(int i=0;i<ar[2];i++)
	cin>>amk[2][i];
	sort(amk[0], amk[0]+ar[0]);
	sort(amk[1], amk[1]+ar[1]);
	sort(amk[2], amk[2]+ar[2]);
	ll vf = INF;
	vf = min({vf, rfz(0, 1, 2), rfz(0, 2, 1), rfz(1, 0, 2), rfz(1, 2, 0), rfz(2, 0, 1), rfz(2, 1, 0)});
	cout<<vf<<"\n";
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