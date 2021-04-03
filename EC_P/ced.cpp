#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<int> G[100001];
int lt[100001], dsc[100001];
bool vis[100001];
int tx; 
std::vector<std::pair<int, int> > Z;

void dfs_visit(int s, int p)
{
	vis[s] = 1;
	dsc[s] = lt[s] = ++tx;
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			dfs_visit(u, s);
			lt[s] = std::min(lt[s], lt[u]);
			if(lt[u] > dsc[s])
			{	
				int x = std::min(s, u);
				int y = std::max(s, u);
				Z.pb(mp(x, y));
			}		
		}
		else if(u != p)
		lt[s] = std::min(lt[s], dsc[u]);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{	
		Z.clear();
		memset(dsc, 0, sizeof(dsc));
		memset(lt, 0, sizeof(lt));
		memset(vis, 0, sizeof(vis));
		tx = 0;
		int n,m;
		std::cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int s,d;
			std::cin>>s>>d;
			G[s].pb(d);
			G[d].pb(s);
		}	
		dfs_visit(1, -1);
		std::sort(Z.begin(), Z.end());
		std::cout<<"Caso #"<<t<<"\n";
		if(!Z.size())
		std::cout<<"Sin bloqueos\n";
		else
		{
			std::cout<<Z.size()<<"\n";
			for(auto u : Z)
			std::cout<<u.first<<" "<<u.second<<"\n";	
		}
		for(int i=1;i<=n;i++)
		G[i].clear();	
	}	
	return 0;
}		