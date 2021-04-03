#include <bits/stdc++.h>
#define pb push_back

std::vector<int> G[5001];
int mv[5001];

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
	}	
	for(int i=1;i<=n;i++)
	{
		int sz = (int)G[i].size();
		if(sz)
		{
			int mn = 100000000;
			for(auto u : G[i])
			mn = std::min(mn, (u - i + n)%n);
			mv[i] = (sz - 1)*n + mn;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		int mx = 0;
		for(int j=1;j<=n;j++)
		{	
			if(mv[j])
			mx = std::max(mx, (j - i + n)%n + mv[j]);
		}
		std::cout<<mx<<" ";
	}
	std::cout<<"\n";
	return 0;	
}