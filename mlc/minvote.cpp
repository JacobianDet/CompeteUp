#include <bits/stdc++.h>
#define CHOR 100100

typedef long long ll;

ll pref1[CHOR], pref2[CHOR], arr[CHOR], ans[CHOR];

void binc(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		ll lo = i+1;
		ll hi = n;
		while(lo < hi)
		{
			ll mid = lo + (hi-lo+1)/2;
			if(pref1[mid-1] - pref1[i] > arr[i])
			hi = mid-1;
			else lo = mid;	
		}
		ans[i+1] += 1;
		ans[lo+1] -= 1;	
		lo = n-i+2;
		hi = n;
		while(lo < hi)
		{
			ll mid = lo + (hi-lo+1)/2;
			if(pref2[mid-1] - pref2[n-i+1] > arr[i])
			hi = mid-1;
			else lo = mid;	
		}	
		ans[n-lo+1] += 1;
		ans[i] -= 1;
	}	
	return;
}

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		memset(pref1,0,sizeof(pref1));
		memset(pref2,0,sizeof(pref2));
		memset(ans,0,sizeof(ans));
		memset(arr,0,sizeof(arr));
		ll n;
		std::cin>>n;
		for(ll i=1;i<=n;i++)
		{
			std::cin>>arr[i];
			pref1[i] = pref1[i-1] + arr[i];
		}	
		for(ll i=n;i>=1;i--)
		pref2[n-i+1] = pref2[n-i] + arr[i];	
		binc(n);
		for(ll i=1;i<=n;i++)
		ans[i] += ans[i-1];
		for(ll i=1;i<=n;i++)
		std::cout<<ans[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}