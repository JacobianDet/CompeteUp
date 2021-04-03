#include <bits/stdc++.h>

int main(void)
{
	int h1=0,a1=0,c1=0,h2=0,a2=0;
	std::cin>>h1>>a1>>c1>>h2>>a2;
	int h1o = h1;
	int h2o = h2;
	int ctr = 0;
	while(h2o > 0)
	{
		if(h2o <= a1)
		{
			h2o -= a1;
		}	
		else {
			if(h1o <= a2)
			{	
				h1o += c1;
			}	
			else {
				 h2o -= a1;
			}
		}		
		ctr++;
		h1o -= a2;	
	}	
	std::cout<<ctr<<"\n";
	while(h2 > 0)
	{
		if(h2 <= a1)
		{
			h2 -= a1;
			std::cout<<"STRIKE\n";
		}
		else {
			if(h1 <= a2)
			{	
				h1 += c1;
				std::cout<<"HEAL\n";
			}	
			else {
				 h2 -= a1;
			 	 std::cout<<"STRIKE\n";
			} 	 
		}	 
		h1 -= a2;	
	}
	return 0;	
}