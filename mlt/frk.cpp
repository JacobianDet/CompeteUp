#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s[n];
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	int ctr = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0,k=(int)s[i].size();j<k-1;j++)
		{
			std::string sx = s[i].substr(j, 2);
			if((sx == "ch") || (sx == "he") || (sx == "ef"))
			{
				ctr++;
				break;
			}	
		}	
	}
	std::cout<<ctr<<"\n";
	return 0;	
}