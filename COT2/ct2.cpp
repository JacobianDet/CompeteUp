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

int ar[MV], br[MV], lvl[MV], fx[MV], cnt[MV], xz[MV], dsc[MV], fin[MV], res[MV];
ll arr[MV];
int P[MV][LMV];
VI G[MV];
MII cord;
int tx;

void dfs_visit(int s, int p)
{
	P[s][0] = p;
	lvl[s] = 0;
	if(p != -1)
	lvl[s] = 1 + lvl[p];	
	dsc[s] = ++tx;
	fx[tx] = s;
	for(auto u : G[s])
	{
		if(u != p)
		dfs_visit(u, s);	
	}
	fin[s] = ++tx;
	fx[tx] = s;
	return;
}

struct sq
{
	int l,r,id,lca;
}Q[MV];

class sparse
{
	public: void ST_build(int n);
			int LCA_find(int p, int q);
};

void sparse::ST_build(int n)
{
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];	
		}	
	}
	return;
}

int sparse::LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tp = p;
		p = q;
		q = tp;
	}
	int l2 = 0;
	for(l2=1;(1<<l2)<=lvl[p];l2++);
	l2--;
	for(int i=l2;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])	
		p = P[p][i];	
	}
	if(p == q)
	return p;
	for(int i=l2;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	return P[p][0];
}

void solve(int T)
{
	memset(P, -1, sizeof(P));
	int n,m;
	cin>>n>>m;
	int Z = (int)sqrt(2*n);
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		br[i] = ar[i];
	}	
	int x = 0;
	int dc = 0;
	sort(br+1, br+n+1);
	for(int i=1;i<=n;i++)
	{
		if(!cord[br[i]])
		{
			x++;
			cord[br[i]] = x;
		}	
	}	
	tx = 0;
	for(int i=1;i<=n;i++)
	ar[i] = cord[ar[i]];
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	dfs_visit(1, -1);
	sparse X;
	X.ST_build(n);
	for(int i=0;i<m;i++)
	{
		cin>>Q[i].l>>Q[i].r;
		Q[i].id = i;
		Q[i].lca = X.LCA_find(Q[i].l, Q[i].r);
		if(Q[i].lca == Q[i].l)
		{
			Q[i].l = dsc[Q[i].l];
			Q[i].r = dsc[Q[i].r];
			Q[i].lca = -1;
  		}	
  		else if(Q[i].lca == Q[i].r)
  		{
  			int x = dsc[Q[i].r];
  			int y = dsc[Q[i].l];
  			Q[i].l = x;
  			Q[i].r = y;
  			Q[i].lca = -1;
  		}	
  		else
  		{
  			int e1 = fin[Q[i].l];
  			int e2 = fin[Q[i].r];
  			if(e1 > e2)
  			{
  				swap(Q[i].l, Q[i].r);
  				swap(e1, e2);
  			}
  			Q[i].l = e1;
  			Q[i].r = dsc[Q[i].r];
  			Q[i].lca = dsc[Q[i].lca];
  		}
	}
	sort(Q, Q+m, [Z](sq A, sq B){ return ((A.l/Z < B.l/Z) || ((A.l/Z == B.l/Z) && (A.r < B.r))); });
	int mo_l = 1, mo_r = 0;
	/*for(int i=0;i<m;i++)
	{
		cout<<Q[i].l<<" "<<Q[i].r<<" "<<Q[i].lca<<"\n";
	}*/	
	for(int i=0;i<m;i++)
	{
		int l = Q[i].l;
		int r = Q[i].r;
		while(mo_r < r)
		{
			mo_r++;
			xz[fx[mo_r]] ^= 1;
			if(xz[fx[mo_r]])
			{	
				cnt[ar[fx[mo_r]]]++;
				if(cnt[ar[fx[mo_r]]] == 1)
				dc++;
			}		
			else 
			{
				cnt[ar[fx[mo_r]]]--;
				if(!cnt[ar[fx[mo_r]]])
				dc--;
			}		
		}
		while(mo_r > r)
		{
			xz[fx[mo_r]] ^= 1;
			if(xz[fx[mo_r]])
			{	
				cnt[ar[fx[mo_r]]]++;
				if(cnt[ar[fx[mo_r]]] == 1)
				dc++;
			}		
			else 
			{
				cnt[ar[fx[mo_r]]]--;
				if(!cnt[ar[fx[mo_r]]])
				dc--;
			}	
			mo_r--;
		}
		while(mo_l < l)
		{
			xz[fx[mo_l]] ^= 1;
			if(xz[fx[mo_l]])
			{	
				cnt[ar[fx[mo_l]]]++;
				if(cnt[ar[fx[mo_l]]] == 1)
				dc++;
			}		
			else 
			{
				cnt[ar[fx[mo_l]]]--;
				if(!cnt[ar[fx[mo_l]]])
				dc--;
			}	
			mo_l++;
		}
		while(mo_l > l)
		{
			mo_l--;
			xz[fx[mo_l]] ^= 1;
			if(xz[fx[mo_l]])
			{	
				cnt[ar[fx[mo_l]]]++;
				if(cnt[ar[fx[mo_l]]] == 1)
				dc++;
			}		
			else 
			{
				cnt[ar[fx[mo_l]]]--;
				if(!cnt[ar[fx[mo_l]]])
				dc--;
			}	
		}
		res[Q[i].id] = dc + ((Q[i].lca != -1) ? (!cnt[ar[fx[Q[i].lca]]] ? 1 : 0) : 0);
	}
	for(int i=0;i<m;i++)
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