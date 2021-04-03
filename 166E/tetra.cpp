#include <bits/stdc++.h>
#define MOD 1000000007

/*D = 0
  A = 1
  B = 2
  C = 3*/

int memo[4][10000001];

/*int path(int id, ll n)
{
	if(!id && !n)
	return 1;
	else if(!n)
	return 0;
	if(memo[id][n] != -1)
	return memo[id][n];	
	int ans = 0;
	for(int i=0;i<4;i++)
	{
		if(i != id)
		ans = (ans%MOD + path(i, n-1)%MOD)%MOD;	
	}	
	memo[id][n] = ans;
	return ans;
}*/

int main(void)
{
	memset(memo,0,sizeof(memo));
	int n;
	std::cin>>n;
	/*int ans = path(0, n)%MOD;
	std::cout<<ans<<"\n";*/
	for(int i=1;i<4;i++)
	memo[i][0] = 0;
	memo[0][0] = 1;
	for(int w=1;w<=n;w++)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(i != j)
				memo[i][w] = (memo[i][w]%MOD + memo[j][w-1]%MOD)%MOD;	
			}	
		}	
	}	
	std::cout<<memo[0][n]<<"\n";
	return 0;
}