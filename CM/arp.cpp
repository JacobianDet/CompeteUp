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
int memo[3005][3005];
PII smemo[3005][3005];
//PII par[3005][3005];
int n;

/*int xd(int ix, int vx)
{
	if(ix == n)
	return 0;
	if(memo[ix][vx] != -1)
	return memo[ix][vx];
	int ans = MV;
	for(int i=vx;i<=3000;i++)
	{
		int sd = ((i == ar[ix+1]) ? 0 : 1);
		if(ans > (sd + xd(ix+1, i)))
		{
			ans = sd + xd(ix+1, i);
			par[ix][vx] = {ix+1, i};
		}	
		else if(ans == (sd + xd(ix+1, i)))
		{
			ans = sd + xd(ix+1, i);
			par[ix][vx] = {ix+1, i};
		}	
	}	
	memo[ix][vx] = ans;
	return ans;
}*/

void solve(int T)
{
	// int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	for(int i=0;i<=n+1;i++)
	{
		for(int j=1;j<=3000;j++)
		{
			memo[i][j] = -1;
			smemo[i][j] = {MV, 0};
			//par[i][j] = {i, j};
		}		
	}
	for(int i=3000;i>0;i--)
	{
		memo[n][i] = ((ar[n] == i) ? 0 : 1);
		if(i == 3000)
		smemo[n][i] = {memo[n][i], i};
		else
		{
			if(memo[n][i] < smemo[n][i+1].ff)
			smemo[n][i] = {memo[n][i], i};
			else smemo[n][i] = smemo[n][i+1];	
		}
	}		
	// int res = xd(0, 1);
	for(int ix=n-1;ix>=0;ix--)
	{
		for(int vx=3000;vx>0;vx--)
		{
			int sd = ((ar[ix] == vx) ? 0 : 1);
			if(ix == 0)
			sd = 0;	
			memo[ix][vx] = sd + smemo[ix+1][vx].ff;
			//par[ix][vx] = {ix+1, smemo[ix+1][vx].ss};
			if(vx == 3000)
			smemo[ix][vx] = {memo[ix][vx], vx};
			else 
			{
				if(memo[ix][vx] < smemo[ix][vx+1].ff)
				smemo[ix][vx] = {memo[ix][vx], vx};
				else smemo[ix][vx] = smemo[ix][vx+1];	
			}	
		}
	}
	cout<<memo[0][1]<<"\n";
	int cvx = 1;
	for(int i=1;i<=n;i++)
	{
		cout<<smemo[i][cvx].ss<<" ";
		cvx = smemo[i][cvx].ss;
	}
	cout<<"\n";
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