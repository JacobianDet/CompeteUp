#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	int mva = 1;
	for(int i=0;i<n;i++)
	{
		if(mva <= arr[i])
		mva++;
	}	
	std::cout<<mva<<"\n";
	return 0;
}