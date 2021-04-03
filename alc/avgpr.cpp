#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		ll arr[3001];
		memset(arr,0,sizeof(arr));
		for(ll i=0;i<n;i++)
		{
			ll t;
			std::cin>>t;
			arr[t+1000]++;
		}
		ll cnt = 0;
		for(ll i=0;i<=2000;i++)
		{
			if(arr[i])
			{
				for(ll j=i+1;j<=2000;j++)
				{
					if(arr[j])
					{	
						ll x = i-1000;
						ll y = j-1000;
						if(((x+y)%2 == 0) && arr[(x+y)/2 + 1000])
						cnt += arr[i]*arr[j];
					}
				}
				cnt += (arr[i]*(arr[i]-1))/2;	
			}	
		}
		std::cout<<cnt<<"\n";	
	}	
	return 0;	
}