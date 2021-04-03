#include <bits/stdc++.h>
using namespace std;
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
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV];
ll arr[MV], factx[MV], invf[MV];
map<PLL, ll> cxt;

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

void factup(void)
{
	factx[0] = 1;
	for(ll i=1;i<MV;i++)
	{
		factx[i] = ((i%MOD) * (factx[i-1]%MOD))%MOD;
		invf[i] = modexp(factx[i], MOD-2)%MOD;
	}	
	return;
}

void solve(int T)
{
	ll n;
	cin>>n;
	ll sx = 0;
	for(int i=0;i<2*n;i++)
	{
		cin>>arr[i];
		sx += arr[i];
	}
	if(sx % (n+1))
	{
		cout<<"0\n";
		return;
	}	
	sx /= (n+1);
	ll cs = 0;
	for(int i=0;i<2*n;i++)
	cs += (sx == arr[i]);
	if(cs < 2)
	{
		cout<<"0\n";
		return;
	}		
	multiset<ll> MC;
	for(int i=0;i<2*n;i++)
	MC.ins(arr[i]);
	MC.erase(MC.find(sx));
	MC.erase(MC.find(sx));
	while(!MC.empty())
	{
		ll a = *MC.begin();
		MC.erase(MC.begin());
		if(MC.find(sx-a) != MC.end())
		{
			MC.erase(MC.find(sx-a));
			cxt[{a, sx-a}]++;
		}
		else
		{
			cxt.clear();
			cout<<"0\n";
			return;
		}	
	}	
	ll res = (factx[n-1]%MOD), sd = 0;
	for(auto u : cxt)
	{
		if(u.ff.ff != u.ff.ss)
		sd += u.ss;	
	}
	res = ((res%MOD) * (modexp(2, sd)%MOD))%MOD;
	for(auto u : cxt)
	res = ((res%MOD) * (invf[u.ss]%MOD))%MOD;
	cout<<res<<"\n";
	cxt.clear();
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

	factup();
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