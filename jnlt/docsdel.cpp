#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m;
		std::cin>>n>>m;
		ll arr[n+1][m+1], pref[n+1][m+1];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			std::cin>>arr[i][j];	
		}	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i == 1)
				pref[i][j] = arr[i][j];
				else pref[i][j] = arr[i][pref[i-1][j]];
			}	
		}
		int q;
		std::map<std::pair<int, int>, ll> mx; 
		std::cin>>q;
		while(q--)
		{
			int a,b;
			std::cin>>a>>b;
			if(mx[mp(a, b)] != 0)
			std::cout<<mx[mp(a, b)]<<"\n";
			else
			{
				ll sum = 0;
				if(a == 1)
				{
					for(int i=1;i<=m;i++)
					sum += (1LL*i*pref[b][i]);
				}	
				else
				{
					for(int i=1;i<=m;i++)
					sum += (1LL*pref[b][i]*pref[a-1][i]);	
				}	
				mx[mp(a, b)] = sum;
				std::cout<<sum<<"\n";
			}	
		}	
	}
	return 0;
}