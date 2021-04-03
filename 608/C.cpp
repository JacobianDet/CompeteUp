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
	int n,sx,sy;
	cin>>n>>sx>>sy;
	int xp = 0, xn = 0, xz = 0, yp = 0, yn = 0, yz = 0;
	for(int i=0;i<n;i++)
	{
		int tx,ty;
		cin>>tx>>ty;
		if(sx - tx > 0)
		xp++;
		else if(sx - tx < 0)
		xn++;
		else xz++;
		if(sy - ty > 0)
		yp++;
		else if(sy - ty < 0)
		yn++;
		else yz++;	
	}
	int mx = max(xp, max(xn, max(yp, yn)));
	if(mx == xp)
	cout<<xp<<"\n"<<sx-1<<" "<<sy<<"\n";
	else if(mx == xn)
	cout<<xn<<"\n"<<sx+1<<" "<<sy<<"\n";
	else if(mx == yp)
	cout<<yp<<"\n"<<sx<<" "<<sy-1<<"\n";
	else cout<<yn<<"\n"<<sx<<" "<<sy+1<<"\n";
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