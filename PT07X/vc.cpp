#include <bits/stdc++.h>
#define pb push_back
#define CHOR 100001

std::vector<std::vector<int> > G(CHOR);
int vx[CHOR][3];

int dfs_visit(int s, int p, int x)
{
	int j = (int)G[s].size();	
	if(j == 1 && G[s][j-1] == p)
	{
		if(x)
		return 0;
		else return 1;	
	}	
	if(vx[s][x] != CHOR)
	return vx[s][x];
	int a0 = 0, a1 = 1;	
	int ans = 0;
	for(int i=0;i<j;i++)
	{
		if(G[s][i] != p)
		{
			if(x == 2 || x == 1)
			{
				a1 += dfs_visit(G[s][i], s, 1);
				a0 += dfs_visit(G[s][i], s, 0);
			}
			else a1 += dfs_visit(G[s][i], s, 1);
		}	
	}
	if(x)
	ans = std::min(a1, a0);
	else ans = a1;
	vx[s][x] = ans;
	return ans;	
}

int main(void)
{
	for(int i=0;i<CHOR;i++)
	{
		for(int j=0;j<3;j++)
		vx[i][j] = CHOR;	
	}
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	int vcov = dfs_visit(1, 0, 2);
	std::cout<<vcov<<"\n";
	return 0;
}