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
ll arr[MV];
//0 = DUMP, 1 = JUICE, 2 = PAN

void solve(int T)
{
	int a,b,c;
	cin>>a>>b>>c;
	int tc = 0;
	if(a > 0)
	{
		a--;
		tc++;
	}	
	if(b > 0)
	{
		b--;
		tc++;
	}
	if(c > 0)
	{
		c--;
		tc++;
	}
	VI X;
	X.pb(a);
	X.pb(b);
	X.pb(c);
	sort(X.rbegin(), X.rend());
	if((X[0] >= 2) && (X[1] >= 1) && (X[2] >= 1))
	{
		X[0] -= 2;
		X[1] -= 1;
		X[2] -= 1;
		tc += 2;
		if(X[1] && X[2])
		{
			X[1]--;
			X[2]--;
			tc++;
		}
		if(X[0] && X[1] && X[2])
		{
			X[0]--; X[1]--; X[2]--;
			tc++;
		}	
	}	
	else if(X[0] && X[1])
	{
		X[0]--;
		X[1]--;
		tc++;
	}
	else if(X[0] && X[2])
	{
		X[0]--;
		X[2]--;
		tc++;
	}	
	else if(X[1] && X[2])
	{
		X[1]--;
		X[2]--;
		tc++;
	}	
	cout<<tc<<"\n";
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