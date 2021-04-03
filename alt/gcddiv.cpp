#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<ll> pz;
bool px[1000000];

void siever(void)
{
	memset(px,1,sizeof(px));
	px[0] = 0;
	px[1] = 0;
	for(ll p=2;p*p<=1000000;p++)
	{
		if(px[p])
		{
			for(ll i=p*p;i<=1000000;i+=p)
			px[i] = 0;	
		}	
	}
	for(ll p=2;p<=1000000;p++)
	{
		if(px[p])
		pz.pb(p);
	}
	return;		
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll n,k;
		std::cin>>n>>k;
		ll arr[n];
		for(ll i=0;i<n;i++)
		std::cin>>arr[i];
		if(n == 1)
		std::cout<<"YES\n";	
		else
		{	
			ll res = 0;
			for(ll i=0;i<n;i++)
			res = std::__gcd(res, arr[i]);
			bool ok = 1;
			for(ll i=0,j=(ll)pz.size();i<j;i++)
			{
				if(!(res % pz[i]))
				{
					if(pz[i] > k)
					{	
						ok = 0;
						break;
					}	
					else
					{
						while(!(res % pz[i]))
						res /= pz[i];	
					}	
				}	
			}
			if(res > k)
			ok = 0;	
			if(!ok)
			std::cout<<"NO\n";
			else std::cout<<"YES\n";
		}		
	}	
	return 0;	
}