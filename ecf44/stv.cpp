#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<ll> arr1, arr2;

ll bs2(ll val)
{
	ll lo = 0;
	ll hi = (ll)arr1.size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo + 1)/2;
		if(arr1[mid] > val)
		hi = mid - 1;
		else lo = mid;	
	}	
	if(!lo)
	return -1;
	else return lo;	
}

int main(void)
{
	ll n,k,l;
	std::cin>>n>>k>>l;
	ll m = n*k;
	for(ll i=0;i<m;i++)
	{
		ll t;
		std::cin>>t;
		arr1.pb(t);
		arr2.pb(t);
	}	
	std::sort(arr1.begin(), arr1.end());
	std::sort(arr2.begin(), arr2.end());
	std::vector<ll> vz1;
	ll y = arr1[0];
	bool ok = 1;
	for(ll i=1;i<n;i++)
	{
		ll x = bs2(l+y);
		if(x == -1)
		{
			ok = 0;
			break;
		}
		vz1.pb(arr1[x]);
		arr1.erase(arr1.begin()+x);
	}
	if(!ok)
    std::cout<<"0\n";
	else
	{ 
		std::vector<ll> vz2;
		for(int i=0;i<m;i++)
		{
			if(!(i % k))
			vz2.pb(arr2[i]);	
		}	
		vz1.pb(arr2[0]);
		std::sort(vz1.begin(), vz1.end());
		std::sort(vz2.begin(), vz2.end());
		ll vol = 0;
		for(int i=0;i<n;i++)
		vol += std::min(vz1[i], vz2[i]);
		std::cout<<vol<<"\n";
	}	
	return 0;	
}