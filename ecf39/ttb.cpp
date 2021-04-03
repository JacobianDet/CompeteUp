#include <bits/stdc++.h>
#define pb push_back
#define MAXX 10000000000000000

typedef long long ll;

std::string s[500];
std::vector<std::vector<ll> > vp(500);
ll cmin[501][501];
ll memo[501][501];
ll n;

ll minc(ll i, ll k)
{
	if(i == n-1)
	return cmin[i][k];
	if(memo[i][k] != -1)
	return memo[i][k];
	ll ans = MAXX;
	for(int t=0;t<=k;t++)
	ans = std::min(ans, cmin[i][t] + minc(i+1, k-t));
	memo[i][k] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo,-1,sizeof(memo));
	for(int i=0;i<501;i++)
	{
		for(int j=0;j<501;j++)
		cmin[i][j] = MAXX;	
	}
	ll m,k;
	std::cin>>n>>m>>k;
	for(ll i=0;i<n;i++)
	{
		std::cin>>s[i];
		for(ll j=0;j<m;j++)
		{
			if(s[i][j] == '1')
			vp[i].pb(j);	
		}	
	}
	for(int i=0;i<n;i++)
	{
		int l=0,r=(int)vp[i].size()-1;	
		for(int t=0;t<=k;t++)
		{
			if(!(r+1) || t >= r-l+1)
			cmin[i][t] = 0;	
			else
			{
				for(int j=0;j<=t;j++)
				cmin[i][t] = std::min(cmin[i][t], (vp[i][r-j] - vp[i][l+t-j] + 1));
				cmin[i][t] = std::min(cmin[i][t], (vp[i][r-t] - vp[i][l] + 1));
				cmin[i][t] = std::min(cmin[i][t], (vp[i][r] - vp[i][l+t] + 1));
			}	
		}	
	}	
	ll ans = minc(0, k);
	std::cout<<ans<<"\n";
	return 0;
}	