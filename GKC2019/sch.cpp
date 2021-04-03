#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 200001
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
ll arr[MV], tc[MV], lf[MV];
VL px;
bool isP[MV];

void siever(void)
{
	memset(isP, 1, sizeof(isP));
	isP[0] = 0;
	isP[1] = 0;
	for(ll p=2;p*p<MV;p++)
	{
		if(isP[p])
		{
			for(ll i=p*p;i<MV;i+=p)
			isP[i] = 0;	
		}	
	}	
	for(ll i=2;i<MV;i++)
	{
		if(isP[i])
		px.pb(i);	
	}	
	return;
}

void solve(int T)
{
	ll l,r;
	std::cin>>l>>r;
	for(ll i=l;i<=r;i++)
	{
		lf[i-l] = i;
		arr[i-l] = 1;
		tc[i-l] = 0;
	}	
	for(auto u : px)
	{
		ll x = 0;
		if(!(l % u))
		x = l;
		else x = ((l/u) + 1)*u;
		for( ;x<=r;x+=u)
		{
			ll ct = 0;
			while(!(lf[x-l] % u))
			{
				ct++;
				lf[x-l] /= u;
			}
			if(u == 2)
			tc[x-l] += ct;
			else arr[x-l] *= (ct + 1);	
		}	
	}
	ll ans = 0;
	for(ll i=l;i<=r;i++)
	{
		if(lf[i-l] > 1)
		{
			arr[i-l] *= 2;
			lf[i-l] = 1;
		}	
		ll z = 0;
		if(tc[i-l] > 1)
		z = tc[i-l] - 1;
		else z = 1 - tc[i-l];
		if((z * arr[i-l]) <= 2)
		ans++;	
	}
	std::cout<<"Case #"<<T<<": "<<ans<<"\n";
	return;	
}

int main(void)
{
	FLASH();
	siever();
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	solve(t);
	return 0;
}