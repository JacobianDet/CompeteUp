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
ll arr[2][MV];
string s[2];

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>arr[0][i];
	cin>>s[0];
	for(int i=0;i<m;i++)
	cin>>arr[1][i];
	cin>>s[1];
	multiset<ll> M1a, M1d, M2a, M2d;
	ll s1 = 0, s2 = 0;
	for(int i=0;i<n;i++)
	{
		s1 += arr[0][i];
		if(s[0][i] == 'A')
		M1a.ins(arr[0][i]);
		else M1d.ins(arr[0][i]);	
	}	
	for(int i=0;i<m;i++)
	{
		s2 += arr[1][i];
		if(s[1][i] == 'A')
		M2a.ins(arr[1][i]);
		else M2d.ins(arr[1][i]);	
	}	
	int z = min(n,m);
	// cout<<z<<"\n";
	VL Z1, Z2;
	for(int i=0;i<=2*z;i++)
	{
		Z1.pb(s1 - s2);
		if(!(i & 1))
		{
			if(((int)M2d.sz() > 0) && ((int)M1a.sz() > 0))
			{	
				s2 -= *M2d.rbegin();
				M1d.ins(*M1a.begin());
				M1a.erase(M1a.find(*M1a.begin()));
				M2d.erase(M2d.find(*M2d.rbegin()));
				// cout<<"AD\n";
			}
			else break;	
		}
		else
		{
			if(((int)M1d.sz() > 0) && ((int)M2a.sz() > 0))
			{
				s1 -= *M1d.rbegin();
				M2d.ins(*M2a.begin());
				M2a.erase(M2a.find(*M2a.begin()));
				M1d.erase(M1d.find(*M1d.rbegin()));
				// cout<<"DA\n";
			}
			else break;	
		}	
	}
	for(auto &&u : Z1)
	{
		// cout<<u<<"\n";
		Z2.pb(u);	
	}	
	for(int i=(int)Z2.sz()-2;i>=0;i--)
	{
		if(i & 1)
		Z2[i] = min(Z2[i], Z2[i+1]);
		else Z2[i] = max(Z2[i], Z2[i+1]);	
	}	
	cout<<Z2[0]<<"\n";
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