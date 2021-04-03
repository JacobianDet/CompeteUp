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
vector<PLL> cfx;

int teq(int a, int b, int c)
{
	if((cfx[a].ff == cfx[a].ss) && (cfx[b].ff == cfx[b].ss))
	return 1;
	else return 3;
}

int sch(int a, int b, int c)
{
	if((cfx[a].ff == cfx[a].ss) && ((cfx[b].ss - cfx[b].ff) == (cfx[c].ss - cfx[c].ff)))
	return 1;
	if(((cfx[a].ss - cfx[a].ff) == (cfx[b].ss - cfx[b].ff)) && ((cfx[b].ss - cfx[b].ff) == (cfx[c].ss - cfx[c].ff)))
	return 1;
	if(cfx[a].ff == cfx[a].ss)
	return 2;	
	if((cfx[b].ss - cfx[b].ff) == (cfx[c].ss - cfx[c].ff))
	return 2;	
	if((cfx[a].ss - cfx[a].ff) + (cfx[b].ss - cfx[b].ff) == (cfx[c].ss - cfx[c].ff))
	return 2;
	return 3;	
}

int mch(int a, int b, int c)
{
	if((cfx[a].ff == cfx[a].ss) && abs(cfx[b].ff) && abs(cfx[c].ff) && !((abs(cfx[b].ss) % abs(cfx[b].ff))) && !((abs(cfx[c].ss) % abs(cfx[c].ff))) && ((cfx[b].ss/cfx[b].ff) == (cfx[c].ss/cfx[c].ff)))
	return 1;
	if(abs(cfx[a].ff) && abs(cfx[b].ff) && (abs(cfx[c].ff)) && !((abs(cfx[a].ss) % abs(cfx[a].ff))) && !((abs(cfx[b].ss) % abs(cfx[b].ff))) && !((abs(cfx[c].ss) % abs(cfx[c].ff))) && ((cfx[a].ss/cfx[a].ff) == (cfx[b].ss/cfx[b].ff)) && ((cfx[b].ss/cfx[b].ff) == (cfx[c].ss/cfx[c].ff)))
	return 1;
	if(cfx[a].ff == cfx[a].ss)
	return 2;
	if(abs(cfx[b].ff) && abs(cfx[c].ff) && !((abs(cfx[b].ss) % abs(cfx[b].ff))) && !((abs(cfx[c].ss) % abs(cfx[c].ff))) && ((cfx[b].ss/cfx[b].ff) == (cfx[c].ss/cfx[c].ff)))
	return 2;	
	if(abs(cfx[a].ff) && abs(cfx[b].ff) && (abs(cfx[c].ff)) && !((abs(cfx[a].ss) % abs(cfx[a].ff))) && !((abs(cfx[b].ss) % abs(cfx[b].ff))) && !((abs(cfx[c].ss) % abs(cfx[c].ff))) && ((cfx[a].ss/cfx[a].ff) * (cfx[b].ss/cfx[b].ff) == (cfx[c].ss/cfx[c].ff)))
	return 2;
	return 3;		
}

int smx(int a, int b, int c)
{
	if(abs(cfx[a].ff) && !(abs(cfx[a].ss) % abs(cfx[a].ff)) && (((cfx[a].ss/cfx[a].ff) * cfx[b].ff + (cfx[c].ss - cfx[c].ff)) == cfx[b].ss))
	return 2;
	if(abs(cfx[a].ff) && !(abs(cfx[a].ss) % abs(cfx[a].ff)) && (((cfx[a].ss/cfx[a].ff) * (cfx[b].ff + (cfx[c].ss - cfx[c].ff))) == cfx[b].ss))
	return 2;
	if(abs(cfx[a].ff) && !(abs(cfx[a].ss) % abs(cfx[a].ff)) && ((cfx[b].ss - (cfx[a].ss/cfx[a].ff) * cfx[b].ff) == (cfx[c].ss - (cfx[a].ss/cfx[a].ff) * cfx[c].ff)))
	return 2;
	if(abs(cfx[a].ff) && abs(cfx[b].ff) && !(abs(cfx[a].ss - cfx[c].ss + cfx[c].ff) % abs(cfx[a].ff)) && !(abs(cfx[b].ss - cfx[c].ss + cfx[c].ff) % abs(cfx[b].ff)) && ((cfx[a].ss - cfx[c].ss + cfx[c].ff)/cfx[a].ff) == ((cfx[b].ss - cfx[c].ss + cfx[c].ff)/cfx[b].ff))
	return 2;
	if(abs(cfx[a].ff + cfx[c].ss - cfx[c].ff) && abs(cfx[b].ff + cfx[c].ss - cfx[c].ff) && !(abs(cfx[a].ss) % abs(cfx[a].ff + cfx[c].ss - cfx[c].ff)) && !(abs(cfx[b].ss) % abs(cfx[b].ff + cfx[c].ss - cfx[c].ff)) && ((cfx[a].ss/(cfx[a].ff + cfx[c].ss - cfx[c].ff)) == (cfx[b].ss/(cfx[b].ff + cfx[c].ss - cfx[c].ff))))
	return 2;	
	return 3;	
}

int lc(int a, int b, int c)
{
	if(abs(cfx[a].ff - cfx[b].ff) && !(abs(cfx[a].ss - cfx[b].ss) % abs(cfx[a].ff - cfx[b].ff)) && !(abs(cfx[a].ss * cfx[b].ff - cfx[b].ss * cfx[a].ff) % abs(cfx[a].ff - cfx[b].ff)) && (cfx[c].ff * (cfx[b].ss - cfx[a].ss) + (cfx[a].ss * cfx[b].ff - cfx[b].ss * cfx[a].ff) == cfx[c].ss * (cfx[b].ff - cfx[a].ff)))
	return 2;
	return 3;
}

void solve(int T)
{
	cfx.resize(3);
	for(auto &&u : cfx)
	cin>>u.ff;
	for(auto &&u : cfx)
	cin>>u.ss;
	if((cfx[0].ff == cfx[0].ss) && (cfx[1].ff == cfx[1].ss) && (cfx[2].ff == cfx[2].ss))
	cout<<"0\n";
	else
	{
		int mm = 3;
		vector<VI> gf = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
		for(auto &&u : gf)
		{
			mm = min(mm, teq(u[0], u[1], u[2]));
			mm = min(mm, sch(u[0], u[1], u[2]));
			mm = min(mm, mch(u[0], u[1], u[2]));
			mm = min(mm, smx(u[0], u[1], u[2]));
			mm = min(mm, lc(u[0], u[1], u[2]));
		}
		cout<<mm<<"\n";	
	}
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