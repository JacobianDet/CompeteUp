#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 500001
#define LMV 21
#define ff first
#define ss second
#define pb push_back
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

int ar[MV];
ll arr[MV];

vector<PLL> G[MV];
int k;

bool cmpx(PLL A, PLL B)
{
	return (A.ss - A.ff) > (B.ss - B.ff);
}

PLL dfs_visit(int s, int p)
{
	vector<PLL> chd;
	for(auto u : G[s])
	{
		if(u.ff != p)
		{
			PLL fx = dfs_visit(u.ff, s);
			chd.pb(mp(fx.ff, fx.ss + u.ss));
		}
	}
	sort(chd.begin(), chd.end(), cmpx);
	int kc = 0;
	ll s1 = 0, s2 = 0;
	for(auto u : chd)
	{
		if(kc < k-1)
		{
			if(u.ss > u.ff)
			{
				s1 += u.ss;
				s2 += u.ss;
				kc++;
			}
			else
			{
				s1 += u.ff;
				s2 += u.ff;
			}
		}
		else if(kc == k-1)
		{
			if(u.ss > u.ff)
			{
				s1 += u.ss;
				s2 += u.ff;
				kc++;
			}
			else
			{
				s1 += u.ff;
				s2 += u.ff;
			}
		}	
		else
		{
			s1 += u.ff;
			s2 += u.ff;
		}
	}
	return mp(s1, s2);
}

void solve(int T)
{
	int n;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		ll s,d,w;
		cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
	}
	PLL dx = dfs_visit(1, -1);
	for(int i=1;i<=n;i++)
	G[i].clear();	
	cout<<max(dx.ff, dx.ss)<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

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