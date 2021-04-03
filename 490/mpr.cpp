#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int ctr = 0, pos = n-1;
	for(int i=0;i<n;i++)
	{
		if(arr[i] <= k)
		ctr++;
		else
		{
			pos = i; 
			break;	
		}	
	}	
	for(int i=n-1;i>pos;i--)
	{
		if(arr[i] <= k)
		ctr++;
		else break;	
	}	
	std::cout<<ctr<<"\n";
	return 0;
}