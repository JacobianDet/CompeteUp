#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	if(arr[0])
	std::cout<<"1\n";
	else
	{
		int mx = 0;
		int pos = -1;
		for(int i=1;i<n;i++)
		{
			if(arr[i] > mx + 1)
			{
				pos = i + 1;
				break;
			}	
			else mx = std::max(mx, arr[i]);
		}
		std::cout<<pos<<"\n";
	}	
	return 0;
}
