#include <bits/stdc++.h>

int R[2001][2001], C[2001][2001], r[2001], c[2001], rk[2001][2001], ck[2001][2001];
char G[2001][2001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n,k;
    std::cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	std::cin>>G[i][j];	
    }	
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		R[i][j] = R[i][j-1];
    		if(G[i][j] == 'W')
    		R[i][j]++;	
    	}	
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		C[j][i] = C[j-1][i];
    		if(G[j][i] == 'W')
    		C[j][i]++;	
    	}	
    }	
    for(int i=1;i<=n;i++)
    {
    	r[i] = r[i-1];
    	if(R[i][n] == n)
    	r[i]++;	
    }	
    for(int i=1;i<=n;i++)
    {
    	c[i] = c[i-1];
    	if(C[n][i] == n)
    	c[i]++;	
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j+k-1<=n;j++)
    	{
    		rk[i][j] = rk[i-1][j];
    		if(R[i][n] + R[i][j-1] - R[i][j+k-1] == n-k)
    		rk[i][j]++;	
    	}	
    }	
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j+k-1<=n;j++)
    	{
    		ck[j][i] = ck[j][i-1];
    		if(C[n][i] + C[j-1][i] - C[j+k-1][i] == n-k)
    		ck[j][i]++;	
    	}	
    }	
    int ans = 0;
    for(int i=1;i+k-1<=n;i++)
    {
    	for(int j=1;j+k-1<=n;j++)
    	{
    		int d = r[i-1] + r[n] - r[i+k-1] + c[j-1] + c[n] - c[j+k-1] + ck[i][j+k-1] - ck[i][j-1] + rk[i+k-1][j] - rk[i-1][j];
    		ans = std::max(ans, d);
    	}	
    }	
    std::cout<<ans<<"\n";
    return 0;
}