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

int ar[MV];
ll arr[MV];

bool pred(int mid, int n, int k, int a)
{
	std::vector<int> Z;
	for(int i=1;i<=mid;i++)
	Z.pb(ar[i]);
	sort(Z.begin(), Z.end());
	int p1 = 1, tot = 0;
	for(auto u : Z)
	{
		if(u-p1 > 0)
		{
			int gp = (u-p1)/(a+1);
			tot += gp;
			if(((u-p1) - gp*(a+1)) == a)
			tot++;	
		}	
		p1 = u+1;
	}	
	if(n-p1+1 > 0)
	{
		int gp = (n-p1+1)/(a+1);
		tot += gp;
		if(((n-p1+1) - gp*(a+1)) == a)
		tot++;	
	}
	if(tot < k)
	return 1;
	else return 0;	
}

int bs1(int n, int k, int a, int m)
{
	int lo = 1;
	int hi = m;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(pred(mid, n, k, a))
		hi = mid;
		else lo = mid + 1;	
	}
	if(pred(lo, n, k, a))
	return lo;
	else return -1;	
}

void solve(int T)
{
	int n,k,a;
	std::cin>>n>>k>>a;
	int m;
	std::cin>>m;
	for(int i=1;i<=m;i++)
	std::cin>>ar[i];
	int pos = bs1(n, k, a, m);	
	std::cout<<pos<<"\n";
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