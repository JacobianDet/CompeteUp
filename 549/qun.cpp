#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::set<int> res;
std::vector<int> G[100001];
int cx[100001];

void bfs_visit(int rx)
{
	std::queue<std::pair<int, int> > Q;
	Q.push(mp(rx, -1));
	while(!Q.empty())
	{
		std::pair<int, int> px = Q.front();
		Q.pop();
		bool ok = (cx[px.first] ? 1 : 0);
		for(auto u : G[px.first])
		{
			if(u != px.second)
			{
				if(!cx[u])
				ok = 0;
				Q.push(mp(u, px.first));
			}	
		}
		if(ok)
		res.insert(px.first);	
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	int rx = -1;
	for(int i=1;i<=n;i++)
	{
		int p;
		std::cin>>p>>cx[i];
		if(p == -1)
		rx = i;
		else
		{
			G[p].pb(i);
			G[i].pb(p);
		}	
	}
	bfs_visit(rx);
	if(!res.size())
	std::cout<<"-1\n";
	else
	{
		for(auto u : res)
		std::cout<<u<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}