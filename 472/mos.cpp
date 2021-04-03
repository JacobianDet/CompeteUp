#include <bits/stdc++.h>
#define pb push_back

int arr[101];
int sze[101];
int ld[101];

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
	std::string s[51];
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	for(int i=1;i<=100;i++)
	{
		arr[i] = i;
		sze[i] = 1;
		ld[i] = i;
	}	
	dsu T;
	std::vector<int> H[51];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j] == '#')
			H[i].pb(j+1);
		}	
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0,k=(int)H[i].size();j<k;j++)
		{
			if(ld[T.root(H[i][j])] < 51)
			{	
				T.find_union(H[i][j], 51+i);
				ld[T.root(H[i][j])] = 51+i;
			}	
		}	
	}	
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		int k = H[i].size();
		int rt = -1;
		if(k > 0)
		{
			rt = ld[T.root(H[i][0])];
			if((int)H[rt-51].size() != k)
			ok = 0;	
		}	
		for(int j=0;j<k;j++)
		{
			if(ld[T.root(H[i][j])] != rt)
			ok = 0;	
		}	
	}	
	if(!ok)
	std::cout<<"No\n";
	else std::cout<<"Yes\n";
	return 0;	
}