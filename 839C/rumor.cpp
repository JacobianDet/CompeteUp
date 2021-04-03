#include <bits/stdc++.h>
#define ll long long

int arr[100001];
int sze[100001];
int minx[100001];

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
					minx[rx] = std::min(minx[rx], minx[ry]);
				}	
				else
				{
					arr[rx] = ry;
					sze[ry] += sze[rx];
					minx[ry] = std::min(minx[rx], minx[ry]);
				}	
				return;
			}
};

int main(void)
{
	memset(arr,0,sizeof(arr));
	memset(sze,0,sizeof(sze));
	memset(minx,0,sizeof(minx));
	int n,m;
	std::cin>>n>>m;
	dsu T;
	for(int i=1;i<=n;i++)
	{	
		std::cin>>minx[i];
		arr[i] = i;
		sze[i] = 1;
	}	
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		T.find_union(s,d);
	}	
	std::set<int> s;
	for(int i=1;i<=n;i++)
	s.insert(T.root(i));
	ll ans = 0;
	for(std::set<int>::iterator it = s.begin(); it != s.end(); it++)
	ans += minx[*it];
	std::cout<<ans<<"\n";
	return 0;
}