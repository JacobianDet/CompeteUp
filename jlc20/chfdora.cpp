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
vector<VI> tdx;
vector<VI> d1, d2;

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	tdx.resize(n+5, VI(m+5));
	d1.resize(n+5, VI(m+5));
	d2.resize(n+5, VI(m+5));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>tdx[i][j];	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0,l=0,r=-1;j<m;j++)
		{
			int k = (j > r) ? 1 : min(d1[i][l+r-j], r-j+1);
			while((j-k >= 0) && (j+k < m) && (tdx[i][j-k] == tdx[i][j+k]))
			k++;
			d1[i][j] = k--;
			if(j + k > r)
			{
				l = j-k;
				r = j+k;
			}	
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0,l=0,r=-1;j<n;j++)
		{
			int k = (j > r) ? 1 : min(d2[l+r-j][i], r-j+1);
			while((j-k >= 0) && (j+k < n) && (tdx[j-k][i] == tdx[j+k][i]))
			k++;
			d2[j][i] = k--;
			if(j + k > r)
			{
				l = j-k;
				r = j+k;
			}	
		}
	}
	ll res = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		res += 1LL*min(d1[i][j], d2[i][j]);
	}
	d1.clear();
	d2.clear();
	tdx.clear();
	cout<<res<<"\n";
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