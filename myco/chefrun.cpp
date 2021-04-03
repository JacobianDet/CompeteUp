#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int x1,x2,x3,v1,v2;
		std::cin>>x1>>x2>>x3>>v1>>v2;
		double t1 = ((double)abs(x1-x3))/v1;
		double t2 = ((double)abs(x2-x3))/v2;
		if(t1 > t2)
		std::cout<<"Kefa\n";
		else if(t1 < t2)
		std::cout<<"Chef\n";
		else std::cout<<"Draw\n";	
	}	
	return 0;
}