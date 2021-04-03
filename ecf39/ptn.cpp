#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int b=0, c=0;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		if(t >= 0)
		b += t;
		else c += t;	
	}	
	std::cout<<b-c<<"\n";
	return 0;
}