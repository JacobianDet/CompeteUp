#include <bits/stdc++.h>
#define CHOR 200001

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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	std::cin>>a[i];
	std::string s;
	std::cin>>s;
	for(int i=1;i<CHOR;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	dsu T;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		if(s[i] == '1')
		T.find_union(i+1, i+2);
	}	
	int ctr = 0;
	for(int i=1;i<=n;i++)
	{
		if(T.root(a[i]) == T.root(i))
		ctr++;	
	}	
	if(ctr == n)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}