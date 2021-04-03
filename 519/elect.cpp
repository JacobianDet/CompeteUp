#include <bits/stdc++.h>

int arr[101];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int tot = 0, mx = 0;
	for(int i=0;i<n;i++)
	{	
		tot += arr[i];
		mx = std::max(mx, arr[i]);
	}	
	int ans = 0;
	if(2*tot % n)
	ans = (2*tot)/n + 1;
	else ans = (2*tot)/n;
	if(ans < mx)
	ans = mx;	
	if(ans*n <= 2*tot)
	ans++;	
	std::cout<<ans<<"\n";
	return 0;	
}