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

bool cmpx(ll A, ll B)
{
	return (A > B);
}

ll bs1(ll n, ll x, ll a, ll y, ll b, ll k)
{
	ll lo = 1;
	ll hi = n;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		ll xa = 0, xb = 0, xab = 0;
		ll ans = 0;
		for(int i=1;i<=mid;i++)
		{
			if(!(i%a) && (i%b))
			xa++;
			else if(!(i%b) && (i%a))
			xb++;
			else if(!(i%a) && !(i%b))
			xab++;	
		}	
		for(int i=1;i<=xab;i++)
		ans += (arr[i] * (x + y))/100;
		for(int i=xab+1;i<=xab+xa;i++)
		ans += (arr[i] * x)/100;
		for(int i=xab+xa+1;i<=xab+xa+xb;i++)
		ans += (arr[i] * y)/100;
		if(ans >= k)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

void solve(int T)
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	cin>>arr[i];
	sort(arr+1, arr+n+1, cmpx);
	ll x,a,y,b,k;
	cin>>x>>a>>y>>b>>k;
	if(x < y)
	{
		swap(a, b);
		swap(x, y);
	}
	ll mid = bs1(n, x, a, y, b, k);	
	ll xa = 0, xb = 0, xab = 0, ans = 0;
	for(int i=1;i<=mid;i++)
	{
		if(!(i%a) && (i%b))
		xa++;
		else if(!(i%b) && (i%a))
		xb++;
		else if(!(i%a) && !(i%b))
		xab++;	
	}	
	for(int i=1;i<=xab;i++)
	ans += (arr[i] * (x + y))/100;
	for(int i=xab+1;i<=xab+xa;i++)
	ans += (arr[i] * x)/100;
	for(int i=xab+xa+1;i<=xab+xa+xb;i++)
	ans += (arr[i] * y)/100;
	cout<<((ans < k) ? -1 : mid)<<"\n";
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