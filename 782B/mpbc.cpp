#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
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

int ar[MV];;
ll arr[MV], sp[MV];

ld bs1(int n)
{
	ld lo = 0;
	ld hi = 1000000001;
	for(int _=0;_<100;_++)
	{
		ld mid = lo + (hi - lo)/2;
		ld gmin = 0, gmax = 0;
		bool ok = 1;
		for(int i=0;i<n;i++)
		{
			if(!i)
			{	
				gmin = max((ld)1, (ld)arr[i] - mid * sp[i]);
				gmax = min((ld)1000000001, (ld)arr[i] + mid * sp[i]);
			}
			else
			{
				gmin = max(gmin, max((ld)1, (ld)arr[i] - mid * sp[i]));
				gmax = min(gmax, min((ld)1000000001, (ld)arr[i] + mid * sp[i]));
			}
			if(gmin > gmax)
			{
				ok = 0;
				break;
			}		
		}
		if(ok)
		hi = mid;
		else lo = mid;	
	}
	return lo;
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<n;i++)
	std::cin>>sp[i];
	ld res = bs1(n);
	SETF();
	std::cout<<setprecision(15)<<res<<"\n";
	UNSETF();
	return;	
}

int main(void)
{
	FLASH();
	int T;
	T = 1;
	while(T--)
	solve(T);
	return 0;
}