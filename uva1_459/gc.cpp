#include <bits/stdc++.h>

int arr[26];
int sze[26];

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
	int t;
	std::cin>>t;
	for(int i=0;i<t;i++)
	{
		memset(arr,-1,sizeof(arr));
		memset(sze,0,sizeof(sze));
		char l;
		std::cin>>l;
		dsu T;
		for(int i=0;i<=(l-65);i++)
		{
			arr[i] = i;
			sze[i] = 1;
		}	
		std::cin.ignore();
		std::string s;
		while(std::getline(std::cin, s))
		{
			if(s.empty())
			break;
			else T.find_union(s[0]-65, s[1]-65);	
		}
		std::set<int> compc;
		for(int i=0;i<=(l-65);i++)
		compc.insert(T.root(i));
		std::cout<<compc.size()<<"\n \n";	
	}	
	return 0;
}