#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define indc std::vector<std::pair<int, int> >

indc ski;
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
	int n;
	std::cin>>n;
	dsu T;
	for(int i=0;i<n;i++)
	{
		int a,b;
		std::cin>>a>>b;
		ski.pb(mp(a,b));
		arr[(a-1)*1000 + b] = (a-1)*1000 + b;
		sze[(a-1)*1000 + b] = 1;
	}
	for(indc::iterator it = ski.begin(); it != ski.end(); it++)
	{
		int x = it->first;
		int y = it->second;
		for(int i=1;i<=1000;i++)
		{
			if(find(ski.begin(), ski.end(), mp(i,y)) != ski.end())
			T.find_union((i-1)*1000 + y, (x-1)*1000 + y);
			if(find(ski.begin(), ski.end(), mp(x,i)) != ski.end())	
			T.find_union((x-1)*1000 + i, (x-1)*1000 + y);	
		}	
	}	
	std::set<int> s;
	for(indc::iterator it = ski.begin(); it != ski.end(); it++)
	{
		int x = it->first;
		int y = it->second;
		s.insert(T.root((x-1)*1000 + y));
	}	
	std::cout<<s.size()-1<<"\n";
	return 0;
}