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
bool isP[MV];
ll arr[MV];
VL px;

void siever(void)
{
	for(int i=2;i<MV;i++)
	isP[i] = 1;
	for(int p=2;p*p<MV;p++)
	{
		if(isP[p])
		{
			for(int i=p*p;i<MV;i+=p)
			isP[i] = 0;
		}
	}
	for(int i=2;i<MV;i++)
	{
		if(isP[i])
		px.pb(1LL*i);	
	}	
	return;	
}

ll modexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res = ((res%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return res;
}

void solve(int T)
{
	ll x,n;
	cin>>x>>n;
	VL Z;
	ll t = x;
	for(auto u : px)
	{
		if(!(t % u))
		{
			while(!(t % u))
			t /= u;
			Z.pb(u);	
		}
	}
	if(t > 1)
	Z.pb(t);
	ll ans = 1;
	for(auto u : Z)
	{
		ll v = n;
		while(v)
		{
			v /= u;
			ans = ((ans%MOD) * (modexp(u, v)%MOD))%MOD;
		}	
	}
	cout<<ans<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	siever();

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