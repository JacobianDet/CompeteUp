#include <bits/stdc++.h>

int arr[200001];

int loe(int n, int k)
{
	int lo = 1;
	int hi = 1000000000;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		int ctr = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i] <= mid)
			ctr++;	
		}	
		if(ctr < k)
		lo = mid + 1;
		else hi = mid;	
	}	
	int ctr = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] <= lo)
		ctr++;	
	}	
	if(ctr == k)
	return lo;
	else return -1;	
}

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int ans = loe(n,k);	
	std::cout<<ans<<"\n";
	return 0;
}