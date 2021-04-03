#include <bits/stdc++.h>

int arr[100001];

bool cmpx(int x, int y)
{
	return (x > y);
}

int bs2(int n, int val)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid] >= val)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,k;
		std::cin>>n>>k;
		for(int i=1;i<=n;i++)
		std::cin>>arr[i];
		std::sort(arr+1, arr+n+1, cmpx);
		int pos = bs2(n, arr[k]);
		std::cout<<pos<<"\n";	
	}
	return 0;
}