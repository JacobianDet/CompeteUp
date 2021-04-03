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

PLL ext_euclid(ll a, ll b)
{
	if(!b)
	return mp(1LL, 0LL);
	else
	{
		PLL px = ext_euclid(b, a%b);
		ll x = px.ss;
		ll y = (px.ff - (a/b)*px.ss);
		return mp(x, y);
	}	
}

void solve(int T)
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll ac = (a >= 0) ? a : -a;
	ll bc = (b >= 0) ? b : -b;
	ll cc = (c >= 0) ? c : -c;
	if(cc % std::__gcd(ac, bc))
	cout<<"-1\n";
	else
	{
		ll gf = -c/std::__gcd(ac, bc);
		PLL px = ext_euclid(ac, bc);
		ll x = px.ff;
		ll y = px.ss;
		if(a < 0)
		x = -x;
		if(b < 0)
		y = -y;
		x *= gf;
		y *= gf;
		cout<<x<<" "<<y<<"\n";	
	}	
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