#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

typedef long long ll;

std::vector<ll> G[CHOR];
std::vector<ll> psn[CHOR];
std::vector<ll> arr[CHOR][20];
ll par[CHOR], lvl[CHOR];
ll P[CHOR][20];

void dfs_visit(ll s, ll p)
{
	if(p != -1)
	{
		par[s] = p;
		lvl[s] = 1 + lvl[p];
	}	
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{	
		if(G[s][i] != p)
		dfs_visit(G[s][i], s);
	}
	return;
}

std::vector<ll> merger(std::vector<ll> left, std::vector<ll> right)
{
	std::vector<ll> res;
	ll n1 = (ll)left.size(), n2 = (ll)right.size();
	ll i=0, j=0, k=0;
	while(i != n1 && j != n2 && k != 10)
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
		k++;
	}	
	while(i != n1 && k != 10)
	{
		res.pb(left[i]);
		i++;
		k++;
	}	
	while(j != n2 && k != 10)
	{
		res.pb(right[j]);
		j++;
		k++;
	}	
	return res;
}

void ST_build(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;(1<<j)<=n;j++)
		P[i][j] = -1;	
	}	
	for(ll i=1;i<=n;i++)
	{	
		P[i][0] = par[i];
		arr[i][0] = merger(psn[i], psn[par[i]]);
	}	
	for(ll j=1;(1<<j)<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			{	
				P[i][j] = P[P[i][j-1]][j-1];
				arr[i][j] = merger(arr[i][j-1], arr[P[i][j-1]][j-1]);
			}		
		}	
	}	
	return;
}

std::vector<ll> LCA_find(ll p, ll q)
{
	std::vector<ll> res = merger(psn[p], psn[q]);
	if(lvl[p] < lvl[q])
	{
		ll tmp = p;
		p = q;
		q = tmp;
	}	
	ll lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(ll i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		{	
			res = merger(res, arr[p][i]);
			p = P[p][i];	
		}	
	}	
	if(p == q)
	return res;
	for(ll i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			res = merger(res, arr[p][i]);
			res = merger(res, arr[q][i]);
			p = P[p][i];
			q = P[q][i];
		}	
	}	
	res = merger(res, arr[p][0]);
	res = merger(res, arr[q][0]);
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,m,q;
	std::cin>>n>>m>>q;
	for(ll i=0;i<n-1;i++)
	{
		ll s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(ll i=1;i<=m;i++)
	{
		ll t;
		std::cin>>t;
		if((ll)psn[t].size() < 10)
		psn[t].pb(i);
	}	
	dfs_visit(1, -1);
	ST_build(n);
	while(q--)
	{
		ll v,u,a;
		std::cin>>v>>u>>a;
		std::vector<ll> ans = LCA_find(v, u);
		a = std::min(a, (ll)ans.size());
		std::cout<<a<<" ";
		for(ll i=0;i<a;i++)
		std::cout<<ans[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}