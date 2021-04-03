#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int sc[601];
	memset(sc, 0, sizeof(sc));
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		sc[t]++;
	}	
	int ctr = 0;
	for(int i=1;i<=600;i++)
	{
		if(sc[i])
		ctr++;	
	}	
	std::cout<<ctr<<"\n";
	return 0;
}