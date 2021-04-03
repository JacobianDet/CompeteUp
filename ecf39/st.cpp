#include <bits/stdc++.h>

int arr[28];
int sze[28];
int ld[28];

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
	std::string s;
	std::cin>>s;
	dsu T;
	for(int i=1;i<=27;i++)
	{
		arr[i] = i;
		ld[i] = i;
		sze[i] = 1;
	}	
	int c = 0;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		if(c == 26)
		break;
		int rx = ld[T.root((int)(s[i]-96))];
		if(rx == c+1)
		{
			c++;
			T.find_union(rx, c+1);
			s[i] = (char)(c + 96);
			ld[T.root(rx)] = ld[c+1];
		}
	}	
	if(c == 26)
	std::cout<<s<<"\n";
	else std::cout<<"-1\n";
	return 0;	
}