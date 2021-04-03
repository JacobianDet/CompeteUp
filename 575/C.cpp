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

int ar[MV];
ll arr[MV];

struct pmov
{
	int x, y, fl, fu, fr, fd; 
}Z[MV];

pair<int, int> xr[MV];
pair<int, int> yr[MV];

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>Z[i].x>>Z[i].y>>Z[i].fl>>Z[i].fu>>Z[i].fr>>Z[i].fd;
	for(int i=0;i<n;i++)
	{
		int ll = Z[i].x, rl = Z[i].x, ul = Z[i].y, dl = Z[i].y;
		if(Z[i].fl)
		ll = -100000;
		if(Z[i].fr)
		rl = 100000;
		if(Z[i].fu)
		ul = 100000;
		if(Z[i].fd)
		dl = -100000;
		xr[i] = mp(ll, rl);
		yr[i] = mp(dl, ul);	
	}
	bool ok = 1;
	pair<int, int> xi = xr[0];
	pair<int, int> yi = yr[0];
	for(int i=1;i<n;i++)
	{
		int ill = max(xi.ff, xr[i].ff);
		int irl = min(xi.ss, xr[i].ss);
		int iul = min(yi.ss, yr[i].ss);
		int idl = max(yi.ff, yr[i].ff);
		if((ill > irl) || (idl > iul))
		{
			ok = 0;
			break;
		}	
		else 
		{
			xi = mp(ill, irl);
			yi = mp(idl, iul);
		}
	}	
	if(!ok)
	cout<<"0\n";
	else cout<<"1 "<<xi.ff<<" "<<yi.ff<<"\n";
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