#include <bits/stdc++.h>

int main(void)
{
	int n, cp=0,cn=0,c0=0;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		if(t > 0)
		cp++;
		else if(t == 0)
		c0++;
		else cn++;	
	}
	int cv = (n + 1)/2;
	if(cp >= cv)
	std::cout<<"1\n";
	else if(cn >= cv)
	std::cout<<"-1\n";
	else std::cout<<"0\n";
	return 0;	
}