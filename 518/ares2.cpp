#include <bits/stdc++.h>
#define MOD 998244353

typedef long long ll; 

int memo[100001][201][3];
int arr[100001];

/* 0 = <
   1 = =
   2 = >
*/   

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];	
	if(arr[1] != -1)
	memo[1][arr[1]][1] = 1;
	else
	{
		for(int i=1;i<=200;i++)
		memo[1][i][1] = 1;		
	}
	for(int i=1;i<=200;i++)
	{
		for(int j=0;j<3;j++)
		memo[1][i][j] = ((memo[1][i][j]%MOD) + (memo[1][i-1][j]%MOD))%MOD;	
	}		
	for(int i=2;i<=n;i++)
	{
		if(arr[i] != -1)
		{
			memo[i][arr[i]][0] = ((((memo[i-1][arr[i]-1][0]%MOD) + (memo[i-1][arr[i]-1][1]%MOD))%MOD) + (memo[i-1][arr[i]-1][2]%MOD))%MOD;
			memo[i][arr[i]][1] = ((((((memo[i-1][arr[i]][0]%MOD) - (memo[i-1][arr[i]-1][0]%MOD) + MOD)%MOD) + (((memo[i-1][arr[i]][1]%MOD) - (memo[i-1][arr[i]-1][1]%MOD) + MOD)%MOD))%MOD) + (((memo[i-1][arr[i]][2]%MOD) - (memo[i-1][arr[i]-1][2]%MOD) + MOD)%MOD))%MOD;
			if(i > 2)
			memo[i][arr[i]][2] = ((((memo[i-1][200][2]%MOD) - (memo[i-1][arr[i]][2]%MOD) + MOD)%MOD) + (((memo[i-1][200][1]%MOD) - (memo[i-1][arr[i]][1]%MOD) + MOD)%MOD))%MOD;
		}
		else
		{
			for(int j=1;j<=200;j++)
			{
				memo[i][j][0] = ((((memo[i-1][j-1][0]%MOD) + (memo[i-1][j-1][1]%MOD))%MOD) + (memo[i-1][j-1][2]%MOD))%MOD;
				memo[i][j][1] = ((((((memo[i-1][j][0]%MOD) - (memo[i-1][j-1][0]%MOD) + MOD)%MOD) + (((memo[i-1][j][1]%MOD) - (memo[i-1][j-1][1]%MOD) + MOD)%MOD))%MOD) + (((memo[i-1][j][2]%MOD) - (memo[i-1][j-1][2]%MOD) + MOD)%MOD))%MOD;
				if(i > 2)
				memo[i][j][2] = ((((memo[i-1][200][2]%MOD) - (memo[i-1][j][2]%MOD) + MOD)%MOD) + (((memo[i-1][200][1]%MOD) - (memo[i-1][j][1]%MOD) + MOD)%MOD))%MOD;
			}	
		}	
		for(int j=1;j<=200;j++)
		{
			for(int k=0;k<3;k++)
			memo[i][j][k] = ((memo[i][j][k]%MOD) + (memo[i][j-1][k]%MOD))%MOD;	
		}	
	}	
	ll ax = (arr[n] != -1) ? (((((memo[n][arr[n]][2]%MOD) - (memo[n][arr[n]-1][2]%MOD) + MOD)%MOD) + (((memo[n][arr[n]][1]%MOD) - (memo[n][arr[n]-1][1]%MOD) + MOD)%MOD))%MOD) : (((memo[n][200][1]%MOD) + (memo[n][200][2]%MOD))%MOD);
	std::cout<<ax<<"\n";
	return 0;
}