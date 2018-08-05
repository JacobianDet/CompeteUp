#include <bits/stdc++.h>
#define CHOR 100001

int arr[CHOR];
int sze[CHOR];
 
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
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<CHOR;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	int a[n];
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	dsu T;
	for(int i=0;i<m;i++)
	{
		int x,y;
		std::cin>>x>>y;
		T.find_union(a[x-1], a[y-1]);
	}	
	int ctr = 0;
	for(int i=1;i<=n;i++)
	{
		if(T.root(i) == T.root(a[i-1]))
		ctr++;	
	}	
	std::cout<<ctr<<"\n";
	return 0;	
}