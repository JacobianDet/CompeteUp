#include <bits/stdc++.h>
 
int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k,s;
		std::cin>>n>>k>>s;
		int req = k*s;
		int noc = (s - (s/7))*n;
		if(req <= noc)
		std::cout<<ceil((float)req/n)<<"\n";
		else std::cout<<"-1\n";
	}	
	return 0;
}