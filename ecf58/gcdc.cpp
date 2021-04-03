#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

int arr[200001], lo[200001];
std::vector<int> G[200001];
std::map<int, std::pair<int, std::pair<int, int> > > memo[200001];

void siever(void)
{
	for(int i=0;i<200001;i++)
	lo[i] = i;
	for(int p=2;p*p<200001;p++)
	{
		if(lo[p] == p)
		{
			for(int i=p*p;i<200001;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}	
		}
	}
	return;	
}

std::pair<int, std::pair<int, int> > dfs_visit(int s, int p, int px)
{
	if(memo[s].find(px) != memo[s].end())
	return memo[s][px];	
	int g = 0, gf = 0, hf1 = 0, hf2 = 0;
	for(auto u : G[s])
	{
		if(u != p)
		{
			int z = arr[u];
			while(z > 1)
			{
				int v = lo[z];
				std::pair<int, std::pair<int, int> > pv = dfs_visit(u, s, v);
				if(v != px)
				g = std::max(g, pv.first);
				else
				{
					gf = std::max(gf, pv.second.first);
					if(pv.second.second > hf1)
					{
						hf2 = hf1;
						hf1 = pv.second.second;
					}
					else if((hf1 >= pv.second.second) && (hf2 < pv.second.second))
					hf2 = pv.second.second;
				}	
				while(!(z % v))
				z /= v;	
			}
		}	
	}
	gf = std::max(gf, hf1 + hf2);
	if(gf > g)
	g = gf;
	memo[s][px] = mp(g, mp(gf, hf1 + 1));
	return mp(g, mp(gf, hf1 + 1));	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	int n;
	std::cin>>n;
	bool ok = 0;
	for(int i=1;i<=n;i++)
	{
		std::cin>>arr[i];
		if(arr[i] > 1)
		ok = 1;
	}
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}
	int z = arr[1];
	int dia = 0;
	while(z > 1)
	{
		int p = lo[z];
		std::pair<int, std::pair<int, int> > px = dfs_visit(1, -1, p);
		while(!(z % p))
		z /= p;
		dia = std::max(dia, px.first);
	}	
	if(ok)
	std::cout<<(dia + 1)<<"\n";
	else std::cout<<dia<<"\n";
	return 0;	
}