#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<ll> subax[100001];
ll trz[100001];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int x;
		ll y;
		std::cin>>x>>y;
		subax[x].pb(y);
	}	
	for(int i=1;i<=m;i++)
	std::sort(subax[i].rbegin(), subax[i].rend());
	for(int i=1;i<=m;i++)
	{
		ll ctr = 0;
		for(int j=0,k=(int)subax[i].size();j<k;j++)
		{
			ctr += subax[i][j];
			if(ctr < 0)
			break;
			trz[j] += ctr;	
		}	
	}	
	ll ans = 0;
	for(int i=0;i<n;i++)
	ans = std::max(ans, trz[i]);
	std::cout<<ans<<"\n";
	return 0;
}