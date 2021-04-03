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

int ar[MV];
ll arr[MV];

struct qry
{
	int ty,ix,jx,ind,kx;
};

int seg[4*MV], res[MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			void update(int i, int s, int d, int ix);
			int query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = 0;
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::merger(int left, int right)
{
	return (left + right);
}

void segtree::update(int i, int s, int d, int ix)
{
	if(s == d)
	{
		seg[i]++;
		return;
	}	
	int m = (s + d)/2;
	if(ix <= m)
	update(2*i, s, m, ix);
	else update(2*i+1, m+1, d, ix);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return 0;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>ar[i];
	int q;
	cin>>q;
	vector<qry> Q;
	for(int i=0;i<q;i++)
	{
		int ix,jx,k;
		cin>>ix>>jx>>k;
		Q.pb({1, ix, jx, i, k});
	}	
	for(int i=1;i<=n;i++)
	Q.pb({0, i, i, -1, ar[i]});
	sort(Q.begin(), Q.end(), [](qry A, qry B){ return (A.kx > B.kx) || ((A.kx == B.kx) && (A.ty > B.ty)); });
	segtree D;
	D.build(1, 1, n);
	for(auto u : Q)
	{
		if(u.ty)
		res[u.ind] = D.query(1, 1, n, u.ix, u.jx);
		else D.update(1, 1, n, u.ix);	
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