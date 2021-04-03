#include <bits/stdc++.h>

std::string s1[2];
std::string s2[2];

int main(void)
{
	for(int i=0;i<2;i++)
	{	
		std::cin>>s1[i];
		s2[i] = s1[i];
	}	
	int n = (int)s1[0].size();
	int cx1 = 0, cx2 = 0;
	for(int i=0;i<n-1;i++)
	{
		int ctr = 0;
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(s1[j][i+k] == '0')
				ctr++;	
			}	
		}
		if(ctr == 3)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(s1[j][i+k] == '0')
					s1[j][i+k] = 'X';	
				}	
			}
			cx1++;
		}
		if(ctr == 4)
		{
			s1[0][i] = 'X';
			s1[1][i] = 'X';
			s1[1][i+1] = 'X';
			cx1++;
		}	
	}
	for(int i=n-1;i>0;i--)
	{
		int ctr = 0;
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(s2[j][i-k] == '0')
				ctr++;	
			}	
		}
		if(ctr == 3)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(s2[j][i-k] == '0')
					s2[j][i-k] = 'X';	
				}	
			}
			cx2++;
		}
		if(ctr == 4)
		{
			s2[0][i] = 'X';
			s2[1][i] = 'X';
			s2[1][i-1] = 'X';
			cx2++;
		}	
	}
	std::cout<<std::max(cx1, cx2)<<"\n";
	return 0;	
}