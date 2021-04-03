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
typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;

int ar[MV];
ll arr[MV];
int memo[201][201][201];
int k,a,b,n;
string s;

struct xs
{
	int nix, nlix, nsp;
}par[201][201][201];

int xd(int ix, int lix, int sp)
{
	if((ix == n-1) && (sp < k))
	return 0;	
	else if(sp == k)
	{
		if(((n - ix) >= a) && ((n - ix) <= b))
		return 1;
		else return 0;	
	}
	if(memo[ix][lix][sp] != -1)
	return memo[ix][lix][sp];
	int ans = 0;
	if(((ix - lix + 1) >= a) && ((ix - lix + 1) <= b))
	{	
		if(xd(ix+1, ix+1, sp+1))
		{	
			par[ix][lix][sp] = {ix+1, ix+1, sp+1};
			ans |= xd(ix+1, ix+1, sp+1);
		}
	}
	if(xd(ix+1, lix, sp))
	{		
		par[ix][lix][sp] = {ix+1, lix, sp};
		ans |= xd(ix+1, lix, sp);	
	}	
	memo[ix][lix][sp] = ans;
	return ans;	
}

void solve(int T)
{
	memset(memo, -1, sizeof(memo));
	cin>>k>>a>>b;
	cin>>s;
	n = (int)s.size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int x=0;x<=k;x++)
			par[i][j][x] = {i, j, x};	
		}	
	}	
	int ans = xd(0, 0, 1);
	if(!ans)
	cout<<"No solution\n";
	else
	{	
		int pix = 0, plix = 0, psp = 1;
		while(psp < k)
		{
			//cout<<pix<<" "<<plix<<" "<<psp<<"\n";
			int tix = par[pix][plix][psp].nix;
			int tlix = par[pix][plix][psp].nlix;
			int tsp = par[pix][plix][psp].nsp;
			if(psp < tsp)
			cout<<s.substr(plix, (tix-plix))<<"\n";
			if(tsp == k)
			cout<<s.substr(tix, (n-tix))<<"\n";	
			pix = tix;
			plix = tlix;
			psp = tsp;
		}
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