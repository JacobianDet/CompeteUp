#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

bool arr[21][21];
ll memo[21][(1<<21)];
int n;

ll MATCH(int i, int mask)
{
	if(i == n)
	return 1;
	if(memo[i][mask] != -1)
	return memo[i][mask];
	ll ans = 0;
	for(int j=0;j<n;j++)
	{
		if((!(mask & (1<<j))) && arr[i][j])
		ans = ((ans%MOD) + (MATCH(i+1, mask | (1<<j))%MOD))%MOD;
	}
	memo[i][mask] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		std::cin>>arr[i][j];	
	}
	ll ans = MATCH(0, 0)%MOD;
	std::cout<<ans<<"\n";
	return 0;
}