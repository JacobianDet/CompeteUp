#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k,v;
		std::cin>>n>>k>>v;
		int sx = 0;
		for(int i=0;i<n;i++)
		{
			int t;
			std::cin>>t;
			sx += t;
		}	
		v *= (n + k);
		if(((v - sx) > 0) && !((v - sx) % k))
		std::cout<<(v - sx)/k<<"\n";
		else std::cout<<"-1\n"; 
	}
	return 0;
}