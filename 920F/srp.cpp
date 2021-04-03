#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MV 1000001
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

bool isP[MV];
int ar[MV], dv[MV];
ll arr[MV];
VI px;

void siever(void)
{
	for(int i=1;i<MV;i++)
	{
		isP[i] = 1;
		dv[i] = 1;
	}
	isP[0] = 0;
	for(int p=2;p*p<MV;p++)
	{
		if(isP[p])
		{
			for(int i=p*p;i<MV;i+=p)
			isP[i] = 0;	
		}
	}
	for(int i=2;i<MV;i++)
	{
		ar[i] = i;
		if(isP[i])
		px.pb(i);	
	}	
	for(auto u : px)
	{
		for(int i=u;i<MV;i+=u)
		{
			int ct = 0;
			while(!(ar[i] % u))
			{
				ar[i] /= u;
				ct++;
			}
			dv[i] *= (ct + 1);
		}	
	}
	return;
}

struct vix
{
	ll val, oc;
	bool ilp, il2;
}seg[4*MV];

class segtree
{
	public: void build(int i, int s, int d);
			void update(int i, int s, int d, int qs, int qd);
			vix query(int i, int s, int d, int qs, int qd);
			vix merger(vix left, vix right);
};

void segtree::build(int i, int s, int d)
{
	if(s == d)
	{
		bool xf = 0;
		if(ar[s] <= 2)
		xf = 1;
		if(ar[s] == 1)
		seg[i] = {ar[s], 1, 1, xf};	
		else if(isP[ar[s]])
		seg[i] = {ar[s], 0, 1, xf};
		else seg[i] = {ar[s], 0, 0, xf};
		return;
	}	
	int m = (s + d)/2;
	build(2*i, s, m);
	build(2*i+1, m+1, d);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

vix segtree::merger(vix left, vix right)
{
	return {(left.val + right.val), (left.oc + right.oc), (bool)(left.ilp & right.ilp), (bool)(left.il2 & right.il2)};
}

void segtree::update(int i, int s, int d, int qs, int qd)
{
	if(seg[i].il2)
	{	
		seg[i].val = 2LL*(d*1LL - s + 1) - seg[i].oc;
		if(s < d)
		{
			seg[2*i].il2 = 1;
			seg[2*i+1].il2 = 1;
			seg[2*i].ilp = 1;
			seg[2*i+1].ilp = 1;
		}
	}	
	if(qs > d || qd < s)
	return;
	else if(qs <= s && d <= qd)
	{
		if(s == d)
		{
			seg[i].val = dv[seg[i].val];
			if(isP[seg[i].val])
			seg[i].ilp = 1;
			else if(seg[i].val <= 2)
			seg[i].il2 = 1;	
			return;	
		}
		else if(seg[i].ilp)
		{
			seg[i].val = 2LL*(d*1LL - s + 1) - seg[i].oc;
			seg[i].il2 = 1;
			if(s < d)
			{
				seg[2*i].il2 = 1;
				seg[2*i+1].il2 = 1;
				seg[2*i].ilp = 1;
				seg[2*i+1].ilp = 1;
 			}
 			return;
 		}	
	}	
	int m = (s + d)/2;
	update(2*i, s, m, qs, qd);
	update(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return;
}

vix segtree::query(int i, int s, int d, int qs, int qd)
{
	if(seg[i].il2)
	{	
		seg[i].val = 2LL*(d*1LL - s + 1) - seg[i].oc;
		if(s < d)
		{
			seg[2*i].il2 = 1;
			seg[2*i+1].il2 = 1;
			seg[2*i].ilp = 1;
			seg[2*i+1].ilp = 1;
		}
	}	
	if(qs > d || qd < s)
	return {0, 0, 1, 1};
	else if(qs <= s && d <= qd)
	return seg[i];
	int m = (s + d)/2;
	vix p1 = query(2*i, s, m, qs, qd);
	vix p2 = query(2*i+1, m+1, d, qs, qd);
	seg[i] = merger(seg[2*i], seg[2*i+1]);
	return merger(p1, p2);	
}

void solve(int T)
{
	siever();
	/*for(int i=1;i<=10;i++)
	std::cout<<dv[i]<<" ";
	std::cout<<"\n";*/	
	int n, q;
	std::cin>>n>>q;
	for(int i=1;i<=n;i++)
	std::cin>>ar[i];
	segtree Z;
	Z.build(1, 1, n);
	while(q--)
	{
		int t,l,r;
		std::cin>>t>>l>>r;
		if(--t)
		std::cout<<Z.query(1, 1, n, l, r).val<<"\n";
		else Z.update(1, 1, n, l, r);	
	}	
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