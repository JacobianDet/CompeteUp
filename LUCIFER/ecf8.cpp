#include <bits/stdc++.h>
#define MOD 1000000007

typedef long long ll;

int m,d,n;
int A[2001], B[2001];
ll memo[2001][2001][(1<<2)];

ll magic(int i, int num, int mask)
{
	if(i == n+1)
	{
		if(!num)
		return 1*1LL;
		else return 0*1LL;	
	}	
	if(memo[i][num][mask] != -1)
	return memo[i][num][mask];
	ll ans = 0;
	if(!mask)
	{
		if(i & 1)
		{
			for(int j=A[i];j<=B[i];j++)
			{
				if(j != d)
				{	
					if(j > A[i] && j < B[i])
					ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), 3)%MOD))%MOD;
					else if(j > A[i])
					ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), 2)%MOD))%MOD;
					else if(j < B[i])
					ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), 1)%MOD))%MOD;
					else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), mask)%MOD))%MOD;
				}		
			}	
		}
		else
		{
			if(d >= A[i] && d <= B[i])
			{	
				if(d > A[i] && d < B[i])
				ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), 3)%MOD))%MOD;
				else if(d > A[i])
				ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), 2)%MOD))%MOD;
				else if(d < B[i])
				ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), 1)%MOD))%MOD;
				else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), mask)%MOD))%MOD;	
			}	
		}	
	}	
	else if(mask == 1)
	{
		if(i & 1)
		{
			for(int j=A[i];j<=9;j++)
			{
				if(j != d)
				{
					if(j > A[i])
					ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), 3)%MOD))%MOD;
					else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), mask)%MOD))%MOD;	
				}	
			}	
		}
		else
		{
			if(d >= A[i])
			{	
				if(d > A[i])
				ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), 3)%MOD))%MOD;
				else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), mask)%MOD))%MOD;	
			}	
		}	
	}
	else if(mask == 2)
	{
		if(i & 1)
		{
			for(int j=0;j<=B[i];j++)
			{
				if(j != d)
				{
					if(j < B[i])
					ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), 3)%MOD))%MOD;
					else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), mask)%MOD))%MOD;	
				}	
			}	
		}
		else
		{
			if(d <= B[i])
			{	
				if(d < B[i])
				ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), 3)%MOD))%MOD;
				else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), mask)%MOD))%MOD;	
			}	
		}	
	}
	else
	{
		if(i & 1)
		{
			for(int j=0;j<=9;j++)
			{
				if(j != d)
				ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (j%m))%m), mask)%MOD))%MOD;
			}	
		}
		else ans = ((ans%MOD) + (magic(i+1, (((((10%m) * (num%m))%m) + (d%m))%m), mask)%MOD))%MOD;	
	}	
	memo[i][num][mask] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>m>>d;
	std::string a, b;
	std::cin>>a>>b;
	n = (int)a.size();
	for(int i=0;i<n;i++)
	A[i+1] = (a[i] - '0');	
	for(int i=0;i<n;i++)
	B[i+1] = (b[i] - '0');
	ll ans = magic(1, 0, 0);
	std::cout<<ans<<"\n";
	return 0;	
}