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

int ar[MV];
ll arr[MV];
PPLL axd[MV];

void solve(int T)
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>axd[i].ss>>axd[i].ff.ff>>axd[i].ff.ss;
	sort(axd, axd+n, [](PPLL A, PPLL B){ return ((A.ss < B.ss) || ((A.ss == B.ss) && (A.ff.ff + A.ff.ss > B.ff.ff + B.ff.ss))); });
	VL cta, ctb, ctbo;
	int ka = 0, kb = 0;
	ll tt = 0;
	for(int i=0;i<n;i++)
	{
		if(axd[i].ff.ff && axd[i].ff.ss)
		ctbo.pb(axd[i].ss);
		else if(axd[i].ff.ff)
		cta.pb(axd[i].ss);
		else if(axd[i].ff.ss)
		ctb.pb(axd[i].ss);
	}	
	VL oa, ob;
	int pa = 0, pb = 0, pbo = 0;
	while((pa < (int)cta.sz()) && (pb < (int)ctb.sz()) && (pbo < (int)ctbo.sz()) && (ka < k) && (kb < k))
	{
		if((cta[pa] + ctb[pb]) < ctbo[pbo])
		{
			oa.pb(cta[pa]);
			ob.pb(ctb[pb]);
			tt += (cta[pa] + ctb[pb]);
			pa++;
			pb++;
		}
		else
		{
			tt += ctbo[pbo];
			pbo++;
		}	
		ka++;
		kb++;
	}
	while((pbo < (int)ctbo.sz()) && (ka < k) && (kb < k))
	{
		tt += ctbo[pbo];
		pbo++;
		ka++;
		kb++;
	}	
	while((pa < (int)cta.sz()) && (pb < (int)ctb.sz()) && (ka < k) && (kb < k))
	{
		oa.pb(cta[pa]);
		ob.pb(ctb[pb]);
		tt += (cta[pa] + ctb[pb]);
		pa++;
		pb++;
		ka++;
		kb++;
	}	
	while((pb < (int)ctb.sz()) && (pbo < (int)ctbo.sz()) && (kb < k))
	{
		if(ctb[pb] < ctbo[pbo])
		{
			ob.pb(ctb[pb]);
			tt += ctb[pb];
			pb++;
			kb++;
		}	
		else
		{
			tt += ctbo[pbo];
			pbo++;
			ka++;
			kb++;
		}
	}
	while((pb < (int)ctb.sz()) && (kb < k))
	{
		ob.pb(ctb[pb]);
		tt += ctb[pb];
		pb++;
		kb++;
	}	
	while((pa < (int)cta.sz()) && (pbo < (int)ctbo.sz()) && (ka < k))
	{
		if(cta[pa] < ctbo[pbo])
		{
			oa.pb(cta[pa]);
			tt += cta[pa];
			pa++;
			ka++;
		}	
		else
		{
			tt += ctbo[pbo];
			pbo++;
			ka++;
			kb++;
		}
	}
	while((pa < (int)cta.sz()) && (ka < k))
	{
		oa.pb(cta[pa]);
		tt += cta[pa];
		pa++;
		ka++;
	}	
	if((ka < k) || (kb < k))
	{
		cout<<"-1\n";
		return;
	}	
	while(ka > k)
	{
		tt -= cta.back();
		cta.pop_back();
		ka--;
	}	
	while(kb > k)
	{
		tt -= ctb.back();
		ctb.pop_back();
		kb--;
	}
	cout<<tt<<"\n";
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

	//cin>>T;
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