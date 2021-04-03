#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n, std::greater<ll>());
	if(arr[0] >= arr[1] + arr[2])
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		if(n & 1)
		{
			for(int i=n-1;i>=0;i-=2)
			std::cout<<arr[i]<<" ";
			for(int i=1;i<n;i+=2)
			std::cout<<arr[i]<<" ";
			std::cout<<"\n";	
		}	
		else
		{
			for(int i=n-2;i>=0;i-=2)
			std::cout<<arr[i]<<" ";
			for(int i=1;i<n;i+=2)
			std::cout<<arr[i]<<" ";
			std::cout<<"\n";
		}
	}
	return 0;
}	