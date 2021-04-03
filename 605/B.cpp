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

void solve(int T)
{
	string s;
	cin>>s;
	int lx=0,rx=0,ux=0,dx=0;
	for(auto u : s)
	{
		if(u == 'L')
		lx++;
		else if(u == 'R')
		rx++;
		else if(u == 'U')
		ux++;
		else dx++;	
	}
	int mlr = min(lx, rx);
	int mud = min(ux, dx);
	if(!mlr && !mud)
	cout<<"0\n";
	else if(!mlr)
	cout<<"2\nUD\n";	
	else if(!mud)
	cout<<"2\nLR\n";	
	else
	{
		cout<<2*(mlr + mud)<<"\n";
		for(int i=0;i<mlr;i++)
		cout<<"L";
		for(int i=0;i<mud;i++)
		cout<<"U";
		for(int i=0;i<mlr;i++)
		cout<<"R";
		for(int i=0;i<mud;i++)
		cout<<"D";
		cout<<"\n";	
	}
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