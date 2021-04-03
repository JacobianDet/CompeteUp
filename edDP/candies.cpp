#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

ll memo[101][100001];
int arr[101];

ll CANDY(int n, int k)
{
	if(k < 0)
	return 0;	
	else if(!n)
	{
		if(k == 0)
		return 1;
		else return 0;
	}
	if(memo[n][k] != -1)
	return memo[n][k];
	ll ans = 0;
	for(int j=0;j<=arr[n];j++)
	ans = ((ans%MOD) + (CANDY(n-1, k-j)%MOD))%MOD;
	memo[n][k] = ans;
	return ans;	
}

int main(void)
{
	memset(memo, -1, sizeof(memo));
	int n,k;
	std::cin>>n>>k;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	ll ans = CANDY(n, k)%MOD;	
	std::cout<<ans<<"\n";
	return 0;
}