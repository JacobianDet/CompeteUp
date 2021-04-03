#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		ll ans = 0;
		for(int i=0;i*i*i*i<=n;i++)
		{
			for(int j=0;j*j*j<=(n-i*i*i*i);j++)
			{
				int z = n - i*i*i*i - j*j*j;
				if(z >= 0)
				ans += (sqrt(z) + 1);	
			}	
		}
		std::cout<<ans<<"\n";	
	}	
	return 0;
}