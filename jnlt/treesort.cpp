#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back
#define mp std::make_pair

std::vector<int> G[CHOR];
int lv[CHOR];

std::pair<int, int> merger(std::pair<int, int> p1, std::pair<int, int> p2, int& ctx)
{
	if(p1.second + 1 == p2.first)
	ctx += 0;
	else if(p2.second + 1 == p1.first)
	ctx += 1;
	else ctx = -100000000;
	return mp(std::min(p1.first, p2.first), std::max(p1.second, p2.second));	
}

std::pair<int, int> dfs_visit(int s, int& ctx)
{
	std::pair<int, int> p;
	if((int)G[s].size() == 0)
	p = mp(lv[s], lv[s]);
	else p = merger(dfs_visit(G[s][0], ctx), dfs_visit(G[s][1], ctx), ctx);
	return p;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			int l,r;
			std::cin>>l>>r;
			if(l == -1)
			lv[i] = r;
			else 
			{
				G[i].pb(l);
				G[i].pb(r);
			}	
		}
		int ctx = 0;
		std::pair<int, int> p = dfs_visit(1, ctx);
		if(ctx < 0)
		std::cout<<"-1\n";
		else std::cout<<ctx<<"\n";
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			lv[i] = 0;
		}	
	}
	return 0;
}