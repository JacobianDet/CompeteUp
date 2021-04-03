#include <bits/stdc++.h>
#define ll long long

ll bins(ll z[], ll n, ll el)
{
	ll lo = 0;
	ll hi = n-1;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo+1)/2;
		if(z[mid] >= el)
		hi = mid-1;
		else lo = mid;	
	}	
	ll ans = z[lo];
	if(ans >= el)
	return -1;	
	else return ans;
}

int main(void)
{
	ll T;
	std::cin>>T;
	for(ll t=0;t<T;t++)
	{
		ll n;
		std::cin>>n;
		ll seq[n][n];
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			std::cin>>seq[i][j];
		}	
		for(ll i=0;i<n;i++)
		std::sort(seq[i], seq[i]+n);
		ll sel=seq[n-1][n-1],msum=seq[n-1][n-1];
		for(ll i=n-2;i>=0;i--)
		{
			ll a = bins(seq[i], n, sel);
			if(a == -1)
			{
				msum = -1;
				break;
			}	
			else
			{
				sel = a;
				msum += a;
			}	
		}
		std::cout<<msum<<"\n";
	}	
	return 0;
}