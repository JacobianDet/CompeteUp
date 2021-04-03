#include <bits/stdc++.h>

int p[5001], c[5001];

struct sf
{
	int id, pot;

	bool operator < (const sf& wx) const
	{
		return (pot < wx.pot);
	}
};

std::set<sf> ZX[5001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	std::cin>>p[i];
	for(int i=1;i<=n;i++)
	std::cin>>c[i];
	for(int i=1;i<=n;i++)
	ZX[c[i]].insert({i, p[i]});	
	int d;
	std::cin>>d;
	while(d--)
	{
		int ix;
		std::cin>>ix;
		ZX[c[ix]].erase({ix, p[ix]});
		std::set<int> mpr;
		for(int i=1;i<=m;i++)
		{
			if(!ZX[i].empty())
			mpr.insert((ZX[i].begin())->pot);	
		}	
		int mexval = 0;
		for(auto u : mpr)
		{
			std::cout<<u<<" ";
			if(u == mexval)
			mexval++;
			else if(u > mexval)
			break;
			else continue;	
		}
		std::cout<<"\n";
		std::cout<<mexval<<"\n";
	}
	return 0;
}