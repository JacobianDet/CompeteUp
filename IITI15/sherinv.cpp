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

int ar[MV], br[MV];
ll arr[MV], BIT[MV], res[MV];
MII cord;

struct sq
{
	int l,r,id;
}Q[MV];

class fentree
{
	public: void update(int i, int n, ll vl);
			ll query(int i);
};

void fentree::update(int i, int n, ll vl)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i] += vl;
	return;	
}

ll fentree::query(int i)
{
	ll ans = 0;
	for( ;i>0;i-=(i & (-i)))
	ans += BIT[i];
	return ans;	
}

void solve(int T)
{
	int n;
	cin>>n;
	int Z = (int)sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		br[i] = ar[i];
	}
	int x = 0;
	ll ct = 0;
	sort(br+1, br+n+1);
	//for(int i=1;i<=n;i++)
	//cout<<br[i]<<" ";
	//cout<<"\n";	
	for(int i=1;i<=n;i++)
	{
		if(!cord[br[i]])
		{
			x++;
			cord[br[i]] = x;
		}	
	}	
	for(int i=1;i<=n;i++)
	ar[i] = cord[ar[i]];
	//for(int i=1;i<=n;i++)
	//cout<<ar[i]<<" ";
	//cout<<"\n";	
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
	}
	sort(Q, Q+q, [Z](sq A, sq B) { return (((A.l/Z) < (B.l/Z)) || (((A.l/Z) == (B.l/Z)) && (A.r < B.r))); });
	//for(int i=0;i<q;i++)
	//cout<<Q[i].l<<" "<<Q[i].r<<" "<<Q[i].id<<"\n";	
	fentree D;
	int mo_l = 1, mo_r = 0;
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l;
		int r = Q[i].r;
		while(mo_r < r)
		{
			mo_r++;
			ct += (D.query(x) - D.query(ar[mo_r]));
			D.update(ar[mo_r], x, 1LL);
		}
		while(mo_r > r)
		{
			ct -= (D.query(x) - D.query(ar[mo_r]));
			D.update(ar[mo_r], x, -1LL);
			mo_r--;
		}
		while(mo_l < l)
		{
			ct -= D.query(ar[mo_l]-1);
			D.update(ar[mo_l], x, -1LL);
			mo_l++;
		}
		while(mo_l > l)
		{
			mo_l--;
			ct += D.query(ar[mo_l]-1);
			D.update(ar[mo_l], x, 1LL);
		}
		res[Q[i].id] = ct;
	}
	for(int i=0;i<q;i++)
	cout<<res[i]<<"\n";
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