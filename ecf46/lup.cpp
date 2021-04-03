#include <bits/stdc++.h>

typedef long long ll;

ll ons[100002], ofs[100002], arr[100002];

int main(void)
{
	int n;
	ll m;
	std::cin>>n>>m;
	arr[0] = 0;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	arr[n+1] = m;	
	for(int i=1;i<=n+1;i++)
	{
		if(i & 1)
		{
			ons[i] = ons[i-1] + (arr[i] - arr[i-1]);
			ofs[i] = ofs[i-1];
		}	
		else
		{
			ons[i] = ons[i-1];
			ofs[i] = ofs[i-1] + (arr[i] - arr[i-1]);
		}
	}
	ll ans = ons[n+1];
	for(int i=1;i<=n;i++)
	{
		if(arr[i]-1 != 0)
		ans = std::max(ans, ons[i-1] + (arr[i]-1-arr[i-1]) + ofs[n+1] - ofs[i]);
		if(arr[i]+1 != m)
		ans = std::max(ans, ons[i] + (arr[i+1]-arr[i]-1) + ofs[n+1] - ofs[i+1]);	
	}	
	std::cout<<ans<<"\n";
	return 0;
}