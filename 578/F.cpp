#include <bits/stdc++.h>
#define pb push_back
#define MOD 2520

typedef long long ll;

ll vf[1001], sz[1001];
bool sv[1001];
std::vector<int> G[1001];
int vis[1001][2521], memo[1001][2521];

int RK(int x, int y)
{
	if(vis[x][y] == 2)
	return memo[x][y];
	if(vis[x][y] == 1)
	{
		int ans = 0;
		int cx = x;
		int cy = y;
		while(1)
		{
			if(!sv[cx])
			ans++;	
			sv[cx] = 1;
			cy = (cy + vf[cx])%MOD;
			cy = (cy + MOD)%MOD;
			cx = G[cx][cy % sz[cx]];
			if(x == cx && y == cy) 
			break;	
		}
		memo[x][y] = ans;
		return ans;
	}	
	else
	{
		vis[x][y] = 1;
		int ny = (y + vf[x])%MOD;
		ny = (ny + MOD)%MOD;
		int ans = RK(G[x][ny % sz[x]], ny);
		vis[x][y] = 2;
		memo[x][y] = ans;
		return ans;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++)
    std::cin>>vf[i];	
    for(int i=1;i<=n;i++)
    {
    	std::cin>>sz[i];
    	for(int j=0;j<sz[i];j++)
    	{
    		int d;
    		std::cin>>d;
    		G[i].pb(d);
    	}	
    }
    for(int i=0;i<2520;i++)
    {
    	for(int j=1;j<=n;j++)
    	{	
    		memset(sv, 0, sizeof(sv));
    		memo[j][i] = RK(j, i);	
    	}	
    }
    int q;
    std::cin>>q;
    while(q--)
    {
    	int x;
    	ll y;
    	std::cin>>x>>y;
    	y %= MOD;
    	if(y < 0)
    	y += MOD;
    	else if(y >= MOD)
    	y -= MOD;
    	std::cout<<memo[x][y]<<"\n";	
    }
    return 0;
}