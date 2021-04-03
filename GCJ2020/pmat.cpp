#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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

int ar[51];
ll arr[MV];
string pt[51];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>pt[i];
	vector<string> pref, suff;
	string res = "";
	for(int i=0;i<n;i++)
	{
		string ts = "";
		int i1 = -1, i2 = -1;
		for(int j=0;j<(int)pt[i].sz();j++)
		{
			if(pt[i][j] != '*')
			ts += pt[i][j];
			else
			{
				i1 = j;
				break;
			}	
		}	
		if(ts != "")
		pref.pb(ts);
		ts = "";
		for(int j=(int)pt[i].sz()-1;j>=0;j--)
		{
			if(pt[i][j] != '*')
			ts += pt[i][j];
			else
			{
				i2 = j;
				break;
			}	
		}
		if(ts != "")
		suff.pb(ts);
		for(int j=i1+1;j<i2;j++)
		{
			if(pt[i][j] != '*')
			res += pt[i][j];	
		}	
	}
	auto f = [](string A, string B)->bool{
		return ((int)A.sz() > (int)B.sz());
	};
	sort(begin(pref), end(pref), f);
	sort(begin(suff), end(suff), f);
	bool ok = 1;
	for(int i=0;i<(int)pref.sz();i++)
	{
		for(int j=0;j<(int)pref[i].sz();j++)
		{
			if(pref[0][j] != pref[i][j])
			{
				ok = 0;
				break;
			}
		}
	}
	for(int i=0;i<(int)suff.sz();i++)
	{
		for(int j=0;j<(int)suff[i].sz();j++)
		{
			if(suff[0][j] != suff[i][j])
			{
				ok = 0;
				break;
			}
		}	
	} 	
	cout<<"Case #"<<T<<": ";
	if(!ok)
	cout<<"*\n";
	else
	{
		if((int)pref.sz() > 0)
		res = (pref[0] + res);
		if((int)suff.sz() > 0)
		{
			reverse(begin(suff[0]), end(suff[0]));
			res = (res + suff[0]);
		}	
		cout<<res<<"\n";
	}
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

// #ifndef ONLINE_JUDGE
// 	time_t time_t1, time_t2;
// 	time_t1 = clock();
// #endif

	cin>>T;
	for(auto _=1;_<=T;_++)
	solve(_);

// #ifndef ONLINE_JUDGE
// 	time_t2 = clock();
// 	SETF();
// 	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
// 	UNSETF();
// #endif

	return 0;
}