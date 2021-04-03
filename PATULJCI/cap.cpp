#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1LL<<57)
#define MV 300001
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
VI str[MV];

struct rx
{
	int l,r,val;
}seg[4*MV];

class segtree 
{
	public: void build(int i, int s, int d);
			rx merger(rx left, rx right);
			rx query(int i, int s, int d, int qs, int qd);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		seg[i] = {s, d, ar[s]};
		return;
	}
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

rx segtree::merger(rx left, rx right)
{
	if(left.l == -1)
	return right;
	else if(right.l == -1)
	return left;
	else
	{
		rx res;
		res.l = left.l;
		res.r = right.r;
		int df1 = 0, df2 = 0;
		if(left.val != -1)
		df1 = (upper_bound(str[left.val].begin(), str[left.val].end(), res.r) - lower_bound(str[left.val].begin(), str[left.val].end(), res.l));
		if(right.val != -1)
		df2 = (upper_bound(str[right.val].begin(), str[right.val].end(), res.r) - lower_bound(str[right.val].begin(), str[right.val].end(), res.l));
		if(df1 > (res.r-res.l+1)/2)
		res.val = left.val;
		else if(df2 > (res.r-res.l+1)/2)
		res.val = right.val;
		else res.val = -1;
		return res;	
	}	
}

rx segtree::query(int i, int s, int d, int qs, int qd)
{
	if(s > qd || d < qs)
	return {-1, -1, -1};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	rx p1 = query(2*i, s, m, qs, qd);
	rx p2 = query(2*i+1, m+1, d, qs, qd);
	return merger(p1, p2);	
}

void solve(int T)
{
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		str[ar[i]].eb(i);
	}	
	int m;
	cin>>m;
	segtree Z;
	Z.build(1, 1, n);
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		rx rz = Z.query(1, 1, n, l, r);
		if(rz.val == -1)
		cout<<"no\n";
		else cout<<"yes "<<rz.val<<"\n";	
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