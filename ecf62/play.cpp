#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::pair<ll, ll> arr[300001];

bool cmpx(std::pair<ll, ll> A, std::pair<ll, ll> B)
{
	return ((A.second > B.second) || ((A.second == B.second) && (A.first > B.first)));
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		ll t,b;
		std::cin>>t>>b;
		arr[i] = mp(t, b);
	}	
	std::sort(arr, arr+n, cmpx);
	ll sx = 0, ans = 0;
	if(n > k)
	{
		std::multiset<ll> Z;
		for(int i=0;i<k;i++)
		{
			sx += arr[i].first;
			Z.insert(arr[i].first);
			ans = std::max(ans, sx * arr[i].second);
		}
		for(int i=k;i<n;i++)
		{
			ll mx = *Z.begin();
			if(mx < arr[i].first)
			{
				Z.erase(Z.begin());
				sx -= mx;
				sx += arr[i].first;
				Z.insert(arr[i].first);
				ans = std::max(ans, sx * arr[i].second);
			}	
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			sx += arr[i].first;
			ans = std::max(ans, sx * arr[i].second);
		}
	}
	std::cout<<ans<<"\n";
	return 0;	
}