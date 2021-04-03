#include <bits/stdc++.h>
#define pb push_back

std::vector<std::vector<int> > G(101);
std::vector<int> lvl(101, -1);

void bfs_visit(int s)
{
	lvl[s] = 0;
	std::queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		for(int i=0,j=G[t].size();i<j;i++)
		{
			if(lvl[G[t][i]] == -1)
			{	
				lvl[G[t][i]] = lvl[t] + 1;
				q.push(G[t][i]);
			}	
		}	
	}
	return;	
}

int main(void)
{
	int n,d;
	std::cin>>n>>d;
	std::string s;
	std::cin>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=i+d;j++)
		{
			if((j <= n) && (s[j-1] - '0'))
			G[i].pb(j);	
		}	
	}
	bfs_visit(1);
	std::cout<<lvl[n]<<"\n";
	return 0;	
}