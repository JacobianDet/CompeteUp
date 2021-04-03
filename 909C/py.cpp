#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long

int n;
std::string ins;
ll memo[5001][5001];

ll pyind(int i, int k)
{
	if(i == n-1)
	return 1;
	if(memo[i][k] != -1)
	return memo[i][k];	
	ll ans = 0;
	if(ins[i] == 's')
	{
		if(!k)
		ans = pyind(i+1, k)%MOD;	
		else ans = (pyind(i+1, k)%MOD + pyind(i, k-1)%MOD)%MOD;
	}	
	else if(ins[i] == 'f')
	ans = pyind(i+1, k+1)%MOD;	
	memo[i][k] = ans;
	return ans;
}

int main(void)
{
	memset(memo,-1,sizeof(memo));
	std::cin>>n;
	char t;
	for(int i=0;i<n;i++)
	{
		std::cin>>t;
		ins += t;
	}
	ll ans = pyind(0, 0);
	std::cout<<ans<<"\n";
	return 0;
}