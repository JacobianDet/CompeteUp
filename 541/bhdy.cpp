#include <bits/stdc++.h>

int arr[105], ta[105];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	int px=0;	
	for(int i=0;i<n/2;i++)
	{
		ta[i] = arr[px];
		px++;
		ta[n-1-i] = arr[px];
		px++;
	}		
	if(n & 1)
	ta[n/2] = arr[px];	
	for(int i=0;i<n;i++)
	std::cout<<ta[i]<<" ";
	std::cout<<"\n";	
	return 0;	
}