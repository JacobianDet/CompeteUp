#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back

typedef long long ll;

std::vector<int> G[100001];
int BIT[100001];
int lvl[100001], par[100001], P[100001][20], st[100001], sz[100001], arr[100001], mark[100001], hnt[100001];
ll memo[100002][301];
int tx;

class fentree
{
	public: void update(int i, int n, int val)
			{
				for( ;i<=n;i+=(i & (-i)))
				BIT[i] += val;
				return;	
			} 

			int query(int i)
			{
				int ans = 0;
				for( ;i>0;i-=(i & (-i)))
				ans += BIT[i];
				return ans;
			}
};

void dfs_visit(int s, int p)
{
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}	
	tx++;
	st[s] = tx;
	sz[s]++;
	for(auto u : G[s])
	{
		if(u != p)
		{
			dfs_visit(u, s);
			sz[s] += sz[u];
		}	
	}	
	return;
}

void ST_build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		P[i][j] = -1;
	}
	for(int i=1;i<=n;i++)
	P[i][0] = par[i];
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
 
int LCA_find(int p, int q)
{
	if(lvl[p] < lvl[q])
	{
		int tmp = p;
		p = q;
		q = tmp;
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
	return par[p];
}

bool cmpx(int A, int B)
{
	return hnt[A] < hnt[B];
}

/*ll GRP(int i, int j, int h)
{
	if(i == k+1)
	return 1;
	if(vis[i][j] == h)
	return memo[i][j];
	ll ans = 0;
	if(j < m)
	ans = ((ans%MOD) + (GRP(i+1, j+1, h)%MOD))%MOD;
	if(j > 0)
	ans = ((ans%MOD) + (((GRP(i+1, j, h)%MOD) * ((1LL*j - 1LL*hnt[arr[i]])%MOD))%MOD))%MOD;
	vis[i][j] = h;
	memo[i][j] = ans;
	return ans;	
}*/

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, 0, sizeof(memo));
	int n,q;
	std::cin>>n>>q;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	tx = 0;
	dfs_visit(1, -1);
	ST_build(n);
	fentree T;
	for(int h=1;h<=q;h++)
	{
		int k,m,r;
		std::cin>>k>>m>>r;
		for(int i=1;i<=k;i++)
		{	
			std::cin>>arr[i];
			mark[arr[i]] = 1;
			T.update(st[arr[i]], n, 1);
			T.update(st[arr[i]] + sz[arr[i]], n, -1);
		}
		for(int i=1;i<=k;i++)
		hnt[arr[i]] = T.query(st[arr[i]]) + T.query(st[r]) - 2*T.query(st[LCA_find(arr[i], r)]) + (mark[LCA_find(arr[i], r)] == 1) - 1;
		for(int i=1;i<=k;i++)
		{
			mark[arr[i]] = 0;
			T.update(st[arr[i]], n, -1);
			T.update(st[arr[i]] + sz[arr[i]], n, 1);
		}
		std::sort(arr+1, arr+k+1, cmpx);
		for(int i=0;i<=m;i++)
		memo[k+1][i] = 1;
		for(int i=k;i>0;i--)
		{
			for(int j=m;j>=0;j--)
			{
				memo[i][j] = 0;
				if(j > 0)
				memo[i][j] = ((memo[i][j]%MOD) + ((memo[i+1][j]%MOD) * ((1LL*j - 1LL*hnt[arr[i]])%MOD))%MOD)%MOD;
				if(j < m)
				memo[i][j] = ((memo[i][j]%MOD) + (memo[i+1][j+1]%MOD))%MOD;
			}
		}
		std::cout<<memo[1][0]<<"\n";
	}
	return 0;
}