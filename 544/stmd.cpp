#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[200001];
int degx[200001];
bool vis[200001];

void bfs_visit(int n, int m, int s)
{
	std::queue<int> Q;
	Q.push(s);
	vis[s] = 1;
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

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		degx[s]++;
		degx[d]++;
	}	
	int nd = 0, dg = 0;
	for(int i=1;i<=n;i++)
	{
		if(dg < degx[i])
		{
			nd = i;
			dg = degx[i];
		}
	}	
	bfs_visit(n, m, nd);
	return 0;
}