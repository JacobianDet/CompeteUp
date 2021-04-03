#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<int> G[200001];
int degx[200001], fin[200001], lt[200001], cct[200001];
bool vis[200001], isB[200001];
std::map<std::pair<int, int>, int> EX;
int tx;

void bfs_visit(int n, int m, int dx, int s)
{
	std::queue<int> Q;
	int xd = dx - cct[s];
	vis[s] = 1;
	for(auto u : G[s])
	{
		if(isB[EX[mp(s, u)]])
		{
			std::cout<<s<<" "<<u<<"\n";
			vis[u] = 1;
			Q.push(u);
		}	
		else if(xd > 0)
		{
			std::cout<<s<<" "<<u<<"\n";
			vis[u] = 1;
			Q.push(u);
			xd--;
		}
	}
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();	
		for(auto v : G[u])
		{
			if(!vis[v])
			{
				std::cout<<u<<" "<<v<<"\n";
				vis[v] = 1;
				Q.push(v);
			}	
		}
	}
	return;
}

void dfs_visit(int s, int p)
{
	vis[s] = 1;
	fin[s] = tx;
	lt[s] = tx;
	tx++;
	for(auto u : G[s])
	{
		if(u == p)
		continue;
		if(vis[u])
		lt[s] = std::min(lt[s], fin[u]);
		else
		{
			dfs_visit(u, s);
			lt[s] = std::min(lt[s], lt[u]);
			if(lt[u] >= fin[s])
			{	
				isB[EX[mp(s, u)]] = 1;	
				cct[s]++;
				cct[u]++;
			}	
		}	
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	tx = 0;
	int n,m,dx;
	std::cin>>n>>m>>dx;
	int zx = 0;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		EX[mp(s, d)] = zx;
		EX[mp(d, s)] = zx;
		zx++;
		degx[s]++;
		degx[d]++;
	}	
	dfs_visit(1, -1);	
	memset(vis, 0, sizeof(vis));
	int nd = -1;
	for(int i=1;i<=n;i++)
	{
		if(degx[i] >= dx && cct[i] <= dx)
		{
			nd = i;
			break;
		}	
	}	
	if(nd == -1)
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		bfs_visit(n, m, dx, nd);
	}	
	return 0;
}