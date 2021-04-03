#include <bits/stdc++.h>
#define INF 1000000000000000002

typedef long long ll;

ll arr[100001];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k;
		std::cin>>n>>k;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		ll mv = -INF;
		int ind = -1;
		for(int i=0;i<n;i++)
		{
			if(arr[i] < 0)
			{
				if(-arr[i] > mv)
				{
					mv = -arr[i];
					ind = i;
				}	
			}
			else
			{
				if(arr[i] > mv)
				{
					mv = arr[i];
					ind = i;
				}	
			}
		}
		std::cout<<"1\n";
		std::cout<<arr[ind]<<"\n";
	}
	return 0;
}