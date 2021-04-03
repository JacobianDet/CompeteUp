#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		ll k;
		std::cin>>n>>k;
		ll arr[n];
		ll sum = 0;
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
			sum += arr[i];
		}	
		int ctr = 0;
		for(int i=0;i<n;i++)
		{
			if(2*arr[i] + k > sum)
			ctr++;	
		}	
		std::cout<<ctr<<"\n";
	}	
	return 0;
}