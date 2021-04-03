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
		int n,k;
		std::cin>>n>>k;
		std::cout<<"Case #"<<t<<": ";
		if(n == 2 || k <= 3)
		{	
			std::cout<<"0\n";
			std::cout<<"1\n"<<"1 "<<n<<" "<<k<<"\n";
		}
		else
		{
			int mx = std::min(n, k);
			std::cout<<(((2*k - mx) * (mx - 1))/2) - k<<"\n"; 
			std::cout<<mx<<"\n";
			std::cout<<"1 "<<n<<" "<<k<<"\n";
			for(int i=1;i<mx-1;i++)
			std::cout<<i<<" "<<i+1<<" "<<k-i<<"\n";
			std::cout<<mx-1<<" "<<n<<" "<<k-mx+1<<"\n";
		}	
	}
	return 0;
}