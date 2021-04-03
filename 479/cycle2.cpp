#include <bits/stdc++.h>
#define CHOR 200001

struct dEL
{
	int arr,sze;
	bool ic;
}happu[CHOR];

int deg[CHOR];

class dsu
{
	public: int root(int x)
			{
				while(x != happu[x].arr)
				x = happu[happu[x].arr].arr;
				return x;	
			}
 
			void find_union(int x, int y)
			{
				int rx = root(x);
				int ry = root(y);
				if(rx == ry)
				return;
				if(happu[rx].sze > happu[ry].sze)
				{
					happu[ry].arr = rx;
					happu[rx].sze += happu[ry].sze;
				}	
				else
				{
					happu[rx].arr = ry;
					happu[ry].sze += happu[rx].sze;
				}	
				return;
			}
};

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		happu[i].arr = i;
		happu[i].sze = 1;
		happu[i].ic = 1;
	}	
	dsu T;
	for(int i=0;i<m;i++)
	{
		int u,v;
		std::cin>>u>>v;
		deg[u]++;
		deg[v]++;
		T.find_union(u, v);		
	}	
	for(int i=1;i<=n;i++)
	{
		if(deg[i] != 2)
		happu[T.root(i)].ic = 0;	
	}	
	std::set<int> amma;
	for(int i=1;i<=n;i++)
	{
		if(happu[T.root(i)].ic)
		amma.insert(T.root(i));	
	}	
	std::cout<<amma.size()<<"\n";
	return 0;
}