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
		if(n & 1)
		std::cout<<"NO\n";
		else
		{
			bool ok = 1;
			for(int i=0;i<n/2;i++)
			{
				if(arr[i] != -1 && arr[(n>>1) + i] != -1)
				{
					if(arr[i] != arr[(n>>1) + i])
					{
						ok = 0;
						break;
					}	
				}	
				else if(arr[i] != -1 || arr[(n>>1) + i] != -1)
				{
					if(arr[i] == -1)
					arr[i] = arr[(n>>1) + i];
					else arr[(n>>1) + i] = arr[i];	
				}	
				else 
				{
					arr[i] = 1;
					arr[(n>>1) + i] = 1;
				}
			}
			if(ok)
			{
				std::cout<<"YES\n";
				for(int i=0;i<n;i++)
				std::cout<<arr[i]<<" ";
				std::cout<<"\n";	
			}	
			else std::cout<<"NO\n";
		}	
	}
	return 0;
}