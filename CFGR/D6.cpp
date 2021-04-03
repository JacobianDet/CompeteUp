#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 300001
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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];

void solve(int T)
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		ll w;
		cin>>s>>d>>w;
		arr[d] -= w;
		arr[s] += w;
	}
	set<PLL> lend, deb;
	for(int i=1;i<=n;i++)
	{
		if(arr[i] > 0)
		deb.insert({arr[i], i});
		else if(arr[i] < 0)
		lend.insert({-arr[i], i});	
	}	
	vector<PPLL> res;
	while(!lend.empty())
	{
		PLL px1 = (*lend.begin());
		PLL px2 = (*deb.begin());
		lend.erase(px1);
		deb.erase(px2);
		if(px1.ff < px2.ff)
		{
			res.pb({{px2.ss, px1.ss}, px1.ff});
			px2.ff -= px1.ff;
			deb.insert(px2);
		}
		else
		{
			res.pb({{px2.ss, px1.ss}, px2.ff});
			px1.ff -= px2.ff;
			if(px1.ff > 0)
			lend.insert(px1);
		}
	}
	cout<<(int)res.sz()<<"\n";
	for(auto u : res)
	cout<<u.ff.ff<<" "<<u.ff.ss<<" "<<u.ss<<"\n";
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