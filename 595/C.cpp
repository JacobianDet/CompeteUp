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
ll arr[MV], bt[40];

ll fexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}
	return res;
}

void solve(int T)
{
	ll n;
	cin>>n;
	ll tp = n;
	for(ll ct=38;ct>=0;ct--)
	{
		ll fx = fexp(3, ct);
		if(tp >= fx)
		{	
			tp -= fx;
			bt[ct]++;
		}
		if(tp >= fx)
		{
			tp -= fx;
			bt[ct]++;
		}	
	}
	int x = 38;
	for(x=38;x>=0;x--)
	{
		if(bt[x] == 2)
		break;
	}	
	if(x != -1)
	{
		for(int i=x+1;i<=38;i++)
		{
			if(!bt[i])
			{
				bt[i]++;
				x = i-1;
				break;
			}	
		}	
		for( ;x>=0;x--)
		bt[x] = 0;
	}
	ll res = 0;
	for(ll i=0;i<=38;i++)
	{
		if(bt[i])
		res += fexp(3, i);
		bt[i] = 0;	
	}	
	cout<<res<<"\n";
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