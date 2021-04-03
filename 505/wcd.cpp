#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::pair<ll, ll> arr[150001];
ll lcx[150001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		ll a, b;
		std::cin>>a>>b;
		arr[i] = mp(a, b);
		lcx[i] = (a * (b/std::__gcd(a, b)));
	}	
	if(n == 1)
	std::cout<<arr[0].first<<"\n";	
	else
	{
		ll lc = std::__gcd(lcx[0], lcx[1]);
		for(int i=2;i<n;i++)
		lc = std::__gcd(lc, lcx[i]);
		if(lc == 1)
		std::cout<<"-1\n";
		else
		{
			for(int i=0;i<n;i++)
			{
				ll a = arr[i].first;
				ll b = arr[i].second;
				if((a % lc) && (b % lc))
				lc = std::__gcd(lc, a);	
			}	
			std::cout<<lc<<"\n";
		}	
	}
	return 0;
}