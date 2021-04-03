#include <bits/stdc++.h>

struct t3
{
	int a,b,c;
}arr[100001];

int n;
int memo[100001][3];

int VACA(int i, int ch)
{
	if(i == n)
	return 0;
	if(memo[i][ch] != -1)
	return memo[i][ch];
	int ans = 0;
	if(!i)
	{
		for(int j=0;j<3;j++)
		{
			if(j == 0)
			ans = std::max(ans, arr[i+1].a + VACA(i+1, j));
			else if(j == 1)
			ans = std::max(ans, arr[i+1].b + VACA(i+1, j));
			else if(j == 2)
			ans = std::max(ans, arr[i+1].c + VACA(i+1, j));	
		}	
	}	
	else
	{
		for(int j=0;j<3;j++)
		{
			if(j != ch)
			{	
				if(j == 0)
				ans = std::max(ans, arr[i+1].a + VACA(i+1, j));
				else if(j == 1)
				ans = std::max(ans, arr[i+1].b + VACA(i+1, j));
				else if(j == 2)
				ans = std::max(ans, arr[i+1].c + VACA(i+1, j));	
			}
		}	
	}
	memo[i][ch] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i].a>>arr[i].b>>arr[i].c;
	int ans = VACA(0, 0);	
	std::cout<<ans<<"\n";
	return 0;
}