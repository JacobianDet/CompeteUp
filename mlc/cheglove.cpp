#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int f[n+1],g[n+1];
		for(int i=1;i<=n;i++)
		std::cin>>f[i];
		for(int i=1;i<=n;i++)
		std::cin>>g[i];
		bool l = 1, b = 1;
		for(int i=1;i<=n;i++)
		{	
			l &= (f[i] <= g[i]);
			b &= (f[i] <= g[n-i+1]);
		}
		if(l & b)
		std::cout<<"both\n";
		else if(l)
		std::cout<<"front\n";
		else if(b)
		std::cout<<"back\n";
		else std::cout<<"none\n";	
	}	
	return 0;
}