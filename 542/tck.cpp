#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

std::vector<ll> arr[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=2*n;i++)
	{
		int t;
		std::cin>>t;
		arr[t].pb(1LL*i);
	}	
	ll ax = 0, p1 = 1, p2 = 1;
	for(int i=1;i<=n;i++)
	{
		if(abs(p1 - arr[i][0]) + abs(p2 - arr[i][1]) < abs(p1 - arr[i][1]) + abs(p2 - arr[i][0]))
		{
			ax += abs(p1 - arr[i][0]) + abs(p2 - arr[i][1]);
			p1 = arr[i][0];
			p2 = arr[i][1];
		}	
		else
		{
			ax += abs(p1 - arr[i][1]) + abs(p2 - arr[i][0]);
			p1 = arr[i][1];
			p2 = arr[i][0];
		}
	}	
	std::cout<<ax<<"\n";
	return 0;
}