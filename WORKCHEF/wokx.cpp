#include <bits/stdc++.h>

typedef long long ll;

int vis[20][4][(1<<9)][2520];
ll memo[20][4][(1<<9)][2520];
int A[20], B[20];
int k;

ll digdpx(int i, int cm, int mask, int rem, int t)
{
	if(i == 20)
	{
		if(__builtin_popcount(mask) < k)
		return 0;
		else
		{
			int ct = 0;
			for(int j=0;j<9;j++)
			{
				if(mask & (1<<j))
				{
					if(!(rem % (j+1)))
					ct++;	
				}	
			}
			if(ct >= k)
			return 1;
			else return 0;
		}	
	}
	if(vis[i][cm][mask][rem] == t)
	return memo[i][cm][mask][rem];
	ll ans = 0;
	if(!cm)
	{
		for(int j=A[i];j<=B[i];j++)
		{
			if(j > A[i] && j < B[i])
			ans += digdpx(i+1, 3, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);
			else if(j > A[i])
			ans += digdpx(i+1, 2, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);
			else if(j < B[i])
			ans += digdpx(i+1, 1, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);
			else ans += digdpx(i+1, cm, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);	
		}	
	}
	else if(cm == 1)
	{
		for(int j=A[i];j<=9;j++)
		{	
			if(j > A[i])
			ans += digdpx(i+1, 3, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);	
			else ans += digdpx(i+1, cm, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);
		}	
	}	
	else if(cm == 2)
	{
		for(int j=0;j<=B[i];j++)
		{
			if(j < B[i])
			ans += digdpx(i+1, 3, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);
			else ans += digdpx(i+1, cm, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);	
		}	
	}
	else
	{
		for(int j=0;j<=9;j++)
		ans += digdpx(i+1, 3, (!j ? mask : (mask | (1<<(j-1)))), (((((rem%2520) * (10%2520))%2520) + (j%2520))%2520), t);	
	}	
	vis[i][cm][mask][rem] = t;
	memo[i][cm][mask][rem] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(vis, 0, sizeof(vis));
	memset(memo, -1, sizeof(memo));
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		ll a,b;
		std::cin>>a>>b>>k;
		for(int i=19;i>=0;i--)
		{
			A[i] = (a%10);
			B[i] = (b%10);
			a /= 10;
			b /= 10;
		}	
		ll ans = digdpx(0, 0, 0, 0, t);
		std::cout<<ans<<"\n";
	}
	return 0;
}