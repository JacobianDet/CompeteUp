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
ll arr[MV], lo[MV], sto[MV];

void siever(void)
{
	iota(lo, lo+MV, 0);
	for(ll p=2;p*p<MV;p++)
	{
		if(lo[p] == p)
		{
			for(ll i=p*p;i<MV;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}	
		}
	}	
	return;
}

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
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	for(ll i=0;i<n;i++)
	{
		ll tp = arr[i];
		ll rx = 1;
		while(tp > 1)
		{
			ll ct = 0;
			ll p = lo[tp];
			while(!(tp % p))
			{
				ct++;
				tp /= p;
			}
			ct %= k;
			rx *= fexp(p, ct);
		}
		sto[rx]++;
	}
	ll res = 0;
	for(ll i=0;i<n;i++)
	{
		ll tp = arr[i];
		ll rx1 = 1;
		ll rx2 = 1;
		bool ok = 1;
		while(tp > 1)
		{
			ll ct = 0;
			ll p = lo[tp];
			while(!(tp % p))
			{
				ct++;
				tp /= p;
			}
			ct %= k;
			rx1 *= fexp(p, ct);
			ct = (k - ct)%k;
			ll pct = 0;
			ll z = 100000;
			while(z > p)
			{
				pct++;
				z /= p;
			}
			if(ct > pct)
			{
				ok = 0;
				break;
			}
			else rx2 *= fexp(p, ct);
		}
		if(ok)
		{
			res += sto[rx2];
			if(rx1 == rx2)
			res--;
		}		
	}	
	res /= 2;
	cout<<res<<"\n";
	return;
}

int main(void)
{
	//FLASH();
	siever();
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