#include <bits/stdc++.h>

int a[100], b[100];

int main(void)
{
	int m,s;
	std::cin>>m>>s;
	if(m == 1 && !s)
	std::cout<<"0 0\n";
	else if(s < 1 || s > 9*m)
	std::cout<<"-1 -1\n";	
	else
	{
		int s1 = s, m1 = m, s2 = s, m2 = m;
		for(int i=0;i<m;i++)
		{
			for(int d=0;d<=9;d++)
			{
				if(!i && !d)
				continue;	
				else
				{
					if(((s1 - d) >= 0) && ((s1 - d) <= 9*(m1 - 1)))
					{	
						a[i] = d;
						m1--;
						s1 -= d;
						break;
					}		
				}	
			}
			for(int d=9;d>=0;d--)
			{
				if(!i && !d)
				continue;
				else
				{
					if(((s2 - d) >= 0) && ((s2 - d) <= 9*(m2 - 1)))
					{	
						b[i] = d;
						m2--;
						s2 -= d;
						break;
					}		
				}		
			}	
		}	
		for(int i=0;i<m;i++)
		std::cout<<a[i];
		std::cout<<" ";
		for(int i=0;i<m;i++)
		std::cout<<b[i];
		std::cout<<"\n";	
	}
	return 0;	
}