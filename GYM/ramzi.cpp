#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int pref[60], suff[60];
ll memo[60][60];

ll chorchor(int i, int j)
{
	if(i+1 == j)
	return 1;
	if(memo[i][j] != -1)
	return memo[i][j];
	ll ans = 1;
	for(int k=i+1;k<j;k++)
	{
		for(int l=j-1;l>k;l--)
		{
			if((pref[k] - pref[i]) == (suff[l] - suff[j]))
			ans = ((ans%MOD) + (chorchor(k, l)%MOD))%MOD;	
		}	
	}
	memo[i][j] = ans;
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
		memset(pref, 0, sizeof(pref));
		memset(suff, 0, sizeof(suff));
		memset(memo, -1, sizeof(memo));
		std::string s;
		std::cin>>s;
		int n = (int)s.size();
		for(int i=1;i<=n;i++)
		pref[i] = pref[i-1] + (s[i-1] - '0');
		for(int i=n;i>0;i--)
		suff[i] = suff[i+1] + (s[i-1] - '0');
		ll ans = chorchor(0, n+1)%MOD;	
		std::cout<<ans<<"\n";
	}
	return 0;
}