#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 100001
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
ll arr[3][MV];
VI G[MV];
int deg[MV];
VI dis;

void dfs_visit(int s, int p)
{
	dis.pb(s);
	for(auto u : G[s])
	{
		if(u != p)
		dfs_visit(u, s);	
	}
	return;
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int j=0;j<3;j++)
	{	
		for(int i=1;i<=n;i++)
		cin>>arr[j][i];
	}
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		deg[s]++;
		deg[d]++;
	}
	bool ok = 1;
	int c1 = 0, c2 = 0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i] > 2)
		{
			ok = 0;
			break;
		}	
		else if(deg[i] == 0)
		c1++;
		else c2++;	
	}
	if(c1 > 2)
	ok = 0;
	if(!ok)
	cout<<"-1\n";
	else
	{
		int st = -1;
		for(int i=1;i<=n;i++)
		{
			if(deg[i] == 1)
			{
				st = i;
				break;
			}	
		}
		dfs_visit(st, -1);
		int fx = -1;
		ll mx = 100000000000000000;
		for(int i=0;i<6;i++)
		{
			int fl = 0;
			ll sx = 0;
			for(auto u : dis)
			{
				if(!i)
				{
					sx += arr[fl][u];
					fl = (fl+1)%3;
				}
				else if(i == 1)
				{
					sx += arr[(fl+1)%3][u];
					fl = (fl+1)%3;
				}	
				else if(i == 2)
				{
					sx += arr[(fl+2)%3][u];
					fl = (fl+1)%3;
				}
				else if(i == 3)
				{
					sx += arr[fl][u];
					fl = (fl+2)%3;
				}	
				else if(i == 4)
				{
					sx += arr[(fl+1)%3][u];
					fl = (fl+2)%3;
				}	
				else
				{
					sx += arr[(fl+2)%3][u];
					fl = (fl+2)%3;
				}
			}
			if(mx > sx)
			{
				mx = sx;
				fx = i;
			}
		}	
		cout<<mx<<"\n";
		int fl = 0;
		for(auto u : dis)
		{
			if(!fx)
			{
				ar[u] = fl+1;
				fl = (fl+1)%3;
			}
			else if(fx == 1)
			{
				ar[u] = (fl+1)%3 + 1;
				fl = (fl+1)%3;
			}	
			else if(fx == 2)
			{
				ar[u] = (fl+2)%3 + 1;
				fl = (fl+1)%3;
			}
			else if(fx == 3)
			{
				ar[u] = fl+1;
				fl = (fl+2)%3;
			}	
			else if(fx == 4)
			{
				ar[u] = (fl+1)%3 + 1;
				fl = (fl+2)%3;
			}	
			else
			{
				ar[u] = (fl+2)%3 + 1;
				fl = (fl+2)%3;
			}
		}
		for(int i=1;i<=n;i++)
		cout<<ar[i]<<" ";
		cout<<"\n";	
	}	
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