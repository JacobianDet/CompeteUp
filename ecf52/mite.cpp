#include <bits/stdc++.h>

int arr[200001];
int ctr[200001];

int bs1(int val, int n)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(arr[mid] >= val)
		hi = mid;
		else lo = mid + 1;	
	}
	return lo;
}

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	std::sort(arr+1, arr+n+1);
	for(int i=arr[1]+1;i<=arr[n];i++)
	{
		int pos = bs1(i, n);
		ctr[i] = (n - pos + 1);
	}	
	int tot = 0, mc = 0;
	for(int i=arr[n];i>arr[1];i--)
	{
		if(tot + ctr[i] <= k)
		tot += ctr[i];
		else
		{
			mc++;
			tot = ctr[i];
		}
	}	
	if(tot > 0)
	mc++;	
	std::cout<<mc<<"\n";
	return 0;
}