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
PLL seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			PLL merger(PLL left, PLL right);
			void upd1(int i, int s, int d, int qs, int qd, ll x);
			void upd2(int i, int s, int d, int idx, ll x);
			PLL query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {arr[s], arr[s]};
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

PLL segtree::merger(PLL left, PLL right)
{
	PLL res;
	res.ff = left.ff + right.ff;
	res.ss = max(left.ss, right.ss);
	return res;
}

void segtree::upd1(int i, int s, int d, int qs, int qd, ll x)
{
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		if(seg[i].ss < x)
		return;	
		else if(s == d)
		{
			seg[i].ff %= x;
			seg[i].ss %= x;
			return;
		}	
	}	
	int m = (s + d)/2;
	upd1(2*i, s, m, qs, qd, x);
	upd1(2*i+1, m+1, d, qs, qd, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

void segtree::upd2(int i, int s, int d, int idx, ll x)
{
	if(s == d)
	{
		seg[i] = {x, x};
		return;
	}
	int m = (s + d)/2;
	if(idx <= m)
	upd2(2*i, s, m, idx, x);
	else upd2(2*i+1, m+1, d, idx, x);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

PLL segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return {0LL, 0LL};
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
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	segtree Z;
	Z.build(1, 1, n);
	while(m--)
	{
		int ty;
		cin>>ty;
		if(ty == 1)
		{
			int l,r;
			cin>>l>>r;
			cout<<Z.query(1, 1, n, l, r).ff<<"\n";
		}
		else if(ty == 2)
		{
			int l,r;
			ll x;
			cin>>l>>r>>x;
			Z.upd1(1, 1, n, l, r, x);
		}		
		else
		{
			int id;
			ll x;
			cin>>id>>x;
			Z.upd2(1, 1, n, id, x);
		}
		/*for(int i=1;i<=n;i++)
		cout<<Z.query(1, 1, n, i, i)<<" ";
		cout<<"\n";*/	
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