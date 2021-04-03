#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];

bool cmpx(ll A, ll B)
{
	return (A > B);
}

int bs1(int n, ll m)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		ll sx = 0, df = 0;
		for(int i=1;i<=n;i++)
		{
			sx += std::max(0LL, arr[i] - df);
			if(!(i % mid))
			df++;	
		}	
		if(sx < m)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	ll m, sx = 0;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{	
		std::cin>>arr[i];
		sx += arr[i];
	}
	if(sx < m)
	std::cout<<"-1\n";
	else
	{
		std::sort(arr+1, arr+n+1, cmpx);
		int ans = bs1(n, m);
		std::cout<<ans<<"\n";
	}	
	return 0;
}