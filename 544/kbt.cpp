#include <bits/stdc++.h>

int arr[5001], gof[5001], memo[5001][5001];
int n, k;

int MR0X(int tx, int i)
{
	if(i == n)
	{
		if(!tx || (tx > k))
		return -20000000;
		else return 0;	
	}
	if(memo[tx][i] != -1)
	return memo[tx][i];
	int ans = -20000000;
	ans = std::max((gof[i] - i) + MR0X(tx + 1, gof[i]), MR0X(tx, i+1));
	memo[tx][i] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	for(int i=0;i<n;i++)
	gof[i] = (std::upper_bound(arr, arr+n, arr[i]+5) - arr);	
	int ans = MR0X(0, 0);
	std::cout<<ans<<"\n";
	return 0;
}	