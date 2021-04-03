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

void solve(int T)
{
	ll n,p,w,d;
	cin>>n>>p>>w>>d;
	ll g = __gcd(w, d);
	if(p % g)
	cout<<"-1\n";
	else
	{
		bool ok = 0;
		for(ll i=0;i<w;i++)
		{
			if((p - d*i) % w)
			continue;
			else
			{
				ll x = (p - d*i)/w;
				ll y = i;
				if((x >= 0) && (x + y <= n))
				{
					ok = 1;
					cout<<x<<" "<<y<<" "<<(n - x - y)<<"\n";
					break;
				}	
			}	
		}	
		if(!ok)
		cout<<"-1\n";	
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