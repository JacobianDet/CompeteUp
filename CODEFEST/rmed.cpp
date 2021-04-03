#include <bits/stdc++.h>

typedef long long ll;

int arr[200001];

int bs1(int n, int val)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(arr[mid] <= val)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

int bs2(int n, int val)
{
	int lo = 0;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid] >= val)
		hi = mid - 1;
		else lo = mid;	
	}
	return lo;
}

int main(void)
{
	int n,s;
	std::cin>>n>>s;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	if(arr[(n>>1)] == s)
	std::cout<<"0\n";
	else if(arr[(n>>1)] > s)
	{
		ll ans = 0;
		int pos = bs1(n, s);
		for(int i=pos;i<=(n>>1);i++)
		ans += 1LL*(arr[i] - s);
		std::cout<<ans<<"\n";
	}	
	else
	{
		ll ans = 0;
		int pos = bs2(n, s);
		for(int i=pos;i>=(n>>1);i--)
		ans += 1LL*(s - arr[i]);
		std::cout<<ans<<"\n";
	}
	return 0;
}