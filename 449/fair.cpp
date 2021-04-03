#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int m,n;
	std::cin>>n>>m;
	std::string s;
	std::cin>>s;
	std::vector<int> l,r;
	std::vector<char> c1,c2;
	for(int i=0;i<m;i++)
	{
		int x;
		char y;
		std::cin>>x;
		l.pb(x);
		std::cin>>x;
		r.pb(x);
		std::cin>>y;
		c1.pb(y);
		std::cin>>y;
		c2.pb(y);
	}	
	for(int i=0;i<m;i++)
	{
		for(int j=l[i]-1;j<=r[i]-1;j++)
		{
			if(s[j] == c1[i])
			s[j] = c2[i];	
		}	
	}
	std::cout<<s<<"\n";
	return 0;	
}