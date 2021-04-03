#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	if(n == 2)
	std::cout<<"0\n";
	else if(n == 3)
	{
		std::sort(arr, arr+n);
		if((arr[1] - arr[0]) < (arr[2] - arr[1]))
		std::cout<<(arr[1] - arr[0])<<"\n";
		else std::cout<<(arr[2] - arr[1])<<"\n";	
	}
	else
	{
		std::sort(arr, arr+n);
		if((arr[n-1] - arr[1]) < (arr[n-2] - arr[0]))
		std::cout<<(arr[n-1] - arr[1])<<"\n";
		else std::cout<<(arr[n-2] - arr[0])<<"\n";	
	}
	return 0;
}