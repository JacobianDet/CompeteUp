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
ll arr[MV], BIT[MV];

class fentree
{
	public: void build(int n);
			void update(int i, int n, ll v);
			ll query(int i); 
};

void fentree::build(int n)
{
	for(int i=1;i<=n;i++)
	BIT[i] = 0;
	return;	
}

void fentree::update(int i, int n, ll v)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i] += v;
	return;	
}

ll fentree::query(int i)
{
	ll sx = 0;
	for( ;i>0;i-=(i & (-i)))
	sx += BIT[i];
	return sx;	
}

int bs2(fentree &Z, int n, ll val)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(Z.query(mid-1) <= val)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

void solve(int T)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	fentree Z;
	Z.build(n);
	for(int i=1;i<=n;i++)
	Z.update(i, n, 1LL*i);
	for(int i=n;i>0;i--)
	{
		int pos = bs2(Z, n, arr[i]);
		ar[i] = pos;
		Z.update(pos, n, -1LL*pos);
	}	
	for(int i=1;i<=n;i++)
	std::cout<<ar[i]<<" ";
	std::cout<<"\n";
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