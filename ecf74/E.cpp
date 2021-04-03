#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 200001
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

bool vis[(1<<20)];
int ar[MV], memo[(1<<20)];
ll arr[MV];
int tab[21][21];
int m;

int xd(int mask)
{
	if(__builtin_popcount(mask) == m)
	return 0;
	if(vis[mask])
	return memo[mask];
	int ans = 100000000, pos = __builtin_popcount(mask);
	for(int i=0;i<m;i++)
	{
		if(!(mask & (1<<i)))
		{
			int vf = 0;
			for(int j=0;j<m;j++)
			{
				if(i != j)
				{
					if(mask & (1<<j))
					vf += pos * tab[i][j];
					else vf -= pos * tab[i][j];
				}	 	
			}
			ans = min(ans, vf + xd(mask | (1<<i)));	
		}
	}
	vis[mask] = 1;
	memo[mask] = ans;
	return ans;	
}

void solve(int T)
{
	memset(vis, 0, sizeof(vis));
	int n;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n-1;i++)
	{
		int c1 = s[i] - 'a';
		int c2 = s[i+1] - 'a';
		if(c1 == c2)
		tab[c1][c2]++;
		else
		{
			tab[c1][c2]++;
			tab[c2][c1]++;
		}	
	}	
	int mv = xd(0);
	cout<<mv<<"\n";
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