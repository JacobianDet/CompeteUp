#include <bits/stdc++.h>
#define pb push_back

int qz[300001];
std::vector<int> G[300001];
bool vis[300001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>qz[i];
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
	}	
	vis[qz[n-1]] = 1;
	int inx = 1, ans = 0;
	for(int i=n-2;i>=0;i--)
	{
		int rep = 0;
		for(auto u : G[qz[i]])
		{
			if(vis[u])
			rep++;	
		}
		if(rep == inx)
		ans++;
		else
		{
			vis[qz[i]] = 1;
			inx++;
		}	
	}
	std::cout<<ans<<"\n";
	return 0;
}