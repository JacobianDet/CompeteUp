#include <bits/stdc++.h>
#define pb push_back

int arr[101];
int sze[101];

class dsu
{
	public: int root(int x)
			{
				while(x != arr[x])
				x = arr[arr[x]];
				return x;	
			}

			void find_union(int x, int y)
			{
				int rx = root(x);
				int ry = root(y);
				if(rx == ry)
				return;
				if(sze[rx] > sze[ry])
				{
					arr[ry] = rx;
					sze[rx] += sze[ry];
				}	
				else
				{
					arr[rx] = ry;
					sze[ry] += sze[rx];
				}	
				return;
			}
};

int main(void)
{
	memset(arr,0,sizeof(arr));
	memset(sze,0,sizeof(sze));
	int n,m;
	std::cin>>n>>m;
	dsu T;
	std::vector<std::vector<int> > G(m+1);
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	int flag = 0;
	for(int i=1;i<=n;i++)
	{
		int z;
		std::cin>>z;
		if(!z)
		flag++;	
		for(int j=0;j<z;j++)
		{
			int x;
			std::cin>>x;
			G[x].pb(i);
			T.find_union(*G[x].begin(), i);
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(find(G[j].begin(), G[j].end(), i) != G[j].end())
			T.find_union(*G[j].begin(), i);	
		}	
	}	
	std::set<int> s;
	for(int i=1;i<=n;i++)
	s.insert(T.root(i));
	if(flag == n)
	std::cout<<s.size()<<"\n";	
	else std::cout<<s.size()-1<<"\n";
	return 0;	
}