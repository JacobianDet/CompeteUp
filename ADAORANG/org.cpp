#include <bits/stdc++.h>
#define CHOR 450001
#define pb push_back

int arr[CHOR];
std::vector<int> G[CHOR];
int par[CHOR], lvl[CHOR];
int P[CHOR][20];
std::vector<int> axe[CHOR];

std::vector<int> merger(std::vector<int> left, std::vector<int> right)
{
	std::vector<int> res;
	int i=0,j=0;
	int n1 = (int)left.size(), n2 = (int)right.size();
	while(i != n1 && j != n2)
	{
		if(left[i] < right[j])
		{
			res.pb(left[i]);
			i++;
		}	
		else if(left[i] > right[j])
		{
			res.pb(right[j]);
			j++;
		}	
		else
		{
			res.pb(left[i]);
			i++;
			j++;
		}	
	}	
	while(i != n1)
	{
		res.pb(left[i]);
		i++;
	}	
	while(j != n2)
	{
		res.pb(right[j]);
		j++;
	}	
	return res;
}

void dfs_visit(int s, int p)
{
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}
	axe[s].pb(arr[s]);
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		{	
			dfs_visit(G[s][i], s);
			axe[s] = merger(axe[s], axe[G[s][i]]);
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
	int lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];
	}
	if(p == q)
	return p;
	for(int i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}
	return par[p];	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,q,r;
		std::cin>>n>>q>>r;
		r++;
		for(int i=1;i<=n;i++)
		std::cin>>arr[i];
		for(int i=0;i<n-1;i++)
		{
			int s,d;
			std::cin>>s>>d;
			s++;
			d++;
			G[s].pb(d);
			G[d].pb(s);
		}	
		dfs_visit(r, -1);
		ST_build(n);
		while(q--)
		{
			int a,b;
			std::cin>>a>>b;
			a++;
			b++;
			int lca = LCA_find(a, b);
			std::cout<<(int)axe[lca].size()<<"\n";
		}
		for(int i=1;i<=n;i++)
		{	
			G[i].clear();
			axe[i].clear();
			lvl[i] = 0;
			par[i] = 0;
		}		
	}
	return 0;	
}