#include <bits/stdc++.h>

int arr[5001];

int bs1(int n, int val)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(arr[mid] > val)
		hi = mid;
		else lo = mid + 1;	
	}
	if(arr[lo] <= val)
	return -1;
	else return lo;	
}

int bs2(int n, int k, int z)
{
	int lo = z;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(z + k - 1 >= mid)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,k;
		std::cin>>n>>k;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		std::sort(arr, arr+n);
		int ctx = 0;
		int z = 0;
		for(int i=0;i<n;i++)
		{
			int pos = bs1(n, i);
			if(pos == -1 || z > n-1)
			break;
			else
			{
				z = std::max(z, pos);
				int x = bs2(n, k, z);
				ctx += (x - z + 1);
				z = x + 1;
			}	
		}
		std::cout<<"Case #"<<t<<": "<<ctx<<"\n";	
	}
	return 0;
}