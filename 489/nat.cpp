#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int arr[200002];
	memset(arr, 0, sizeof(arr));
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		arr[t + 100001]++;
	}
	int ctr = 0;
	for(int i=0;i<200002;i++)
	{
		if((i != 100001) && arr[i])
		ctr++;	
	}
	std::cout<<ctr<<"\n";
	return 0;
}