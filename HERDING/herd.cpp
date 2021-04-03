#include <bits/stdc++.h>

int arr[1000001];
int sze[1000001];

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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			arr[(i-1)*1000 + j] = (i-1)*1000 + j;
			sze[(i-1)*1000 + j] = 1;
		}	
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char z;
			std::cin>>z;
			if(z == 'N')
			T.find_union((i-1)*1000 + j, (i-2)*1000 + j);
			else if(z == 'E')
			T.find_union((i-1)*1000 + j, (i-1)*1000 + j+1);
			else if(z == 'W')
			T.find_union((i-1)*1000 + j, (i-1)*1000 + j-1);
			else T.find_union((i-1)*1000 + j, i*1000 + j);	
		}	
	}	
	std::set<int> s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		s.insert(T.root((i-1)*1000 + j));	
	}	
	std::cout<<s.size()<<"\n";
	return 0;
}