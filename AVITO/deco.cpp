#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001

std::vector<int> G[CHOR];
int deg[CHOR];

int dfs_visit(int s, int p)
{
	int x = s;
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		x = dfs_visit(G[s][i], s);	
	}	
	return x;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		deg[s]++;
		deg[d]++;
		G[s].pb(d);
		G[d].pb(s);
	}	
	int ct = 0;
	for(int i=1;i<=n;i++)
	{
		if(deg[i] > 2)
		ct++;	
	}	
	if(ct > 1)
	std::cout<<"No\n";
	else
	{
		int mdeg = 0;
		int s = 0;
		for(int i=1;i<=n;i++)
		{
			if(mdeg < deg[i])
			{
				mdeg = deg[i];
				s = i;
			}	
		}
		std::cout<<"Yes\n"<<mdeg<<"\n";
		for(int i=0,j=(int)G[s].size();i<j;i++)
		std::cout<<s<<" "<<dfs_visit(G[s][i], s)<<"\n";
	}	
	return 0;
}