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
ll arr[MV], bt[51];

void solve(int T)
{
	memset(bt, 0, sizeof(bt));
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	for(ll i=0;i<51;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(arr[j] & (1LL<<i))
			bt[i]++;	
		}	
	}
	ll ax = 0;
	ll sx = 0;
	for(ll i=50;i>=0;i--)
	{
		if(bt[i] >= (n-bt[i]))
		{	
			ax |= (1LL<<i);
			sx += (1LL<<i) * (n - bt[i]);
		}
		else sx += (1LL<<i) * bt[i];	
	}
	if(sx > m)
	cout<<"Case #"<<T<<": -1\n";
	else
	{
		for(ll i=50;i>=0;i--)
		{
			if(bt[i] >= (n-bt[i]))
			continue;
			else
			{
				if((sx + -(1LL<<i) * bt[i] + (1LL<<i) * (n - bt[i]) >= 0) && ((sx + -(1LL<<i) * bt[i] + (1LL<<i) * (n - bt[i])) <= m))
				{
					ax |= (1LL<<i);
					sx += (-(1LL<<i) * bt[i] + (1LL<<i) * (n - bt[i]));
				}	
			}	
		}
		cout<<"Case #"<<T<<": "<<ax<<"\n";
	}	
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;

/*#ifndef ONLINE_JUDGE
	time_t time_t1, time_t2;
	time_t1 = clock();
#endif*/

	for(int _=1;_<=T;_++)
	solve(_);

/*#ifndef ONLINE_JUDGE
	time_t2 = clock();
	SETF();
	cout<<"Time taken: "<<setprecision(7)<<(time_t2 - time_t1)/(double)CLOCKS_PER_SEC<<"\n";
	UNSETF();
#endif*/

	return 0;
}