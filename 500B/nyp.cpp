#include <bits/stdc++.h>

int arr[301];
int sze[301];

void swapx(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

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
	int n;
	std::cin>>n;
	dsu T;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	int p[n+1];
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
	std::cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		std::string s;
		std::cin>>s;
		for(int j=0;j<n;j++)
		{
			if(s[j]-'0')
			T.find_union(i,j+1);	
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int x = T.root(i);
			int y = T.root(j);
			if(x == y)
			{
				if(p[j] < p[i])
				swapx(p[i], p[j]);	
			}	
		}	
	}
	for(int i=1;i<=n;i++)
	std::cout<<p[i]<<" ";
	std::cout<<"\n";
	return 0;	
}