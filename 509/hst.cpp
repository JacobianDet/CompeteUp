#include <bits/stdc++.h>

int arr[1001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	int diff = 0;
	for(int i=0;i<n-1;i++)
	diff += (arr[i+1] - arr[i] - 1);
	std::cout<<diff<<"\n";
	return 0;
}