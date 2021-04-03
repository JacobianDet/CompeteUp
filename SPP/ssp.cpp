#include <bits/stdc++.h>

typedef long long ll;

ll arr[20][20];
ll b[20], c[20];

void MATMUL(ll a[][20], ll b[][20], int k, ll p)
{
	ll ans[20][20];
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
			ans[i][j] = ((ans[i][j]%p) + (((a[i][r]%p) * (b[r][j]%p))%p))%p;	
		}	
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		a[i][j] = ans[i][j];	
	}	
	return;
}

void modexp(ll n, int k, ll p)
{
	ll res[20][20];
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
		MATMUL(res, arr, k, p);
		MATMUL(arr, arr, k, p);
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
		memset(arr, 0, sizeof(arr));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int k;
		std::cin>>k;
		ll bsum = 0;
		for(int i=1;i<=k;i++)
		std::cin>>b[i];
		for(int i=1;i<=k;i++)
		std::cin>>c[i];
		ll m,n,p;
		std::cin>>m>>n>>p;
		for(int i=1;i<=k;i++)
		bsum = ((bsum%p) + (b[i]%p))%p;
		ll ans = 0;
		if(m <= k && n <= k)
		{
			for(ll i=m;i<=n;i++)
			ans = ((ans%p) + (b[i]%p))%p;
			std::cout<<ans<<"\n";	
		}	
		else if(m <= k && n > k)
		{
			for(ll i=m;i<=k;i++)
			ans = ((ans%p) + (b[i]%p))%p;
			arr[1][1] = 1;
			for(int i=2;i<=k+1;i++)
			{	
				arr[1][i] = c[i-1];
				arr[2][i] = c[i-1];
			}		
			for(int i=3;i<=k+1;i++)
			arr[i][i-1] = 1;
			arr[k+2][k+2] = 1;
			b[0] = 1;
			modexp(n-k, k+2, p);
			ans = ((ans%p) + (((arr[1][1]%p) * (bsum%p))%p))%p;
			for(int i=2;i<=k+2;i++)
			ans = ((ans%p) + (((arr[1][i]%p) * (b[k+2-i]%p))%p))%p;
			ans = ((ans%p) - (bsum%p) + p)%p;
			std::cout<<ans<<"\n";	
		}	
		else
		{
			arr[1][1] = 1;
			for(int i=2;i<=k+1;i++)
			{	
				arr[1][i] = c[i-1];
				arr[2][i] = c[i-1];
			}		
			for(int i=3;i<=k+1;i++)
			arr[i][i-1] = 1;
			arr[k+2][k+2] = 1;
			b[0] = 1;
			modexp(n-k, k+2, p);
			ans = ((ans%p) + (((arr[1][1]%p) * (bsum%p))%p))%p;
			for(int i=2;i<=k+2;i++)
			ans = ((ans%p) + (((arr[1][i]%p) * (b[k+2-i]%p))%p))%p;
			if(m > k+1)
			{	
				memset(arr, 0, sizeof(arr));
				arr[1][1] = 1;
				for(int i=2;i<=k+1;i++)
				{	
					arr[1][i] = c[i-1];
					arr[2][i] = c[i-1];
				}		
				for(int i=3;i<=k+1;i++)
				arr[i][i-1] = 1;
				arr[k+2][k+2] = 1;
				b[0] = 1;
				modexp(m-k-1, k+2, p);
				ans = ((ans%p) - (((arr[1][1]%p) * (bsum%p))%p) + p)%p;
				for(int i=2;i<=k+2;i++)
				ans = ((ans%p) - (((arr[1][i]%p) * (b[k+2-i]%p))%p) + p)%p;
			}
			else ans = ((ans%p) - (bsum%p) + p)%p;	
			std::cout<<ans<<"\n";
		}	
	}
	return 0;
}