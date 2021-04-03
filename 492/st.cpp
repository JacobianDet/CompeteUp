#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int arr[2*n];
	for(int i=0;i<2*n;i++)
	std::cin>>arr[i];
	int swc = 0;
	for(int i=0;i<2*n;i+=2)
	{
		int pos = -1;
		for(int j=i+1;j<2*n;j++)
		{
			if(arr[j] == arr[i])
			{
				pos = j;
				break;
			}	
		}	
		for(int j=pos;j>i+1;j--)
		{
			swc++;
			std::swap(arr[j], arr[j-1]);
		}	
	}	
	std::cout<<swc<<"\n";
	return 0;
}