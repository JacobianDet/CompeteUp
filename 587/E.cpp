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

ll sumup1(ll val)
{
	ll x = val;
	ll dc = 0;
	while(x)
	{
		dc++;
		x /= 10;
	}
	ll tx = 1, add = 0, sx = 0;
	for(ll i=1;i<dc;i++)
	{
		ll cnt = 9*tx;
		sx += add*cnt + ((cnt * (cnt+1))/2)*i;
		add += cnt*i;
		tx *= 10;
	}
	ll cnt = (val - tx + 1);
	sx += add*cnt + ((cnt * (cnt+1))/2)*dc;
	return sx;
}

ll sumup2(ll val)
{
	ll x = val;
	ll dc = 0;
	while(x)
	{
		dc++;
		x /= 10;
	}
	ll tx = 1, sx = 0;
	for(ll i=1;i<dc;i++)
	{
		ll cnt = 9*tx;
		sx += cnt*i;
		tx *= 10;
	}	
	ll cnt = (val - tx + 1);
	sx += cnt*dc;
	return sx;
}	

ll bs1a(ll k)
{
	ll lo = 1;
	ll hi = 1000000001;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(sumup1(mid) >= k)
		hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

ll bs1b(ll k, ll vf)
{
	ll lo = 1;
	ll hi = vf;
	while(lo < hi)
	{
		ll mid = lo + (hi - lo)/2;
		if(sumup2(mid) < k)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

void solve(int T)
{
	ll k;
	std::cin>>k;
	ll vf = bs1a(k);
	k -= sumup1(vf-1);
	ll vfx = bs1b(k, vf);
	k -= sumup2(vfx-1);
	VI Z;
	while(vfx)
	{
		Z.pb(vfx%10);
		vfx /= 10;
	}
	std::reverse(Z.begin(), Z.end());
	std::cout<<Z[k-1]<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}