#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	while(std::getline(std::cin, s))
	{	
		int a=0,b=0;
		for(int i=0,j=(int)s.size();i<j;i++)
		{
			if(i & 1)
			{
				if(s[i] == '1')
				b++;	
			}	
			else
			{
				if(s[i] == '1')
				a++;	
			}	
			if((i >= 9) && (i & 1))
			{
				if(a > b)
				{
					std::cout<<"TEAM-A "<<i+1<<"\n";
					break;
				}	
				else if(b > a)
				{
					std::cout<<"TEAM-B "<<i+1<<"\n";
					break;
				}	
			}
			else if(i < 9)
			{
				if(i & 1)
				{
					if(b-a == (5-(i-1)/2))
					{	
						std::cout<<"TEAM-B "<<i+1<<"\n";
						break;
					}	
					else if(a-b == (5-(i-1)/2))
					{
						std::cout<<"TEAM-A "<<i+1<<"\n";
						break;
					}	
				}	
				else
				{
					if(a-b == (6-i/2))
					{
						std::cout<<"TEAM-A "<<i+1<<"\n";
						break;
					}	
					else if(b-a == (5-i/2))
					{
						std::cout<<"TEAM-B "<<i+1<<"\n";
						break;
					}	
				}	
			}	
		}	
		if(a == b)
		std::cout<<"TIE\n";	
		s.clear();
	}
	return 0;
}