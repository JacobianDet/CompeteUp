#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		ll sum = 0;
		for(int i=0;i<n;i++)
		{	
			std::cin>>arr[i];
			sum += arr[i];
		}
		if(sum % n)
		std::cout<<n-1<<"\n";
		else std::cout<<n<<"\n";	
	}
	return 0;
}