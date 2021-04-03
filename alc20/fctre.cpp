#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF (1LL<<57)
#define MV 3000001
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

const int MOD = 1000000007;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct h_llint {
  static uint64_t splitmix64(uint64_t x) {    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

struct h_pair{
  size_t operator()(const PLL&x)const{
    return hash<ll>()(((ll)x.ff)^(((ll)x.ss)<<32));
  }
};

typedef map<ll, ll> MLL;
typedef map<PII, int> MPII;
typedef map<PLL, ll> MPLL;
typedef set<int> SI;
typedef set<ll> SL;
//ordered_set = order_of_key(.)
//ordered_set = find_by_order(.)
typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef ordered_multiset<int> MOSI;
typedef ordered_multiset<ll> MOSL;
typedef unordered_map<ll, int, h_llint> UMLI;
typedef unordered_map<ll, ll, h_llint> UMLL;
typedef unordered_map<PLL, int, h_pair> UMPI;
typedef unordered_map<PLL, ll, h_pair> UMPL;

int ar[MV], lo[MV], lvl[MV], fx[MV], xz[MV], dsc[MV], fin[MV];
ll arr[MV], res[MV], inv[MV];
int P[MV][LMV];
VI G[MV];
vector<PII> pf[MV];
int tx;

void siever(void)
{
	iota(lo, lo+MV, 0);
	for(ll p=2;p*p<MV;p++)
	{
		if(lo[p] == p)
		{
			for(ll i=p*p;i<MV;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}	
		}
	}
	inv[1] = 1;
	for(ll i=2;i<MV;i++)
	inv[i] = ((1LL*(MOD - (MOD/i))%MOD) * (1LL*inv[MOD%i]%MOD))%MOD;	
	return;
}

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
	memset(arr, 0, sizeof(arr));
	int n;
	cin>>n;
	const int Z = (int)sqrt(2*n);
	tx = 0;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];
		int tu = ar[i];
		while(tu > 1)
		{
			int p = lo[tu];
			int ct = 0;
			while(!(tu % p))
			{
				tu /= p;
				ct++;
			}
			pf[i].pb({p, ct});
		}
	}	
	dfs_visit(1, -1);
	sparse X;
	X.ST_build(n);
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
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
	sort(Q, Q+q, [Z](sq A, sq B){ return ((A.l/Z < B.l/Z) || ((A.l/Z == B.l/Z) && (((A.l/Z) & 1) ? (A.r < B.r) : (A.r > B.r)))); });
	int mo_l = 1, mo_r = 0;
	ll rx = 1;
	/*for(int i=0;i<m;i++)
	{
		cout<<Q[i].l<<" "<<Q[i].r<<" "<<Q[i].lca<<"\n";
	}*/	
	for(int i=0;i<q;i++)
	{
		int l = Q[i].l;
		int r = Q[i].r;
		while(mo_l > l)
		{
			mo_l--;
			xz[fx[mo_l]] ^= 1;
			if(xz[fx[mo_l]])
			{	
				for(auto &&u : pf[fx[mo_l]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] += u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}	
			}		
			else 
			{
				for(auto &&u : pf[fx[mo_l]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] -= u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}	
		}
		while(mo_r < r)
		{
			mo_r++;
			xz[fx[mo_r]] ^= 1;
			if(xz[fx[mo_r]])
			{	
				for(auto &&u : pf[fx[mo_r]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] += u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}		
			else 
			{
				for(auto &&u : pf[fx[mo_r]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] -= u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}		
		}
		while(mo_l < l)
		{
			xz[fx[mo_l]] ^= 1;
			if(xz[fx[mo_l]])
			{	
				for(auto &&u : pf[fx[mo_l]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] += u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}		
			else 
			{
				for(auto &&u : pf[fx[mo_l]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] -= u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}	
			mo_l++;
		}
		while(mo_r > r)
		{
			xz[fx[mo_r]] ^= 1;
			if(xz[fx[mo_r]])
			{	
				for(auto &&u : pf[fx[mo_r]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] += u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}		
			else 
			{
				for(auto &&u : pf[fx[mo_r]])
				{
					rx = ((rx%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
					arr[u.ff] -= u.ss;
					rx = ((rx%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				}
			}	
			mo_r--;
		}
		res[Q[i].id] = rx;
		if(Q[i].lca != -1)
		{
			for(auto &&u : pf[fx[Q[i].lca]])
			{
				res[Q[i].id] = ((res[Q[i].id]%MOD) * (inv[arr[u.ff]+1]%MOD))%MOD;
				arr[u.ff] += u.ss;
				res[Q[i].id] = ((res[Q[i].id]%MOD) * ((arr[u.ff]+1)%MOD))%MOD;
				arr[u.ff] -= u.ss;
			}
		}
	}
	for(int i=0;i<q;i++)
	cout<<res[i]<<"\n";
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		pf[i].clear();
		xz[i] = 0;
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

	siever();
	cin>>T;
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