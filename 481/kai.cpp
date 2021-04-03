#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	int ctr = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'x')
		{
			int j=i+1;
			bool x = 0;
			for( ;j<n;j++)
			{
				if(s[j] != 'x')
				break;
				else
				{
					int k=j+1;
					for( ;k<n;k++)
					{
						if(s[k] != 'x')
						{	
							x = 1;
							break;
						}		
						else ctr++;	
					}
					j = k;
				}
				if(x)
				break;	
			}
			i = j;	
		}	
	}
	std::cout<<ctr<<"\n";
	return 0;	
}