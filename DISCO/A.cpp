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
	int x,y;
	cin>>x>>y;
	int tv = 0;
	if((x == 1) && (y == 1))
	tv += (2*300000) + 400000;
	else if(x == 1)
	{
		tv += 300000;
		if(y == 2)
		tv += 200000;
		else if(y == 3)
		tv += 100000;
	}
	else if(x == 2)
	{
		tv += 200000;
		if(y == 1)
		tv += 300000;	
		else if(y == 2)
		tv += 200000;
		else if(y == 3)
		tv += 100000;	
	}	
	else if(x == 3)
	{
		tv += 100000;
		if(y == 1)
		tv += 300000;	
		else if(y == 2)
		tv += 200000;
		else if(y == 3)
		tv += 100000;	
	}
	else
	{
		if(y == 1)
		tv += 300000;	
		else if(y == 2)
		tv += 200000;
		else if(y == 3)
		tv += 100000;
	}	
	cout<<tv<<"\n";
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