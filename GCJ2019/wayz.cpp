#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n;
		std::cin>>n;
		std::string p;
		std::cin>>p;
		std::cout<<"Case #"<<t<<": ";
		for(int i=0;i<2*n-2;i++)
		{
			if(p[i] == 'S')
			std::cout<<'E';
			else std::cout<<'S';	
		}	
		std::cout<<"\n";
	}
	return 0;
}