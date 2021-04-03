#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	ll mx = 10000000000;
	ll ans = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(mx > arr[i])
		mx = arr[i];
		else if(mx)
		mx--;
		else mx = 0;	
		ans += mx;
	}	
	std::cout<<ans<<"\n";
	return 0;
}