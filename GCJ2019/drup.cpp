#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int w;
		std::cin>>w;
		int s1 = 0, s2 = 0;
		std::cout<<"1"<<std::endl;
		std::cin>>s1;
		std::cout<<"2"<<std::endl;
		std::cin>>s2;
		int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
		for(int i=0;i<=100;i++)
		{
			if((s2 - s1 - i) & 1)
			{
				r2 = i;
				r1 = (s2 - s1 - i)/2;
				if(!((s1 - r2 - 2*r1)%4))
				{
					r3 = (s1 - r2 - 2*r1)/4;
					r4 = (s1 - r2 - 2*r1)/4;
					r5 = (s1 - r2 - 2*r1)/4;
					r6 = (s1 - r2 - 2*r1)/4;
					break;
				}	
			}	
		}
		std::cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<" "<<r5<<" "<<r6<<std::endl;	
	}
	return 0;
}