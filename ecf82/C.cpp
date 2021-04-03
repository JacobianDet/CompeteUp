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

int ar[MV], vis[MV];
ll arr[MV];
VI G[30];
int tab[30][30];

string dfs_visit(int s)
{
	vis[s] = 1;
	string zx = "";
	zx += (char)(s - 1 + 'a');
	for(auto u : G[s])
	{
		if(!vis[u])
		zx += dfs_visit(u);
	}
	return zx;
}

void solve(int T)
{
	memset(tab, 0, sizeof(tab));
	memset(vis, 0, sizeof(vis));
	string s;
	cin>>s;
	int n = (int)s.sz();
	for(int i=0;i<n-1;i++)
	{
		if(!tab[s[i]-'a'+1][s[i+1]-'a'+1])
		{
			// cout<<(s[i]-'a'+1)<<"\n";
			G[s[i]-'a'+1].pb(s[i+1]-'a'+1);
			G[s[i+1]-'a'+1].pb(s[i]-'a'+1);
			tab[s[i]-'a'+1][s[i+1]-'a'+1] = 1;
			tab[s[i+1]-'a'+1][s[i]-'a'+1] = 1;
		}
	}
	bool ok = 1;
	int d1 = 0;
	for(int i=1;i<=26;i++)
	{
		if((int)G[i].sz() > 2)
		{
			ok = 0;
			break;
		}
		else if((int)G[i].sz() == 1)
		d1++;	
	}
	if((d1 < 2) && (n > 1))
	ok = 0;	
	if(!ok)
	cout<<"NO\n";
	else
	{
		string zx = "";
		cout<<"YES\n";
		for(int i=1;i<=26;i++)
		{
			if((int)G[i].sz() == 1)
			{
				zx += dfs_visit(i);
				break;
			}
		}	
		for(int i=1;i<=26;i++)
		{
			if(!vis[i])
			zx += dfs_visit(i);	
		}
		cout<<zx<<"\n";
	}	
	for(int i=1;i<=26;i++)
	G[i].clear();	
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