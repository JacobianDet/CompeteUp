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
ll mat[2][2], res[2][2];

ll modexp(ll a, ll n)
{
	ll rv = 1;
	while(n)
	{
		if(n & 1)
		rv = ((rv%MOD) * (a%MOD))%MOD;
		a = ((a%MOD) * (a%MOD))%MOD;
		n >>= 1;	
	}
	return rv;
}

void MATMUL(ll n)
{
	res[0][0] = 1;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 1;
	while(n)
	{
		if(n & 1)
		{
			ll r00 = ((((res[0][0]%MOD) * (mat[0][0]%MOD))%MOD) + (((res[0][1]%MOD) * (mat[1][0]%MOD))%MOD))%MOD;
			ll r01 = ((((res[0][0]%MOD) * (mat[0][1]%MOD))%MOD) + (((res[0][1]%MOD) * (mat[1][1]%MOD))%MOD))%MOD;
			ll r10 = ((((res[1][0]%MOD) * (mat[0][0]%MOD))%MOD) + (((res[1][1]%MOD) * (mat[1][0]%MOD))%MOD))%MOD;
			ll r11 = ((((res[1][0]%MOD) * (mat[0][1]%MOD))%MOD) + (((res[1][1]%MOD) * (mat[1][1]%MOD))%MOD))%MOD;
			res[0][0] = r00;
			res[0][1] = r01;
			res[1][0] = r10;
			res[1][1] = r11;
		}	
		ll m00 = ((((mat[0][0]%MOD) * (mat[0][0]%MOD))%MOD) + (((mat[0][1]%MOD) * (mat[1][0]%MOD))%MOD))%MOD;
		ll m01 = ((((mat[0][0]%MOD) * (mat[0][1]%MOD))%MOD) + (((mat[0][1]%MOD) * (mat[1][1]%MOD))%MOD))%MOD;
		ll m10 = ((((mat[1][0]%MOD) * (mat[0][0]%MOD))%MOD) + (((mat[1][1]%MOD) * (mat[1][0]%MOD))%MOD))%MOD;
		ll m11 = ((((mat[1][0]%MOD) * (mat[0][1]%MOD))%MOD) + (((mat[1][1]%MOD) * (mat[1][1]%MOD))%MOD))%MOD;
		mat[0][0] = m00;
		mat[0][1] = m01;
		mat[1][0] = m10;
		mat[1][1] = m11;
		n >>= 1;
	}
	return;
}

void solve(int T)
{
	ll n,m;
	cin>>n>>m;
	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[1][1] = 0;
	ll f1 = 0, f2 = 0;
	if(n > 2)
	{	
		MATMUL(n-2);
		f1 = ((((4%MOD) * (res[0][0]%MOD))%MOD) + (((2%MOD) * (res[0][1]%MOD))%MOD))%MOD;
	}
	else if(n == 2)
	f1 = 4;
	else f1 = 2;
	mat[0][0] = 1;
	mat[0][1] = 1;
	mat[1][0] = 1;
	mat[1][1] = 0;
	if(m > 2)
	{	
		MATMUL(m-2);
		f2 = ((((4%MOD) * (res[0][0]%MOD))%MOD) + (((2%MOD) * (res[0][1]%MOD))%MOD))%MOD;
	}
	else if(m == 2)
	f2 = 4;
	else f2 = 2;
	ll ax = ((((f1%MOD) + (f2%MOD))%MOD) - (2%MOD) + MOD)%MOD;
	cout<<ax<<"\n";
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