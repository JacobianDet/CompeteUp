#include <bits/stdc++.h>

int main(void)
{
	int n,c,rx=0;
	std::cin>>n>>c;
	int cx = 1000;
	for(rx=1;(rx*rx<=n);rx++);
	rx--;	
	int pos1 = -1, pos2 = -1;
	for(int i=rx;i<=n;i+=rx)
	{
		std::cout<<"1 "<<i<<std::endl;
		int ver = 0;
		std::cin>>ver;
		if(ver == 0)
		cx--;
		else if(ver == 1)
		{
			pos1 = i-rx+1;
			pos2 = i;
			std::cout<<"2"<<std::endl;
			cx -= (c+1);
			break;
		}
		if(i+rx < n)
		pos1 = i;	
	}
	if(pos2 == -1)
	{
		for(int i=pos1;i<=n;i++)
		{
			std::cout<<"1 "<<i<<std::endl;
			int ver = 0;
			std::cin>>ver;
			if(ver == 0)
			cx--;
			else if(ver == 1)
			{
				std::cout<<"3 "<<i<<std::endl;
				return 0;
			}	
		}
	}
	else
	{
		for(int i=pos1;i<=pos2;i++)
		{
			std::cout<<"1 "<<i<<std::endl;
			int ver = 0;
			std::cin>>ver;
			if(ver == 0)
			cx--;
			else if(ver == 1)
			{
				std::cout<<"3 "<<i<<std::endl;
				return 0;
			}	
		}
	}
	return 0;
}