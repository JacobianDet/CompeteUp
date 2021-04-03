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

int ar1[MV], ar2[MV], pc[MV], BIT[MV];
ll arr[MV];

class fentree
{
	public: void update(int i, int n);
			int query(int i);
};

void fentree::update(int i, int n)
{
	for( ;i<=n;i+=(i & (-i)))
	BIT[i]++;
	return;	
}

int fentree::query(int i)
{
	int ans = 0;
	for( ;i>0;i-=(i & (-i)))
	ans += BIT[i];
	return ans;	
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar1[i];
	for(int i=1;i<=n;i++)
	cin>>ar2[i];
	for(int i=1;i<=n;i++)
	pc[ar1[i]] = i;
	int ct = 0;
	fentree D;
	for(int i=n;i>0;i--)
	{
		ct += (D.query(pc[ar2[i]]-1) ? 1 : 0);
		D.update(pc[ar2[i]], n);
	}	
	cout<<ct<<"\n";
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