#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 300001
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

int ar[MV], minx[MV], maxx[MV], memo[MV];
ll arr[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar[i];	
	set<int, greater<int> > S;
	for(int i=1;i<=n;i++)
	{
		S.ins(ar[i]);
		if(!minx[ar[i]])
		minx[ar[i]] = i;
		if(!maxx[ar[i]])
		maxx[ar[i]] = i;
		if(minx[ar[i]] > i)
		minx[ar[i]] = i;
		if(maxx[ar[i]] < i)
		maxx[ar[i]] = i;	
	}	
	VI Z(S.begin(), S.end());
	memo[Z[0]] = 1;
	for(int i=1;i<Z.sz();i++)
	{
		if(minx[Z[i-1]] < maxx[Z[i]])
		memo[Z[i]] = 1;
		else memo[Z[i]] = memo[Z[i-1]] + 1;	
	}
	for(int i=1;i<=n;i++)
	{
		minx[ar[i]] = 0;
		maxx[ar[i]] = 0;
	}	
	n = S.sz();
	int m = 0;
	for(auto u : Z)
	m = max(m, memo[u]);
	cout<<(n - m)<<"\n";
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