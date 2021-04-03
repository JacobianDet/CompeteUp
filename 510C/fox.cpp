#include <bits/stdc++.h>
#define pb push_back

std::string s[101];
std::vector<int> G[27];
int indeg[27];
int vis[27];

bool dfs_vis1(int s)
{
	vis[s] = 1;
	bool ok = 0;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(!vis[G[s][i]])
		ok |= dfs_vis1(G[s][i]);
		else if(vis[G[s][i]] == 1)
		ok = 1;	
	}	
	vis[s] = 2;
	return ok;
}

void bfs_visx(void)
{
	std::queue<int> Q;
	for(int i=1;i<=26;i++)
	{
		if(!indeg[i])
		Q.push(i);	
	}
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		std::cout<<(char)(u + 96);
		for(auto v : G[u])
		{
			indeg[v]--;
			if(!indeg[v])
			Q.push(v);	
		}	
	}
	std::cout<<"\n";
	return;	
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	bool ok = 0;
	for(int i=0;i<n;i++)
	{
		if(i && (s[i-1][0] == s[i][0]))
		{
			bool iok = 0;
			for(int j=0,k=std::min((int)s[i-1].size(), (int)s[i].size());j<k;j++)
			{
				if(s[i-1][j] != s[i][j])
				{
					iok = 1;
					G[(s[i-1][j] - 'a' + 1)].pb((s[i][j] - 'a' + 1));
					break;
				}	
			}	
			if(!iok)
			{
				if((int)s[i-1].size() > (int)s[i].size())
				{
					ok = 1;
					break;
				}	
			}	
		}	
		else if(i)
		G[(s[i-1][0] - 'a' + 1)].pb((s[i][0] - 'a' + 1));	
	}	
	if(!ok)
	{	
		for(int i=1;i<=26;i++)
		{
			if(!vis[i])
			ok |= dfs_vis1(i);	
		}	
	}
	if(ok)
	std::cout<<"Impossible\n";
	else
	{
		for(int i=1;i<=26;i++)
		{
			for(auto x : G[i])
			indeg[x]++;
		}	
		bfs_visx();
	}
	return 0;	
}