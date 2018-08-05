#include <bits/stdc++.h>
#define MOD 1000000000

typedef long long ll;

ll arr[12][12];
ll b[12], c[12];

void MATMUL(ll a[][12], ll b[][12], int k)
{
	ll ans[12][12];
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		ans[i][j] = 0;	
	}	
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int r=1;r<=k;r++)
			ans[i][j] = ((ans[i][j]%MOD) + (((a[i][r]%MOD) * (b[r][j]%MOD))%MOD))%MOD;	
		}	
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		a[i][j] = ans[i][j];	
	}	
	return;
}

void modexp(ll n, int k)
{
	ll res[12][12];
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		res[i][j] = 0;	
	}	
	for(int i=1;i<=k;i++)
	res[i][i] = 1;	
	while(n)
	{
		if(n & 1)
		MATMUL(res, arr, k);
		MATMUL(arr, arr, k);
		n >>= 1;	
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		arr[i][j] = res[i][j];	
	}	
	return;
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
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int k;
		std::cin>>k;
		for(int i=1;i<=k;i++)
		std::cin>>b[i];
		for(int i=1;i<=k;i++)
		std::cin>>c[i];
		ll n;
		std::cin>>n;
		if(n <= k)
		std::cout<<(b[n]%MOD)<<"\n";
		else
		{
			memset(arr, 0, sizeof(arr));
			for(int i=1;i<=k;i++)
			arr[1][i] = c[i];
			for(int i=2;i<=k;i++)
			arr[i][i-1] = 1;
			arr[k+1][k+1] = 1;
			b[0] = 1;
			modexp(n-k, k+1);
			ll ans = 0;
			for(int i=1;i<=k+1;i++)
			ans = ((ans%MOD) + (((arr[1][i]%MOD) * (b[k+1-i]%MOD))%MOD))%MOD;
			std::cout<<ans<<"\n";
		}	
	}	
	return 0;
}