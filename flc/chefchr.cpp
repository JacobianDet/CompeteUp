#include <bits/stdc++.h>

int arr[27];
int sze[27];

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
	for(int i=1;i<=26;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	dsu T;
	T.find_union('c'-'a'+1, 'h'-'a'+1);
	T.find_union('c'-'a'+1, 'e'-'a'+1);
	T.find_union('c'-'a'+1, 'f'-'a'+1);
	while(t--)
	{
		std::string s;
		std::cin>>s;
		int ctr = 0;
		for(int i=0,j=(int)s.size();i<=j-4;i++)
		{
			int a = T.root(s[i]-'a'+1);
			int b = T.root(s[i+1]-'a'+1);
			int c = T.root(s[i+2]-'a'+1);
			int d = T.root(s[i+3]-'a'+1);
			if((a == b) && (b == c) && (c == d) && (s[i] != s[i+1]) && (s[i] != s[i+2]) && (s[i] != s[i+3]) && (s[i+1] != s[i+2]) && (s[i+1] != s[i+3]) && (s[i+2] != s[i+3]))
			ctr++;	
		}
		if(ctr)
		std::cout<<"lovely "<<ctr<<"\n";
		else std::cout<<"normal"<<"\n";
	}
	return 0;	
}