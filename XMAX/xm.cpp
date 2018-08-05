#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

typedef long long ll;

ll arr[CHOR];
std::vector<ll> mat[65];
std::vector<ll> res;

int cntr(ll n)
{
	int cnt = 0;
	while(n)
	{
		cnt++;
		n >>= 1;
	}
	return cnt;	
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{	
		int n,k;
		std::cin>>n>>k;
		for(int i=0;i<n;i++)
		std::cin>>arr[i];
		for(int i=0;i<n;i++)
		mat[cntr(arr[i])].pb(arr[i]);
		for(int i=64;i>=0;i--)
		{
			if(!mat[i].empty())
			{
				res.pb(mat[i][0]);
				for(int j=1,m=(int)mat[i].size();j<m;j++)
				{
					mat[i][j] ^= mat[i][0];
					mat[cntr(mat[i][j])].pb(mat[i][j]);
				}
				mat[i].clear();	
			}	
		}
		ll ans = k;
		for(int i=0,j=(int)res.size();i<j;i++)
		{
			if(ans < (ans ^ res[i]))
			ans ^= res[i];
		}	
		std::cout<<ans<<"\n";
		res.clear();
	}	
	return 0;
}
