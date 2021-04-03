#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	int n;
	ll d;
	std::cin>>n>>d;
	ll arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int ans = 2;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i] + d < arr[i+1] - d)
		ans += 2;
		else if(arr[i] + d == arr[i+1] - d)
		ans += 1;	
	}	
	std::cout<<ans<<"\n";
	return 0;
}