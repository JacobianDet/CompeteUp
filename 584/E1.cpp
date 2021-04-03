#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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

int ar[MV];
ll arr[MV];
int tab[13][2001];
int memo[13][(1<<12)], vis[13][(1<<12)], cya[13][(1<<12)];
int m,n;
VI D;

bool cmpx(int A, int B)
{
	return ((ar[A] > ar[B]) ? 1 : 0);
}

int cyc(int ix, int mask)
{
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		int inx = 0;
		for(int j=0;j<n;j++)
		{
			if((1<<j) & mask)
			inx += tab[(i+j)%n][D[ix]];
		}
		ans = max(ans, inx);
	}
	return ans;
}

int xd(int ix, int mask, int T)
{
	if(ix == m)
	{	
		if(mask == (1<<n)-1)
		return 0;
		else return -100000000;
	}	
	if(vis[ix][mask] == T)
	return memo[ix][mask];
	int ans = 0;
	int fl = (1<<n) - 1 - mask;
	for(int nm=fl;nm>0;nm=(fl&(nm-1)))
	ans = max(ans, cya[ix][nm] + xd(ix+1, nm | mask, T));
	ans = max(ans, xd(ix+1, mask, T));	
	vis[ix][mask] = T;
	memo[ix][mask] = ans;
	return ans;	
}

void solve(int T)
{
	D.clear();
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		std::cin>>tab[i][j];	
	}
	for(int i=0;i<m;i++)
	{
		ar[i] = 0;
		for(int j=0;j<n;j++)
		ar[i] = max(ar[i], tab[j][i]);	
	}	
	for(int i=0;i<m;i++)
	D.pb(i);
	sort(D.begin(), D.end(), cmpx);
	m = min(m,n);
	for(int i=0;i<m;i++)
	{
		for(int mask = 0;mask<(1<<n);mask++)
		cya[i][mask] = cyc(i, mask);	
	}	
	int ans = xd(0, 0, T);
	cout<<ans<<"\n";
	return;
}

int main(void)
{
	FLASH();
	for(int i=0;i<13;i++)
	{
		for(int j=0;j<(1<<12);j++)
		{
			vis[i][j] = 41;
			memo[i][j] = 0;
		}	
	}
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}