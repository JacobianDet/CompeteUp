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
string s[301];
int res[301][301];

void solve(int T)
{
	int h,w,k;
	cin>>h>>w>>k;
	for(int i=0;i<h;i++)
	cin>>s[i];	
	for(int i=0;i<h;i++)
	{
		int ct = 0;
		for(int j=0;j<w;j++)
		ct += (s[i][j] == '#');
		ar[i] = ct;
	}
	int f = -1, cx = 1;
	for(int i=0;i<h;i++)
	{
		if(ar[i])
		{
			int pf = -1;
			for(int j=0;j<w;j++)
			{
				if(ar[i] == 1)
				{
					pf = j;
					break;
				}	
				res[i][j] = cx;	
				cx += (s[i][j] == '#');
				ar[i] -= (s[i][j] == '#');
			}	
			for(int j=pf;j<w;j++)
			res[i][j] = cx;
			cx++;
			for(int j=i-1;j>f;j--)
			{
				for(int x=0;x<w;x++)
				res[j][x] = res[i][x];	
			}
			f = i;
		}
	}
	for(int i=f+1;i<h;i++)
	{
		for(int j=0;j<w;j++)
		res[i][j] = res[f][j];	
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		cout<<res[i][j]<<" \n"[j == w-1];	
	}	
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;

/*#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif*/

	while(T--)
	solve(T);

/*#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif*/

	return 0;
}