#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
//ordered_set = order_by_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], br[MV];
ll arr[MV];

void solve(int T, int S)
{
	if(S == 1)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>ar[i];
		for(int i=0;i<n;i++)
		cin>>br[i];
		sort(ar, ar+n);
		sort(br, br+n);
		bool ok = 1;
		SI xfz;
		for(int i=0;i<n;i++)
		{
			if(ar[i] >= br[i])
			{
				ok = 0;
				break;
			}
			if((i > 0) && (xfz.find(ar[i]) == xfz.end()))
			{
				ok = 0;
				break;
			}	
			xfz.ins(ar[i]);
			xfz.ins(br[i]);
		}	
		if(ok)
		cout<<"YES\n";
		else cout<<"NO\n";	
	}
	else
	{
		int n;
		cin>>n;
		// for(int i=0;i<n;i++)
		multiset<int> xfz1, xfz2;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			xfz1.ins(t);
		}
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			xfz2.ins(t);
		}
		bool ok = 0, fin = 1;
		while(((int)xfz1.sz() > 0) && ((int)xfz2.sz() > 0))
		{
			if(!ok)
			{
				int d1 = *xfz1.begin();
				// xfz1.erase(xfz1.begin());
				auto it = xfz2.upper_bound(d1);
				if(it == xfz2.end())
				ok = 1;
				else
				{
					xfz1.erase(xfz1.begin());
					xfz2.erase(it);
				}
			}
			else
			{
				int d1 = *xfz2.begin();
				auto it = xfz1.upper_bound(d1);
				if(it == xfz1.end())
				{
					fin = 0;
					break;
				}	
				else
				{
					xfz2.erase(xfz2.begin());
					xfz1.erase(it);
				}
			}	
		}
		if(fin)
		cout<<"YES\n";
		else cout<<"NO\n";	
	}
	return;
}

int main(void)
{
	FLASH();
	int T, S;
	T = 1;

#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif

	cin>>T>>S;
	while(T--)
	solve(T, S);

#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif

	return 0;
}