#include <bits/stdc++.h>

typedef long long ll;

int arr[11][100001], nex[11][100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		std::cin>>arr[i][j];	
	}	
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		nex[i][arr[i][j-1]] = arr[i][j];
	}	
	ll ans = 0;
	ll c = 1;
	int xz = arr[1][1];
	for(int i=2;i<=n;i++)
	{
		bool ok = 1;
		for(int j=2;j<=m;j++)
		{
			if(nex[j][xz] != arr[1][i])
			{
				ok = 0;
				break;
			}	
		}	
		if(!ok)
		{
			ans += c*(c+1)/2;
			c = 0;
		}
		c++;	
		xz = arr[1][i];
	}	
	ans += c*(c+1)/2;
	std::cout<<ans<<"\n";
	return 0;
}