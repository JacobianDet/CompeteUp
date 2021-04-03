#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	if(n <= 3)
	{
		for(int i=1;i<n;i++)
		std::cout<<1<<" ";
		std::cout<<n<<"\n";
	}
	else
	{
		int x = n;
		int nx = 0;
		while(x > 1)
		{
			int mx = 0;
			if(x & 1)
			mx = (x>>1) + 1;
			else mx = (x>>1);
			nx = (n/x);
			while(nx & (nx - 1))
			nx &= (nx - 1);
			for(int i=1;i<=mx;i++)
			std::cout<<nx<<" ";
			x >>= 1;	
		}
		for(int i=n;i>=nx;i--)
		{
			if(!(i % nx))
			{
				std::cout<<i<<"\n";
				break;
			}	
		}	
	}
	return 0;
}