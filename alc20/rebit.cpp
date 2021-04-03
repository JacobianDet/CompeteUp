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

const int MOD = 998244353;

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

struct c4
{
	ll c0, c1, ca, cA;
}memo[MV];

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

void solve(int T)
{
	string s;
	cin>>s;
	int n = (int)s.sz();
	stack<int> S1, S2;
	for(int i=0;i<n;i++)
	{
		memo[i] = {0, 0, 0, 0};
		if(s[i] == '#')
		S1.push(i);
		else if(s[i] == '(')
		continue;
		else if(s[i] == ')')
		{
			S1.push(S2.top());
			S2.pop();
		}	
		else S2.push(i);	
	}	
	VI exd;
	while(!S1.empty())
	{
		exd.pb(S1.top());
		S1.pop();
	}
	reverse(begin(exd), end(exd));
	for(auto &&u : exd)
	{
		if(s[u] == '#')
		{
			memo[u].c0 = modexp(4, MOD-2)%MOD;
			memo[u].c1 = modexp(4, MOD-2)%MOD;
			memo[u].ca = modexp(4, MOD-2)%MOD;
			memo[u].cA = modexp(4, MOD-2)%MOD;
			S1.push(u);
		}
		else
		{
			int y1 = S1.top();
			S1.pop();
			int y2 = S1.top();
			S1.pop();
			if(s[u] == '&')
			{
				memo[u].c0 = (((memo[y1].c0%MOD) * (((((memo[y2].c1%MOD) + (memo[y2].ca%MOD))%MOD) + (memo[y2].cA%MOD))%MOD))%MOD);
				memo[u].c0 = (((memo[u].c0%MOD) + (((memo[y2].c0%MOD) * (((((memo[y1].c1%MOD) + (memo[y1].ca%MOD))%MOD) + (memo[y1].cA%MOD))%MOD))%MOD))%MOD);
				memo[u].c0 = (((memo[u].c0%MOD) + (((((((memo[y1].c0%MOD) * (memo[y2].c0%MOD))%MOD) + (((memo[y1].ca%MOD) * (memo[y2].cA%MOD))%MOD))%MOD) + (((memo[y1].cA%MOD) * (memo[y2].ca%MOD))%MOD))%MOD))%MOD);
 				memo[u].ca = (((((memo[y1].ca%MOD) * ((memo[y2].ca%MOD) + (memo[y2].c1%MOD))%MOD)%MOD) + (((memo[y2].ca%MOD) * ((memo[y1].c1%MOD)%MOD))%MOD))%MOD);
 				memo[u].cA = (((((memo[y1].cA%MOD) * ((memo[y2].cA%MOD) + (memo[y2].c1%MOD))%MOD)%MOD) + (((memo[y2].cA%MOD) * ((memo[y1].c1%MOD)%MOD))%MOD))%MOD);
 				memo[u].c1 = ((memo[y1].c1%MOD) * (memo[y2].c1%MOD))%MOD;
 			}	
 			else if(s[u] == '|')
 			{
 				memo[u].c1 = (((memo[y1].c1%MOD) * (((((memo[y2].c0%MOD) + (memo[y2].ca%MOD))%MOD) + (memo[y2].cA%MOD))%MOD))%MOD);
				memo[u].c1 = (((memo[u].c1%MOD) + (((memo[y2].c1%MOD) * (((((memo[y1].c0%MOD) + (memo[y1].ca%MOD))%MOD) + (memo[y1].cA%MOD))%MOD))%MOD))%MOD);
				memo[u].c1 = (((memo[u].c1%MOD) + (((((((memo[y1].c1%MOD) * (memo[y2].c1%MOD))%MOD) + (((memo[y1].ca%MOD) * (memo[y2].cA%MOD))%MOD))%MOD) + (((memo[y1].cA%MOD) * (memo[y2].ca%MOD))%MOD))%MOD))%MOD);
 				memo[u].ca = (((((memo[y1].ca%MOD) * ((memo[y2].ca%MOD) + (memo[y2].c0%MOD))%MOD)%MOD) + (((memo[y2].ca%MOD) * ((memo[y1].c0%MOD)%MOD))%MOD))%MOD);
 				memo[u].cA = (((((memo[y1].cA%MOD) * ((memo[y2].cA%MOD) + (memo[y2].c0%MOD))%MOD)%MOD) + (((memo[y2].cA%MOD) * ((memo[y1].c0%MOD)%MOD))%MOD))%MOD);
 				memo[u].c0 = ((memo[y1].c0%MOD) * (memo[y2].c0%MOD))%MOD;
 			}
 			else
 			{
 				memo[u].c0 = (((((memo[y1].c0%MOD) * (memo[y2].c0%MOD))%MOD) + (((memo[y1].c1%MOD) * (memo[y2].c1%MOD))%MOD))%MOD);
 				memo[u].c0 = (((memo[u].c0%MOD) + (((((memo[y1].ca%MOD) * (memo[y2].ca%MOD))%MOD) + (((memo[y1].cA%MOD) * (memo[y2].cA%MOD))%MOD))%MOD))%MOD);
 				memo[u].ca = (((((memo[y1].ca%MOD) * (memo[y2].c0%MOD))%MOD) + (((memo[y1].cA%MOD) * (memo[y2].c1%MOD))%MOD))%MOD);
 				memo[u].ca = (((memo[u].ca%MOD) + (((((memo[y1].c0%MOD) * (memo[y2].ca%MOD))%MOD) + (((memo[y1].c1%MOD) * (memo[y2].cA%MOD))%MOD))%MOD))%MOD);
 				memo[u].cA = (((((memo[y1].cA%MOD) * (memo[y2].c0%MOD))%MOD) + (((memo[y1].ca%MOD) * (memo[y2].c1%MOD))%MOD))%MOD);
 				memo[u].cA = (((memo[u].cA%MOD) + (((((memo[y1].c0%MOD) * (memo[y2].cA%MOD))%MOD) + (((memo[y1].c1%MOD) * (memo[y2].ca%MOD))%MOD))%MOD))%MOD);
 				memo[u].c1 = (((((memo[y1].c0%MOD) * (memo[y2].c1%MOD))%MOD) + (((memo[y1].c1%MOD) * (memo[y2].c0%MOD))%MOD))%MOD);
 				memo[u].c1 = (((memo[u].c1%MOD) + (((((memo[y1].ca%MOD) * (memo[y2].cA%MOD))%MOD) + (((memo[y1].cA%MOD) * (memo[y2].ca%MOD))%MOD))%MOD))%MOD);
 			}
 			S1.push(u);	
		}
	}
	int yx = S1.top();
	S1.pop();
	cout<<memo[yx].c0<<" "<<memo[yx].c1<<" "<<memo[yx].ca<<" "<<memo[yx].cA<<"\n";
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