#include <bits/stdc++.h>

int arr[200];
int sze[200];

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
	memset(arr,-1,sizeof(arr));
	memset(sze,0,sizeof(sze));
	int n,m;
	std::cin>>n>>m;
	dsu T;
	for(int i=0;i<n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	for(int i=0;i<m;i++)
	{
		arr[100+i] = 100+i;
		sze[100+i] = 1;
	}	
	int b;
	std::cin>>b;
	std::set<int> boy;
	std::set<int> girl;
	for(int i=0;i<b;i++)
	{	
		int x,y;
		std::cin>>x;
		boy.insert(x);
		if(boy.size() == 1)
		y = x;	
		T.find_union(y, x);
		y = x;
	}
	int g;
	std::cin>>g;
	for(int i=0;i<g;i++)
	{
		int x,y;
		std::cin>>x;
		girl.insert(100+x);
		if(girl.size() == 1)
		y = 100 + x;	
		T.find_union(y, 100+x);
		y = 100 + x;
	}		
	if(boy.size() && girl.size())
	T.find_union(*boy.begin(), *girl.begin());
	int lim = n*m/std::__gcd(n,m);
	for(int i=0;i<2*lim;i++)
	{
		int x = i%n;
		int y = 100 + i%m;
		if((boy.find(x) != boy.end()) || (girl.find(y) != girl.end()))
		{	
			T.find_union(x, y);
			boy.insert(x);
			girl.insert(y);
		}	
	}
	int z = T.root(*boy.begin());
	if(sze[z] != n+m)
	std::cout<<"No\n";
	else std::cout<<"Yes\n";	
	return 0;	
}