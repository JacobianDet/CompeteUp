#include <bits/stdc++.h>
#define pb push_back
 
typedef long long ll;
 
int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n,k;
		std::cin>>n>>k;
		ll arr[n];
		for(ll i=0;i<n;i++)
		std::cin>>arr[i];	
		ll ms = 0, ts = 0;
		std::vector<ll> tomu;
		std::vector<ll> amma;
		for(ll i=0;i<n;i++)
		{
			if(i & 1)
			{	
				tomu.pb(arr[i]);
				ts += arr[i];
			}	
			else ms += arr[i];
			amma.pb(arr[i]);	
		}
		if(ts > ms)
		{
			std::cout<<"YES\n";
			continue;
		}
		else if(n == 1)
		{
			std::cout<<"NO\n";
			continue;
		}	
		else
		{
			std::sort(amma.rbegin(), amma.rend());
			std::sort(tomu.rbegin(), tomu.rend());
			int ctr = 0;
			for(ll i=0,j=(ll)tomu.size();(i<j && ctr<k);i++)
			{
				ll x = *amma.begin();
				ll y = *tomu.begin();
				if(x == y)
				{
					amma.erase(amma.begin());
					tomu.erase(tomu.begin());
				}	
				else
				{
					ll z = *(tomu.begin() + ((ll)tomu.size() - 1));
					ts += (x - z);
					ms += (z - x);
					amma.erase(amma.begin());
					tomu.erase(tomu.begin() + ((ll)tomu.size() - 1));
					ctr++;
				}	
			}
			if(ts > ms)
			std::cout<<"YES\n";
			else std::cout<<"NO\n";	
		}
	}
	return 0;	
} 