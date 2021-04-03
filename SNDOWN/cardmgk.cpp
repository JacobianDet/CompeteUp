#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		int ic = 0, pos = -1;
		for(int i=1;i<n;i++)
		{
			if(arr[i-1] > arr[i])
			{
				ic++;
				pos = i;
			}	
		}	
		if((ic > 1) || ((ic == 1) && (arr[n-1] > arr[0])))
		std::cout<<"NO\n";
		else std::cout<<"YES\n";
	}
	return 0;
}