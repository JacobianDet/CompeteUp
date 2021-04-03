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
ll arr[MV], seg[4*MV];
string amma;

class segtree
{
	public: void build(int i, int s, int d);
			ll merger(ll left, ll right);
			void update(int i, int s, int d, int x, int val);
			ll query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		ll mask = 0;
		mask |= (1LL<<(amma[s-1] - 'a'));
		seg[i] = mask;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

ll segtree::merger(ll left, ll right)
{
	ll res = left | right;
	return res;
}

void segtree::update(int i, int s, int d, int x, int val)
{
	if(s == d)
	{
		ll mask = 0;
		mask |= (1LL<<val);
		seg[i] = mask;
		return;
	}
	int m = (s + d)/2;
	if(x <= m)
	update(2*i, s, m, x, val);
	else update(2*i+1, m+1, d, x, val);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;	
}

ll segtree::query(int i, int s, int d, int qs, int qd)
{
	if(qs > d || qd < s)
	return 0;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	ll p1 = query(2*i, s, m, qs, qd);
	ll p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

void solve(int T)
{
	cin>>amma;
	int n = amma.sz();
	segtree D;
	D.build(1, 1, n);
	int q;
	cin>>q;
	while(q--)
	{
		int ty;
		cin>>ty;
		if(ty == 1)
		{
			int x;
			char c;
			cin>>x>>c;
			D.update(1, 1, n, x, (c-'a'));
		}
		else
		{
			int s, d;
			cin>>s>>d;
			cout<<__builtin_popcountll(D.query(1, 1, n, s, d))<<"\n";
		}
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