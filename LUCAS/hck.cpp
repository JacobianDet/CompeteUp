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
const int M1 = 142857;
const int M2 = 37;
const int M3 = 13;
const int M4 = 11;
const int M5 = 27;
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

ll arr[40], factx37[40], factx13[40], factx11[40], invf37[40], invf13[40], invf11[40];

ll modexp(ll a, ll n, ll p)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%p) * (a%p))%p;
		a = ((a%p) * (a%p))%p;
		n >>= 1;	
	}
	return res;
}

void factup(void)
{
	factx37[0] = 1, invf37[0] = 1;
	for(ll i=1;i<M2;i++)
	{
		factx37[i] = ((factx37[i-1]%M2) * (i%M2))%M2;
		invf37[i] = modexp(factx37[i], M2-2, M2)%M2;
	}	
	factx13[0] = 1, invf13[0] = 1;
	for(ll i=1;i<M3;i++)
	{
		factx13[i] = ((factx13[i-1]%M3) * (i%M3))%M3;
		invf13[i] = modexp(factx13[i], M3-2, M3)%M3;
	}
	factx11[0] = 1, invf11[0] = 1;
	for(ll i=1;i<M4;i++)
	{
		factx11[i] = ((factx11[i-1]%M4) * (i%M4))%M4;
		invf11[i] = modexp(factx11[i], M4-2, M4)%M4;
	}
	arr[0] = 1;
	for(ll i=1;i<M5;i++)
	{
		ll tt = i;
		if(!(tt % 3))
		tt = 1;
		arr[i] = ((arr[i-1]%M5) * (tt%M5))%M5;	
	}	
	return;		
}

void solve(int T)
{
	ll n,r;
	cin>>n>>r;
	ll m27 = 1, tn = n, tr = r, tnr = n-r, t3 = 0;
	while(tn)
	{
		ll fx = ((modexp((arr[26]%M5), tn/M5, M5)%M5) * (arr[tn%M5]%M5))%M5;
		m27 = ((m27%M5) * (fx%M5))%M5;
		t3 += (tn/3);
		tn /= 3;
	}
	ll me1 = 1, me2 = 1;
	while(tr)
	{
		ll fx = ((modexp((arr[26]%M5), tr/M5, M5)%M5) * (arr[tr%M5]%M5))%M5;
		me1 = ((me1%M5) * (fx%M5))%M5;
		t3 -= (tr/3);
		tr /= 3;
	}
	while(tnr)
	{
		ll fx = ((modexp((arr[26]%M5), tnr/M5, M5)%M5) * (arr[tnr%M5]%M5))%M5;
		me2 = ((me2%M5) * (fx%M5))%M5;
		t3 -= (tnr/3);
		tnr /= 3;
	}
	m27 = ((m27%M5) * (((modexp(me1, 17, M5)%M5) * (modexp(me2, 17, M5)%M5))%M5))%M5;
	if(t3 >= 3)
	m27 = 0;
	else m27 = ((m27%M5) * (modexp(3, t3, M5)%M5))%M5;
	VL nn(31), rr(31);
	tn = n, tr = r;
	for(int i=0;i<31;i++)
	{
		nn[i] = tn%M2;
		tn /= M2;
		rr[i] = tr%M2;
		tr /= M2;
	}
	ll m37 = 1;
	for(int i=0;i<31;i++)
	{
		if(nn[i] < rr[i])
		{
			m37 = 0;
			break;
		}	
		m37 = ((m37%M2) * (((factx37[nn[i]]%M2) * (((invf37[rr[i]]%M2) * (invf37[nn[i]-rr[i]]%M2))%M2))%M2))%M2; 	
	}
	tn = n, tr = r;
	for(int i=0;i<31;i++)
	{
		nn[i] = tn%M3;
		tn /= M3;
		rr[i] = tr%M3;
		tr /= M3;
	}
	ll m13 = 1;
	for(int i=0;i<31;i++)
	{
		if(nn[i] < rr[i])
		{
			m13 = 0;
			break;
		}	
		m13 = ((m13%M3) * (((factx13[nn[i]]%M3) * (((invf13[rr[i]]%M3) * (invf13[nn[i]-rr[i]]%M3))%M3))%M3))%M3; 	
	}
	tn = n, tr = r;
	for(int i=0;i<31;i++)
	{
		nn[i] = tn%M4;
		tn /= M4;
		rr[i] = tr%M4;
		tr /= M4;
	}
	ll m11 = 1;
	for(int i=0;i<31;i++)
	{
		if(nn[i] < rr[i])
		{
			m11 = 0;
			break;
		}	
		m11 = ((m11%M4) * (((factx11[nn[i]]%M4) * (((invf11[rr[i]]%M4) * (invf11[nn[i]-rr[i]]%M4))%M4))%M4))%M4; 	
	}
	ll a1 = ((((m27%M1) * ((M1/M5)%M1)) * (modexp((M1/M5), 17, M5)%M1))%M1);
	ll a2 = ((((m37%M1) * ((M1/M2)%M1)) * (modexp((M1/M2), M2-2, M2)%M1))%M1);
	ll a3 = ((((m13%M1) * ((M1/M3)%M1)) * (modexp((M1/M3), M3-2, M3)%M1))%M1);
	ll a4 = ((((m11%M1) * ((M1/M4)%M1)) * (modexp((M1/M4), M4-2, M4)%M1))%M1);
	ll ax = ((((((a1%M1) + (a2%M1))%M1) + (a3%M1))%M1) + (a4%M1))%M1;
	cout<<ax<<"\n";
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

	factup();
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