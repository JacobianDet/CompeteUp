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
ll arr[MV], res[MV];

struct qry
{
	int ty, ix, jx, ind;
};

PLL seg[4*MV];
PPLL lazy[4*MV];
MLL lu;

class segtree
{
	public: void build(int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void update(int i, int s, int d, int qs, int qd, ll vx);
			PLL query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {0, 0};
		lazy[i] = {{0, 0}, 0};
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	lazy[i] = {{0, 0}, 0};
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::merger(PLL left, PLL right)
{
	PLL res;
	res.ff = max(left.ff, right.ff);
	res.ss = max(left.ss, right.ss);
	return res;
}

void segtree::update(int i, int s, int d, int qs, int qd, ll vx)
{
	if(lazy[i].ss)
	{
		if(s < d)
		{
			seg[2*i] = {seg[2*i].ff + lazy[i].ff.ff, max(seg[2*i].ss, seg[2*i].ff + lazy[i].ff.ss)};
			seg[2*i+1] = {seg[2*i+1].ff + lazy[i].ff.ff, max(seg[2*i+1].ss, seg[2*i+1].ff + lazy[i].ff.ss)};
			lazy[2*i] = {{lazy[2*i].ff.ff + lazy[i].ff.ff, max(lazy[2*i].ff.ss, lazy[2*i].ff.ff + lazy[i].ff.ss)}, 1};
			lazy[2*i+1] = {{lazy[2*i+1].ff.ff + lazy[i].ff.ff, max(lazy[2*i+1].ff.ss, lazy[2*i+1].ff.ff + lazy[i].ff.ss)}, 1};
		}
		lazy[i] = {{0, 0}, 0};
	}
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		seg[i] = {seg[i].ff + vx, max(seg[i].ss, seg[i].ff + vx)};
		lazy[i] = {{lazy[i].ff.ff + vx, max(lazy[i].ff.ss, lazy[i].ff.ff + vx)}, 1};
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, vx);
	update(2*i+1, m+1, d, qs, qd, vx);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i].ss)
	{
		if(s < d)
		{
			seg[2*i] = {seg[2*i].ff + lazy[i].ff.ff, max(seg[2*i].ss, seg[2*i].ff + lazy[i].ff.ss)};
			seg[2*i+1] = {seg[2*i+1].ff + lazy[i].ff.ff, max(seg[2*i+1].ss, seg[2*i+1].ff + lazy[i].ff.ss)};
			lazy[2*i] = {{lazy[2*i].ff.ff + lazy[i].ff.ff, max(lazy[2*i].ff.ss, lazy[2*i].ff.ff + lazy[i].ff.ss)}, 1};
			lazy[2*i+1] = {{lazy[2*i+1].ff.ff + lazy[i].ff.ff, max(lazy[2*i+1].ff.ss, lazy[2*i+1].ff.ff + lazy[i].ff.ss)}, 1};
		}
		lazy[i] = {{0, 0}, 0};
	}
	if(s > qd || d < qs)
	return {0, 0};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	PLL p1 = query(2*i, s, m, qs, qd);
	PLL p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);
}

void solve(int T)
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	vector<qry> Q;
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int ix,jx;
		cin>>ix>>jx;
		Q.pb({1, ix, jx, i});
	}		
	for(int i=1;i<=n;i++)
	Q.pb({0, -1, i, -1});
	sort(Q.begin(), Q.end(), [](qry A, qry B){ return ((A.jx < B.jx) || ((A.jx == B.jx) && (A.ty < B.ty))); });
	segtree D;
	D.build(1, 1, n);
	for(auto u : Q)
	{
		if(u.ty)
		res[u.ind] = D.query(1, 1, n, u.ix, u.jx).ss;	
		else
		{
			int px = lu[arr[u.jx]];
			lu[arr[u.jx]] = u.jx;
			D.update(1, 1, n, px+1, u.jx, arr[u.jx]);
		}	
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