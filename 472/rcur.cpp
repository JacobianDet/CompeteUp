#include <bits/stdc++.h>

typedef long long ll;

int arr[100001], az[100001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	int cur = 0;
	for(int i=1;i<=n;i++)
	{
		cur = std::max(az[i-1], arr[i] + 1);
		az[i] = cur;
	}	
	cur = 0;
	for(int i=n-1;i>0;i--)
	{
		cur = std::max(az[i], std::max(az[i+1]-1, arr[i] + 1));
		az[i] = cur;
 	}
 	ll ans = 0;
 	for(int i=1;i<=n;i++)
 	ans += ((ll)az[i] - arr[i] - 1);
 	std::cout<<ans<<"\n";
 	return 0;
}