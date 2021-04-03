#include <bits/stdc++.h>

int arr[501];
int memo[501][501];

int zuma(int i, int j)
{
	if(i == j)
	return 1;
	else if(i > j)
	return 0;	
	if(memo[i][j] != -1)
	return memo[i][j];
	int ans = 1000000000;	
	for(int k=i+1;k<=j;k++)
	{
		if(arr[k] == arr[i])
		{	
			if(k == i+1)
			ans = std::min(ans, 1 + zuma(k+1, j));
			else ans = std::min(ans, zuma(i+1, k-1) + zuma(k+1, j));	
		}	
	}	
	ans = std::min(ans, 1 + zuma(i+1, j));
	memo[i][j] = ans;
	return ans;
}

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int ans = zuma(1, n);
	std::cout<<ans<<"\n";
	return 0;		
}