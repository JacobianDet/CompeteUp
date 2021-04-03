#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int ass[256];
	memset(ass, -1, sizeof(ass));
	for(int i=0;i<n;i++)
	{
		int t = -1;
		if(arr[i]-k+1 < 0)
		t = 0;
		else t = arr[i]-k+1;
		if(ass[arr[i]] != -1)
		std::cout<<ass[arr[i]]<<" ";
		else
		{	
			if(ass[t] == -1)
			{
				std::cout<<t<<" ";
				for(int j=t;j<=arr[i];j++)
				ass[j] = t;	
			}	
			else if(ass[t] != -1)
			{
				if(ass[t] == t)
				{
					std::cout<<t<<" ";
					for(int j=t;j<=arr[i];j++)
					ass[j] = t;	
				}
				else
				{
					int p = t;
					while(ass[p] == ass[t])
					p++;
					std::cout<<p<<" ";
					for(int j=p;j<=arr[i];j++)
					ass[j] = p;	
				}	
			}	
		}	
	}	
	std::cout<<"\n";
	return 0;
}