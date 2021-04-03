#include <bits/stdc++.h>

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			std::cin>>arr[i][j];	
		}	
		int trc = 0;
		for(int i=0;i<n;i++)
		{
			int itrc = 0;
			for(int j=0;j<n-i;j++)
			itrc += arr[i+j][j];
			trc = std::max(trc, itrc);
		}	
		for(int j=0;j<n;j++)
		{
			int itrc = 0;
			for(int i=0;i<n-j;i++)
			itrc += arr[i][j+i];
			trc = std::max(trc, itrc);	
		}	
		std::cout<<trc<<"\n";
	}	
	return 0;
}