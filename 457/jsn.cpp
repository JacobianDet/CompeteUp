#include <bits/stdc++.h>

int main(void)
{
	int x,hh,mm;
	std::cin>>x>>hh>>mm;
	if(hh%10 == 7 || mm%10 == 7)
	std::cout<<0<<"\n";
	else
	{
		int ctr = 0;
		while(1)
		{
			ctr++;
			if(mm >= 0 && mm-x < 0)
			{
				hh = (hh - 1 + 24)%24;
				mm = (mm - x + 60)%60;
			}	
			else mm = (mm - x + 60)%60;
			if(hh%10 == 7 || mm%10 == 7)
			{
				std::cout<<ctr<<"\n";
				break;
			}	
		}	
	}	
	return 0;
}