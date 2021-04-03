#include <bits/stdc++.h>

int main(void)
{
	int w,h,u1,d1,u2,d2;
	std::cin>>w>>h>>u1>>d1>>u2>>d2;
	for(int i=h;i>0;i--)
	{
		w += i;
		if(d1 == i)
		w -= u1;
		else if(d2 == i)
		w -= u2;
		if(w < 0)
		w = 0;	
	}	
	std::cout<<w<<"\n";
	return 0;
}