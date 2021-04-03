#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int col[200001], next[200001], lcol[200001];
ll memo[200001];
int n;

ll BHUVT(int i)
{
	if(i == n+1)
	return 1;
	if(memo[i] != -1)
	return memo[i];
	ll ans = BHUVT(i+1)%MOD;
	if(next[i] && next[i] != i+1)
	ans = ((ans%MOD) + (BHUVT(next[i])%MOD))%MOD;
	memo[i] = ans;
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>col[i];
	for(int i=1;i<=n;i++)
	{
		if(lcol[col[i]])
		{
			next[lcol[col[i]]] = i;
			lcol[col[i]] = i;
		}	
		else lcol[col[i]] = i;
	}	
	ll ans = BHUVT(1)%MOD;
	std::cout<<ans<<"\n";
	return 0;
}