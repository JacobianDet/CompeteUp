#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

ll cs[100001];
std::pair<ll, ll> arr[100001];
std::vector<std::vector<std::vector<ll> > > memo;

bool cmpx(std::pair<ll, ll> A, std::pair<ll, ll> B)
{
	return(A.first < B.first);
}

/*ll RAF(ll n, ll k, bool x)
{
	if(!k && x)
	return 0;
	else if(!n)	
	return 1000000000000000;	
	if(vis[n][k][x])
	return memo[n][k][x];
	ll ans = 1000000000000000;
	if(!x)
	{	
		ans = std::min(ans, RAF(n-1, k, 0));
		ans = std::min(ans, cs[arr[n].second] + (1LL*TK - k) * (-1LL*arr[n].first) + 1LL*k * arr[n].first + RAF(n-1, k, 1));
		if(k)
		ans = std::min(ans, cs[arr[n].second] + arr[n].first + RAF(n-1, k-1, 0));
	}
	else 
	{
		ans = std::min(ans, RAF(n-1, k, 1));
		if(k)
		ans = std::min(ans, cs[arr[n].second] + (-1LL*arr[n].first) + RAF(n-1, k-1, 1));
	}
	vis[n][k][x] = 1;
	memo[n][k][x] = ans;
	return ans;	
}*/

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int k,n;
		std::cin>>k>>n;
		memo.resize(n+1);
		for(int i=0;i<=n;i++)
		memo[i].resize(k+1);	
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{	
				memo[i][j].resize(2);
				memo[i][j][0] = 10000000000000000;
				memo[i][j][1] = 10000000000000000;		
			}	
		}	
		for(int i=1;i<=n;i++)
		{
			ll x;
			std::cin>>x;
			arr[i] = mp(x, i);
		}
		std::sort(arr+1, arr+n+1, cmpx);
		for(int i=1;i<=n;i++)
		std::cin>>cs[i];	
		for(int i=0;i<=n;i++)
		memo[i][0][1] = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				for(int x=0;x<2;x++)
				{
					memo[i][j][x] = std::min(memo[i][j][x], memo[i-1][j][x]);
					if(!x)
					{
						memo[i][j][x] = std::min(memo[i][j][x], cs[arr[i].second] + (k - j) * (-arr[i].first) + j * (arr[i].first) + memo[i-1][j][1]);
						if(j)
						memo[i][j][x] = std::min(memo[i][j][x], cs[arr[i].second] + arr[i].first + memo[i-1][j-1][x]);	
					}	
					else if(j)
					memo[i][j][x] = std::min(memo[i][j][x], cs[arr[i].second] - arr[i].first + memo[i-1][j-1][x]);	
				}	
			}
		}	
		std::cout<<"Case #"<<t<<": "<<memo[n][k][0]<<"\n";
	}	
	return 0;
}