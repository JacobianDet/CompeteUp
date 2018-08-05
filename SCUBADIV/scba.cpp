#include <bits/stdc++.h>

struct qry
{
	int ox,nt,wt;
}Q[1001];

int memo[1001][101][101];

int sd(int i, int a, int b)
{
	if(i < 0)
	{
		if(a > 0 || b > 0)
		return 100000000;
		else return 0;
	}	 
	if(a <= 0 && b <= 0)
	return 0;	
	if(memo[i][a][b] != -1)
	return memo[i][a][b];
	int ans = 100000000;
	ans = std::min(Q[i].wt + sd(i-1, ((a>=Q[i].ox) ? (a-Q[i].ox) : 0), ((b>=Q[i].nt) ? (b-Q[i].nt) : 0)), sd(i-1, a, b));	
	memo[i][a][b] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(memo,-1,sizeof(memo));
		int ov,nv;
		std::cin>>ov>>nv;
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>Q[i].ox>>Q[i].nt>>Q[i].wt;
		int ans = sd(n-1, ov, nv);
		std::cout<<ans<<"\n";	
	}	
	return 0;
}