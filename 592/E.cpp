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
ll arr[MV], pref[MV];

ll ef1(ll n, ll val)
{
	ll lo = 0;
	ll hi = n-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(arr[mid] >= val)
		hi = mid;
		else lo = mid + 1;	
	}
	if(arr[lo] < val)
	return -1;	
	else return lo;
}

ll ef2(ll n, ll val)
{
	ll lo = 0;
	ll hi = n-1;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(arr[mid] <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	if(arr[lo] > val)
	return -1;	
	else return lo;
}

ll bs1(ll n, ll k)
{
	ll lo = 0;
	ll hi = arr[n-1] - arr[0];
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		bool ok = 0;
		for(ll i=0;i<n;i++)
		{
			ll ps = ef1(n, arr[i] + mid);
			ll cx = 0;
			if(ps == -1)
			cx = ((i+1)*arr[i] - pref[i]);	
			else cx = ((i+1)*arr[i] - pref[i]) + ((pref[n-1] - ((ps > 0) ? pref[ps-1] : 0LL)) - (n - ps)*(arr[i] + mid));
			if(cx <= k)
			{
				ok = 1;
				break;
			}
		}	
		for(ll i=n-1;i>=0;i--)
		{
			ll ps = ef2(n, arr[i] - mid);
			ll cx = 0;
			if(ps == -1)
			cx = ((pref[n-1] - ((i > 0) ? pref[i-1] : 0LL)) - (n - i)*arr[i]);	
			else cx = ((ps+1)*(arr[i] - mid) - pref[ps]) + ((pref[n-1] - ((i > 0) ? pref[i-1] : 0LL)) - (n - i)*arr[i]);
			if(cx <= k)
			{
				ok = 1;
				break;
			}
		}
		if(ok)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

void solve(int T)
{
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	sort(arr, arr+n);
	for(ll i=0;i<n;i++)
	{
		if(!i)
		pref[i] = arr[i];
		else pref[i] = pref[i-1] + arr[i];	
	}
	ll ans = bs1(n, k);
	cout<<ans<<"\n";
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