#include <bits/stdc++.h>

typedef long long ll;

int memo[2][201][6000];
int p2[201], p5[201];

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		ll t;
		std::cin>>t;
		int c2 = 0;
		while((t > 1) && !(t%2))
		{
			c2++;
			t /= 2;
		}	
		p2[i] = c2;
		int c5 = 0;
		while((t > 1) && !(t%5))
		{
			c5++;
			t /= 5;
		}	
		p5[i] = c5;
	}	
	for(int i=1;i<=n;i++)
	{
		memo[1][1][p5[i]] = std::max(p2[i], memo[0][1][p5[i]]);
		for(int j=2;j<=k;j++)
		{
			for(int p=0;p<6000;p++)
			{
				if(p-p5[i] >= 0 && memo[0][j-1][p-p5[i]] != -1)
				memo[1][j][p] = std::max(memo[0][j-1][p-p5[i]] + p2[i], memo[0][j][p]);	
			}	
		}
		for(int j=0;j<=k;j++)
		{
			for(int p=0;p<6000;p++)
			memo[0][j][p] = memo[1][j][p];	
		}	
	}	
	int ans = 0;
	for(int p=0;p<6000;p++)
	ans = std::max(ans, std::min(p, memo[0][k][p]));
	std::cout<<ans<<"\n";
	return 0;	
}