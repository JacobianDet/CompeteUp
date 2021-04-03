#include <bits/stdc++.h>
#define ll long long
#define CHOR 1000000007

ll memo[2][101];

//Top-Down
/*ll ktree(int k, int d, int n)
{
	if(n == 0)
	return 1;
	else if(n < 0)
	return 0;	
	if(d && memo[1][n] != -1)
	return memo[1][n];	
	else if(!d && memo[0][n] != -1)
	return memo[0][n];	
	ll st = 0;
	for(int i=1;i<=k;i++)
	{
		if(i < d && n > d)
		st = (st%CHOR + ktree(k,d,n-i)%CHOR)%CHOR;
		else if(i >= d)
		st = (st%CHOR + ktree(k,0,n-i)%CHOR)%CHOR;	
		else continue;	
	}
	if(d)
	memo[1][n] = st;
	else memo[0][n] = st;	
	return st;	
}*/

int main(void)
{
	memset(memo,-1,sizeof(memo));
	int n,k,d;
	std::cin>>n>>k>>d;
	//ll ans = ktree(k,d,n);
	memo[0][0] = 1;
	memo[1][0] = -1;
	//Bottom-Up
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i+j <= n)
			{	
				if(n-i > d && j < d)
				memo[0][i+j] = (std::max((ll)0,memo[0][i+j])%CHOR + memo[0][i]%CHOR)%CHOR;	
				else if(j >= d && memo[0][i] != -1)
				memo[1][i+j] = (std::max((ll)0,memo[1][i+j])%CHOR + memo[0][i]%CHOR)%CHOR;
				if(memo[1][i] != -1)
				memo[1][i+j] = (std::max((ll)0,memo[1][i+j])%CHOR + memo[1][i]%CHOR)%CHOR;	
			}
		}
	}		
	if(memo[1][n] == -1)
	memo[1][n] = 0;	
	std::cout<<memo[1][n]<<"\n";
	return 0;
}