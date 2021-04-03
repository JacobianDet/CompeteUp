#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+n);
	ll vx = 0;
	for(int i=0;i<n;i++)
	{
		if(std::upper_bound(arr, arr+n, arr[i]+5) != arr+n)
		vx = std::max(vx, 1LL*(std::upper_bound(arr, arr+n, arr[i]+5) - (arr+i)));
		else vx = std::max(vx, 1LL*n-i);
	}	
	std::cout<<vx<<"\n";
	return 0;
}