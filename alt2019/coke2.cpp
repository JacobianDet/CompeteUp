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

int ar[MV], cs[MV], lazy[4*MV], seg[4*MV];
ll arr[MV];

class segtree
{
	public: void build(int i, int s, int d);
			int merger(int left, int right);
			void update(int i, int s, int d, int qs, int qd, int vx);
			int query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		lazy[i] = MOD;
		seg[i] = MOD;
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	lazy[i] = MOD;
	return;
}

int segtree::merger(int left, int right)
{
	return min(left, right);
}

void segtree::update(int i, int s, int d, int qs, int qd, int vx)
{
	if(lazy[i] != MOD)
	{
		seg[i] = min(seg[i], lazy[i]);	
		if(s < d)
		{
			lazy[2*i] = min(lazy[2*i], lazy[i]);
			lazy[2*i+1] = min(lazy[2*i+1], lazy[i]);
		}	
		lazy[i] = MOD;
	}
	if(s > qd || d < qs)
	return;
	else if(qs <= s && d <= qd)
	{
		seg[i] = min(vx, seg[i]);
		if(s < d)
		{
			lazy[2*i] = min(vx, lazy[2*i]);
			lazy[2*i+1] = min(vx, lazy[2*i+1]);
		}	
		return;
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd, vx);
	update(2*i+1, m+1, d, qs, qd, vx);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

int segtree::query(int i, int s, int d, int qs, int qd)
{
	if(lazy[i] != MOD)
	{
		seg[i] = min(seg[i], lazy[i]);	
		if(s < d)
		{
			lazy[2*i] = min(lazy[2*i], lazy[i]);
			lazy[2*i+1] = min(lazy[2*i+1], lazy[i]);
		}
		lazy[i] = MOD;
	}
	if(s > qd || d < qs)
	return MOD;
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	int p1 = query(2*i, s, m, qs, qd);
	int p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

void solve(int T)
{
	int n,q,k,l,r;
	std::cin>>n>>q>>k>>l>>r;
	for(int i=0;i<n;i++)
	std::cin>>cs[i]>>ar[i];
	segtree Z;
	Z.build(1, 1, q);
	for(int i=0;i<n;i++)
	{
		if(k < l)
		{
			if(cs[i] <= l)
			continue;
			else
			{
				int t1 = 0, t2 = 0;
				if(cs[i] > r)
				t1 = cs[i] - r;
				else t1 = 1;
				if(t1 > q)
				continue;	
				t2 = std::min(cs[i] - l, q);	
				Z.update(1, 1, q, t1, t2, ar[i]);
			}	
		}
		else if(k > r)
		{
			if(cs[i] >= r)
			continue;
			else
			{
				int t1 = 0, t2 = 0;
				if(cs[i] < l)
				t1 = l - cs[i];
				else t1 = 1;
				if(t1 > q)
				continue;	
				t2 = std::min(r - cs[i], q);
				Z.update(1, 1, q, t1, t2, ar[i]);
			}	
		}	
		else
		{
			int t1 = 0, t2 = 0;
			if(cs[i] < l)
			t1 = l - cs[i];
			else if(cs[i] > r)
			t1 = cs[i] - r;
			else t1 = 1;
			if(t1 > q)
			continue;
			t2 = q;	
			Z.update(1, 1, q, t1, t2, ar[i]);
		}
	}
	for(int i=1;i<=q;i++)
	{	
		int x = Z.query(1, 1, q, i, i);
		if(x == MOD)
		x = -1;
		std::cout<<x<<" ";
	}		
	std::cout<<"\n";
	return;
}

int main(void)
{
	FLASH();
	int T;
	cin>>T;
	while(T--)
	solve(T);
	return 0;
}