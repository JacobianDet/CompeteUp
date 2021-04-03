#include <bits/stdc++.h>
#define pb push_back
#define CHOR 200001

std::vector<int> G[CHOR];
int par[CHOR], arr[CHOR];

void dfs_visit(int s, int p)
{
	par[s] = p;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		dfs_visit(G[s][i], s);	
	}	
	return;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	if(arr[0] != 1)
	std::cout<<"No\n";
	else
	{
		dfs_visit(1, 0);
		std::queue<int> Q;
		Q.push(arr[0]);
		int x = 1;
		bool ok = 1;
		while(!Q.empty())
		{
			int m = (int)Q.size();
			for(int i=0;i<m;i++)
			{
				int s = Q.front();
				Q.pop();
				for(int j=0,k=(int)G[s].size();j<((s == 1) ? k : (k-1));j++)
				{
					if(x < n)
					{
						if(par[arr[x]] == s)
						{
							Q.push(arr[x]);
							x++;
						}	
						else 
						{
							ok = 0;
							break;
						}

					}
				}
				if(!ok)
				break;		
			}
			if(!ok)
			break;	
		}
		if(!ok)
		std::cout<<"No\n";
		else std::cout<<"Yes\n";
	}
	return 0;		
}