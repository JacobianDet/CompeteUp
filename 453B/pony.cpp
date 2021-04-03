#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define INF 1000000000000

typedef long long ll;

int pz[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int n,arr[100],bmk[61];
ll memo[100][1<<17];
std::pair<int, int> par[100][1<<17];
int soln[100][1<<17];

/*ll harmony(int s, int mask)
{
	if(s == n)
	return 0;
	if(memo[s][mask] != -1)
	return memo[s][mask];
	ll ans = INF;	
	for(int i=1;i<=60;i++)
	{
		if(!(mask & bmk[i]))
		{
			if(ans > abs(arr[s]-i) + harmony(s+1, (mask | bmk[i])))
			{	
				ans = std::min(ans, abs(arr[s]-i) + harmony(s+1, (mask | bmk[i])));
				par[s][mask] = mp(s+1, (mask | bmk[i]));
				soln[s][mask] = i;
			}	
		}	
	}	
	memo[s][mask] = ans;
	return ans;
}*/

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<(1<<17);j++)
		memo[i][j] = INF;	
	}	
	std::cin>>n;
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<(1<<17);j++)
		{	
			par[i][j] = mp(i, j);
			soln[i][j] = 0;
		}		
	}	
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=1;i<=60;i++)
	{
		for(int j=0;j<17;j++)
		{
			if(!(i % pz[j]))
			bmk[i] |= (1<<j);	
		}	
	}	
	//ll ans = harmony(0, 0);
	//std::cout<<soln[0][0]<<"\n";
	for(int j=0;j<(1<<17);j++)
	{
		for(int i=1;i<=60;i++)
		{
			if(!(j & bmk[i]))
			{	
				if(memo[n-1][j] > 1LL*abs(arr[n-1]-i))
				{	
					memo[n-1][j] = std::min(memo[n-1][j], 1LL*abs(arr[n-1]-i));
					soln[n-1][j] = i;
				}
			}			
		}	
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int mask=0;mask<(1<<17);mask++)
		{
			for(int j=1;j<=60;j++)
			{
				if(!(mask & bmk[j]))
				{
					if(memo[i][mask] > abs(arr[i]-j) + memo[i+1][mask | bmk[j]])
					{
						memo[i][mask] = abs(arr[i]-j) + memo[i+1][mask | bmk[j]];
						par[i][mask] = mp(i+1, (mask | bmk[j]));
						soln[i][mask] = j;
					}	
				}	
			}	
		}	
	}	
	int s = 0;
	int mask = 0;
	std::vector<int> sz;
	while(par[s][mask] != mp(s, mask))
	{
		std::pair<int, int> p = par[s][mask];
		sz.pb(soln[s][mask]);
		s = p.first;
		mask = p.second;
	}	
	sz.pb(soln[s][mask]);
	//std::cout<<ans<<"\n";
	for(int i=0,j=(int)sz.size();i<j;i++)
	std::cout<<sz[i]<<" ";
	std::cout<<"\n";	
	return 0;
}