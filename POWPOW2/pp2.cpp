#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<59)
#define MV 300001
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

const int MOD1 = 1000000007;
const int MOD2 = 1000000006;
const int MOD3 = 500000003;
const int MOD4 = 500000002;
const int MOD5 = 148721;
const int MOD6 = 1681;
const int MOD7 = 2;

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
ll arr[MV], factx5[MOD5+1], invf5[MOD5+1], factx6[MV], invf6[MV], factx7[MOD7+1], invf7[MOD7+1], p41[MV];

ll modexp(ll a, ll n, ll m)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%m) * (a%m))%m;
		a = ((a%m) * (a%m))%m;
		n >>= 1;	
	}
	return res;
}

void factup(void)
{
	factx5[0] = 1; factx5[1] = 1;
	invf5[0] = 1; invf5[1] = 1;
	factx6[0] = 1; factx6[1] = 1;
	invf6[0] = 1; invf6[1] = 1;
	factx7[0] = 1; factx7[1] = 1;
	invf7[0] = 1; invf7[1] = 1;
	for(ll i=2;i<MOD5;i++)
	{
		factx5[i] = ((i%MOD5) * (factx5[i-1]%MOD5))%MOD5;
		invf5[i] = modexp(factx5[i], MOD5-2, MOD5)%MOD5;
	}	
	for(ll i=2;i<MOD7;i++)
	{
		factx7[i] = ((i%MOD7) * (factx7[i-1]%MOD7))%MOD7;
		invf7[i] = modexp(factx7[i], MOD7-2, MOD7)%MOD7;
	}
	for(ll i=2;i<MV;i++)
	{
		ll tz = i;
		ll ct = 0;
		while(!(tz % 41))
		{
			tz /= 41;
			ct++;
		}	
		p41[i] = ct + p41[i-1];
		factx6[i] = ((tz%MOD6) * (factx6[i-1]%MOD6))%MOD6;
		invf6[i] = modexp(factx6[i], MOD6-41-1, MOD6)%MOD6;
	}
	return;
}

void solve(int T)
{
	ll a,b,n;
	cin>>a>>b>>n;
	if(b == 0)
	{
		cout<<"1\n";
		return;
	}	
	else if(a == 0)
	{
		cout<<"0\n";
		return;
	}
	else if(n == 0)
	{
		ll yy = modexp(a, b, MOD1);
		cout<<yy<<"\n";
		return;
	}
	ll N = 2*n;
	ll R = n;
	ll rm5 = 1, rm6 = 0, rm7 = 1;
	if(p41[N] - p41[N-R] - p41[R] < 2)
	rm6 = ((((factx6[N]%MOD6) * (((invf6[N-R]%MOD6) * (invf6[R]%MOD6))%MOD6))%MOD6) * (modexp(41, p41[N]-p41[N-R]-p41[R], MOD6)%MOD6))%MOD6;
	ll dN = N, dR = R;
	VL NN(31), RR(31);
	for(int i=0;i<31;i++)
	{
		NN[i] = dN%MOD5;
		dN /= MOD5;
		RR[i] = dR%MOD5;
		dR /= MOD5;
	}
	for(int i=0;i<31;i++)
	{
		if(NN[i] >= RR[i])
		rm5 = ((rm5%MOD5) * (((factx5[NN[i]]%MOD5) * (((invf5[NN[i]-RR[i]]%MOD5) * (invf5[RR[i]]%MOD5))%MOD5))%MOD5))%MOD5;
		else rm5 = 0;	
	}
	dN = N, dR = R;
	for(int i=0;i<31;i++)
	{
		NN[i] = dN%MOD7;
		dN /= MOD7;
		RR[i] = dR%MOD7;
		dR /= MOD7;
	}
	for(int i=0;i<31;i++)
	{
		if(NN[i] >= RR[i])
		rm7 = ((rm7%MOD7) * (((factx7[NN[i]]%MOD7) * (((invf7[NN[i]-RR[i]]%MOD7) * (invf7[RR[i]]%MOD7))%MOD7))%MOD7))%MOD7;
		else rm7 = 0;	
	}		
	ll rm4 = ((((((rm5%MOD4) * ((((MOD4/MOD5)%MOD4) * (modexp(MOD4/MOD5, MOD5-2, MOD5)%MOD4))%MOD4))%MOD4) + (((rm6%MOD4) * ((((MOD4/MOD6)%MOD4) * (modexp(MOD4/MOD6, MOD6-41-1, MOD6)%MOD4))%MOD4))%MOD4))%MOD4) + (((rm7%MOD4) * ((((MOD4/MOD7)%MOD4) * (modexp(MOD4/MOD7, MOD7-2, MOD7)%MOD4))%MOD4))%MOD4))%MOD4;
	ll rm3 = modexp(b%MOD3, rm4, MOD3)%MOD3;
	ll rm7s2 = ((b & 1) ? 1 : 0);
	ll rm2 = ((((rm7s2%MOD2) * ((((MOD2/MOD7)%MOD2) * (modexp(MOD2/MOD7, MOD7-2, MOD7)%MOD2))%MOD2))%MOD2) + (((rm3%MOD2) * ((((MOD2/MOD3)%MOD2) * (modexp(MOD2/MOD3, MOD3-2, MOD3)%MOD2))%MOD2))%MOD2))%MOD2;
	ll rm1 = modexp(a, rm2, MOD1)%MOD1;
	cout<<rm1<<"\n";
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