#include <bits/stdc++.h>
#define CHOR 2002
#define LIKE 1000000007

int R[CHOR], U[CHOR], L[CHOR], cord[CHOR];
int a;
int memo[CHOR][CHOR];

int RU(int n, int i)
{
	if(n == a)
	return 0;
	if(memo[n][i] != -1)
	return memo[n][i];
	int ans = 0;
	if(!R[n] || (R[n] != R[n+1]))
	{
		if(!U[n])
		ans = std::min(L[i] + RU(n+1, i), RU(n+1, 0));
		else ans = std::min(L[i] + RU(n+1, i), std::min(L[cord[n]] + RU(n+1, cord[n]), RU(n+1, 0)));
	}	
	else
	{
		if(!U[n])
		{
			if(!i)
			ans = LIKE;
			else ans = L[i] + RU(n+1, i);	
		}
		else
		{
			if(!i)
			ans = L[cord[n]] + RU(n+1, cord[n]);
			else ans = std::min(L[i] + RU(n+1, i), L[cord[n]] + RU(n+1, cord[n]));		
		}	
	}
	if(ans > LIKE)
	ans = LIKE;	
	memo[n][i] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n,m;
	std::cin>>a>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		std::cin>>l>>r;
		for(int j=l;j<=r;j++)
		R[j] = i;	
	}
	for(int i=1;i<=m;i++)
	{
		int x,p;
		std::cin>>x>>p;
		if(!cord[x] || (U[x] > p))
		{	
			U[x] = p;
			L[i] = p;
			cord[x] = i;
		}	
	}	
	int ans = RU(0, 0);
	if(ans == LIKE)
	std::cout<<"-1\n";
	else std::cout<<ans<<"\n";
	return 0;	
}