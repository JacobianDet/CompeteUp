#include <bits/stdc++.h>

int arr[10001];
int sze[10001];

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
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			arr[(i-1)*100 + j] = (i-1)*100 + j;
			sze[(i-1)*100 + j] = 1;
		}	
	}	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		std::cin>>a>>b>>c;
		T.find_union((c-1)*100 + a, (c-1)*100 + b);
	}	
	int q;
	std::cin>>q;
	for(int i=0;i<q;i++)
	{
		int x,y,ct=0;
		std::cin>>x>>y;
		for(int j=1;j<=m;j++)
		{
			int a = T.root((j-1)*100 + x);
			int b = T.root((j-1)*100 + y);
			if(a == b)
			ct++;	
		}
		std::cout<<ct<<"\n";	
	}	
	return 0;
}