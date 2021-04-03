#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

std::string grid[3];

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
		for(int i=0;i<3;i++)
		std::cin>>grid[i];
		std::cout<<"Case #"<<t<<": ";
		if(n & 1)
		std::cout<<"0\n";
		else 
		{
			ll ans = 0;
			if(grid[0][0] == '#' || grid[1][0] == '#' || grid[1][n-1] == '#' || grid[2][n-1] == '#')
			ans = 0;	
			else ans = 1;
			if(ans)
			{	
				for(int i=1;i<n-1;i+=2)
				{
					ll sx = 0;
					if(grid[1][i] != '#' && grid[0][i] != '#' && grid[0][i+1] != '#' && grid[1][i+1] != '#')
					sx++;
					if(grid[1][i] != '#' && grid[2][i] != '#' && grid[2][i+1] != '#' && grid[1][i+1] != '#')
					sx++;
					ans = ((ans%MOD) * (sx%MOD))%MOD;	
				}
			}
			std::cout<<ans<<"\n";	
		}	
	}
	return 0;
}