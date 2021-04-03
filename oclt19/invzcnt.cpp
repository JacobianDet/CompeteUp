#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 1000005
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

int ar[MV], br[MV], rr[MV];
ll arr[MV], BIT[MV];
MII cord;

class fentree
{
	public: void update(int i, int n);
			ll query(int i); 
};

void fentree::update(int i, int n)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i]++;
	return;
}

ll fentree::query(int i)
{
	ll ax = 0;
	for( ;i>0;i-=(i & (-i)))
	ax += BIT[i];
	return ax;
}

void solve(int T)
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	while(q--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=n;i++)
		{	
			br[i] = ar[i] ^ k;
			rr[i] = br[i];
		}	
		sort(rr+1, rr+n+1);
		int x = 0;
		for(int i=1;i<=n;i++)
		{
			if(!cord[rr[i]])
			{
				x++;
				cord[rr[i]] = x;
			}
		}	
		ll ans = 0;
		fentree D;
		for(int i=n;i>0;i--)
		{
			ans += D.query(cord[br[i]]-1);
			D.update(cord[br[i]], x);
		}
		for(int i=1;i<=x;i++)
		BIT[i] = 0;	
		cout<<ans<<"\n";
		cord.clear();
	}	
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