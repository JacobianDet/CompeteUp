#include <bits/stdc++.h>

typedef long long ll;

ll arr[101];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,m,k;
		std::cin>>n>>m>>k;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		bool ok = 1;
		for(int i=0;i<n-1;i++)
		{
			if(arr[i] >= std::max(0LL, arr[i+1] - k))
			m += (arr[i] - std::max(0LL, arr[i+1] - k));
			else if(arr[i+1] >= arr[i] + k)
			{
				m -= (arr[i+1] - arr[i] - k);
				if(m < 0)
				{
					ok = 0;
					break;
				}	
			}	
		}
		if(ok)
		std::cout<<"YES\n";
		else std::cout<<"NO\n";	
	}
	return 0;
}	