#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 1000001
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

int ar[(1<<20)], res[MV];
ll arr[MV];

void solve(int T)
{
	memset(ar, 0, sizeof(ar));
	memset(res, 0, sizeof(res));
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=1;i<=k;i++)
	{
		string z;
		cin>>z;
		int bt = 0;
		for(int j=0,m=(int)z.sz();j<m;j++)
		bt |= (1<<(z[j]-'a'));
		ar[bt] = i;	
	}	
	for(int i=0;i<20;i++)
	{
		for(int mask=(1<<20)-1;mask>=0;mask--)
		{
			if((ar[mask]) && (mask & (1<<i)))
			ar[mask ^ (1<<i)] = ar[mask];	
		}	
	}	
	int pz = 0;
	while(pz < n)
	{
		int tz = pz;
		int bt = 0;
		while((tz < n) && (ar[bt | (1<<(s[tz]-'a'))]))
		{	
			bt |= (1<<(s[tz]-'a'));
			tz++;
		}	
		res[pz] += ar[bt];
		res[tz] -= ar[bt];
		pz = tz;
	}
	for(int i=1;i<n;i++)
	res[i] += res[i-1];
	for(int i=0;i<n;i++)
	cout<<res[i]<<" ";
	cout<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;



	while(T--)
	solve(T);



	return 0;
}