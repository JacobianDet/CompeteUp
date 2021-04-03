#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	for(int i=0;i<T;i++)
	{
		int n,m,c1=0,c2=0;
		std::cin>>n>>m;
		std::string s[n];
		for(int j=0;j<n;j++)
		std::cin>>s[j];
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				//RGR format & GRG format
				if(j & 1)
				{
					if(k & 1)
					{
						if(s[j][k] == 'R')
						c2 += 5;
						else c1 += 3;	
					}
					else
					{
						if(s[j][k] == 'R')
						c1 += 5;
						else c2 += 3;	
					}	

				}
				else
				{
					if(k & 1)
					{
						if(s[j][k] == 'R')
						c1 += 5;
						else c2 += 3;
					}	
					else 
					{
						if(s[j][k] == 'R')
						c2 += 5;
						else c1 += 3;
					}	
				}	
			}	
		}
		std::cout<<std::min(c1,c2)<<"\n";	
	}
	return 0;	
}