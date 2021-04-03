#include <bits/stdc++.h>

int arr[100001];

int bs1(int val, int n)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(arr[mid] < val)
		lo = mid + 1;
		else hi = mid;	
	}
	if(arr[lo] == val)
	return lo;
	else return -1;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	while(q--)
	{
		int x;
		std::cin>>x;
		int pos = bs1(x, n);
		std::cout<<pos<<"\n";	
	}	
	return 0;
}