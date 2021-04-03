#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr,arr+n);
	if(n & 1)
	std::cout<<arr[n/2]<<"\n";
	else std::cout<<arr[n/2 - 1]<<"\n";
	return 0;	
}