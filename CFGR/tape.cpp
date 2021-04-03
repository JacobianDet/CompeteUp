#include <bits/stdc++.h>

typedef long long ll;

ll arr[100001];

int main(void)
{
	int n,m,k;
	std::cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::multiset<ll> M;
	for(int i=1;i<n;i++)
	M.insert(arr[i] - arr[i-1]);
	ll ans = n, sz = n;	
	while(sz > k)
	{
		sz--;
		ans += (*M.begin() - 1);
		M.erase(M.begin());
	}
	std::cout<<ans<<"\n";
	return 0;
}