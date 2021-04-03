#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[100001];
bool vis[100001];
std::vector<int> ax;

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
	}	
	std::set<int> S;
	S.insert(1);
	while(!S.empty())
	{
		int s = *S.begin();
		S.erase(S.begin());
		vis[s] = 1;
		ax.pb(s);
		for(auto u : G[s])
		{
			if(!vis[u])
			S.insert(u);	
		}
	}
	for(int i=0;i<n;i++)
	std::cout<<ax[i]<<" ";
	std::cout<<"\n";
	return 0;	
}