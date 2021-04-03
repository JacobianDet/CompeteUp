#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 1000000007

std::map<std::pair<int, int>, int> cord;
std::map<int, std::pair<int, int> > crx;
int mdx[25][25], memo[(1<<24)], par[(1<<24)];
int usx[24];

/*int YANK(int mask)
{
	if(mask == (1<<n) - 1)
	return 0;
	if(memo[mask] != -1)
	return memo[mask];
	int ans = INF;
	if(__builtin_popcount(mask) <= n-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(!(mask & (1<<(i-1))))
			{
				if(ans > 2 * mdx[i][0] + YANK(mask | (1<<(i-1))))
				{
					par[mask] = (mask | (1<<(i-1)));
					ans = std::min(ans, 2 * mdx[i][0] + YANK(mask | (1<<(i-1))));
				}
			}	
		}
	}
	if(__builtin_popcount(mask) <= n-2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((i != j) && !(mask & (1<<(i-1))) && !(mask & (1<<(j-1))))
				{	
					if(ans > mdx[i][0] + mdx[j][0] + mdx[i][j] + YANK((mask | (1<<(i-1))) | (1<<(j-1))))
					{	
						par[mask] = ((mask | (1<<(i-1))) | (1<<(j-1)));
						ans = std::min(ans, mdx[i][0] + mdx[i][j] + mdx[j][0] + YANK((mask | (1<<(i-1))) | (1<<(j-1))));
					}
				}	
			}
		}
	}
	memo[mask] = ans;
	return ans;
}*/	

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int x,y;
	std::cin>>x>>y;
	cord[mp(x, y)] = 0;
	crx[0] = mp(x, y);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		std::cin>>a>>b;
		cord[mp(a, b)] = i;
		crx[i] = mp(a, b);
	}
	for(int i=1;i<=n;i++)
	mdx[i][0] = abs(crx[i].first - crx[0].first) * abs(crx[i].first - crx[0].first) + abs(crx[i].second - crx[0].second) * abs(crx[i].second - crx[0].second);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{	
			mdx[i][j] = abs(crx[i].first - crx[j].first) * abs(crx[i].first - crx[j].first) + abs(crx[i].second - crx[j].second) * abs(crx[i].second - crx[j].second);
			mdx[j][i] = abs(crx[i].first - crx[j].first) * abs(crx[i].first - crx[j].first) + abs(crx[i].second - crx[j].second) * abs(crx[i].second - crx[j].second);
		}
	}	
	for(int i=0;i<(1<<n);i++)
	{
		memo[i] = INF;
		par[i] = i;
	}
	memo[(1<<n) - 1] = 0;
	for(int mask = (1<<n)-2;mask>=0;mask--)
	{
		int sz = 0;
		for(int i=0;i<n;i++)
		{
			if(!(mask & (1<<i)))
			{	
				usx[sz] = i+1;
				sz++;
			}
		}	
		if(__builtin_popcount(mask) <= n-1)
		{
			for(int x=0;x<sz;x++)
			{
				int i = usx[x];
				if(memo[mask] > 2 * mdx[i][0] + memo[mask | (1<<(i-1))])
				{
					par[mask] = (mask | (1<<(i-1)));
					memo[mask] = std::min(memo[mask], 2 * mdx[i][0] + memo[mask | (1<<(i-1))]);
				}	
			}	
		}
		if(__builtin_popcount(mask) <= n-2)
		{
			for(int x=0;x<sz;x++)
			{
				for(int y=x+1;y<sz;y++)
				{
					int i = usx[x];
				       	int j = usx[y];	
					if(memo[mask] > mdx[i][0] + mdx[j][0] + mdx[i][j] + memo[(mask | (1<<(i-1))) | (1<<(j-1))])
					{	
						par[mask] = ((mask | (1<<(i-1))) | (1<<(j-1)));
						memo[mask] = std::min(memo[mask], mdx[i][0] + mdx[i][j] + mdx[j][0] + memo[(mask | (1<<(i-1))) | (1<<(j-1))]);
					}	
				}
				break;
			}
		}
	}			
	std::cout<<memo[0]<<"\n";
	int st = 0;
	std::cout<<"0 ";
	while(st != ((1<<n) - 1))
	{
		int nst = par[st];
		for(int i=0;i<n;i++)
		{
			if((st ^ nst) & (1<<i))
			std::cout<<(i+1)<<" ";
		}	
		std::cout<<"0 ";
		st = nst;
	}
	std::cout<<"\n";
	return 0;
}	
		
