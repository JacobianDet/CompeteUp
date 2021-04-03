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
		ll y = px.ff - (a/b)*px.ss;
		return mp(x, y);
	}	
}

void solve(int T)
{
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll g = __gcd(w, d);
	if(!p)
	cout<<"0 0 "<<n<<"\n";	
	else if(p % g)
	cout<<"-1\n";
	else
	{
		ll z = p/g;
		PLL px = ext_euclid(w, d);
		ll x = z * px.ff;
		ll y = z * px.ss;
		ll u = w/g;
		ll v = d/g;
		ll k1 = 0;
		if(x >= 0)
		{	
			k1 = x/v;
			k1 = -k1;
		}	
		else 
		{
			ll vx = -x;
			k1 = (vx + v - 1)/v;
		}	
		ll k2 = 0;
		if(y >= 0)
		k2 = y/u;
		else
		{
			ll vy = -y;
			k2 = ((vy + u - 1)/u);
			k2 = -k2;
		}	
		if(v > u)
		{
			ll k3 = 0;
			if((n - x - y) >= 0)
			k3 = ((n - x - y)/(v - u));	
			else
			{
				ll vn = (x + y - n);
				k3 = ((x + y - n + v - u - 1)/(v - u));
				k3 = -k3;
			}
			if(k1 <= min(k2, k3))
			cout<<(x + k1*v)<<" "<<(y - k1*u)<<" "<<(n - x - k1*v - y + k1*u)<<"\n";
			else cout<<"-1\n";
		}
		else if(v < u)
		{
			ll k3 = 0;
			if((n - x - y) >= 0)
			{	
				k3 = ((n - x - y)/(u - v));
				k3 = -k3;
			}	
			else
			{
				ll vn = (x + y - n);
				k3 = ((x + y - n + u - v - 1)/(u - v));
			}	
			if(max(k3, k1) <= k2)
			cout<<(x + k2*v)<<" "<<(y - k2*u)<<" "<<(n - x - k2*v - y + k2*u)<<"\n";
			else cout<<"-1\n";	
		}	
		else
		{
			if((n - x - y) >= 0)
			{
				if(k1 <= k2)
				cout<<(x + k1*v)<<" "<<(y - k1*u)<<" "<<(n - x - k1*v - y + k1*u)<<"\n";
				else cout<<"-1\n";	
			}
			else cout<<"-1\n";	
		}
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