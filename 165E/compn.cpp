#include <bits/stdc++.h>

int arr[1000001], memo[(1<<22)];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
		memo[arr[i]] = arr[i];
	}	
	for(int p=0;p<22;p++)
	{
		for(int mask=0; mask<(1<<22); mask++)
		{
			if(mask & (1<<p))
			{	
				if((memo[mask ^ (1<<p)] != -1) && (memo[mask] == -1))
				memo[mask] = memo[mask ^ (1<<p)];
			}
		}	
	}	
	for(int i=0;i<n;i++)
	std::cout<<memo[(1<<22) - 1 - arr[i]]<<" ";
	std::cout<<"\n";
	return 0;
}