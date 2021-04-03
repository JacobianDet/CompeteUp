#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define ll long long

char G[2000][2000];
ll hor[2000][2000], ver[2000][2000];
int n,m,k;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(G,'.',sizeof(G));
	std::cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	
			std::cin>>G[i][j];
			if(G[i][j] == '.')
			{
				if((i-1 >= 0) && (G[i-1][j] == '.'))
				ver[i][j] += ver[i-1][j];
				if((j-1 >= 0) && (G[i][j-1] == '.'))
				hor[i][j] += hor[i][j-1];
				ver[i][j]++;
				hor[i][j]++;	
			}	
		}		
	}
	ll ans = 0;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(k != 1)
			{	
				if(hor[i][j] >= k)
				ans++;
				if(ver[i][j] >= k)	
				ans++;
			}
			else 
			{
				if(hor[i][j] >= k)
				ans++;	
			}	
		}	
	}	
	std::cout<<ans<<"\n";
	return 0;
}