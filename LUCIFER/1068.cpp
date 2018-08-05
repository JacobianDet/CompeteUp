#include <bits/stdc++.h>

int A[11], B[11];
int memo[11][300][300][(1<<2)];
int k;

int fax(int i, int nx, int sx, int mask)
{
	if(i == 11)
	{
		if(!nx && !sx)
		return 1;
		else return 0;	
	}
	if(memo[i][nx][sx][mask] != -1)
	return memo[i][nx][sx][mask];
	int ans = 0;
	if(!mask)
	{
		for(int j=A[i];j<=B[i];j++)
		{
			if(j > A[i] && j < B[i])
			ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, 3);	
			else if(j > A[i])
			ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, 2);
			else if(j < B[i])
			ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, 1);	
			else ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, mask);			
		}	
	}
	else if(mask == 1)
	{
		for(int j=A[i];j<=9;j++)
		{
			if(j > A[i])
			ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, 3);	
			else ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, mask);		
		}	
	}
	else if(mask == 2)
	{
		for(int j=0;j<=B[i];j++)
		{
			if(j < B[i])
			ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, 3);	
			else ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, mask);		
		}	
	}	
	else
	{
		for(int j=0;j<=9;j++)
		ans += fax(i+1, ((((10%k) * (nx%k))%k) + (j%k))%k, ((sx%k) + (j%k))%k, mask);		
	}	
	memo[i][nx][sx][mask] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(memo, -1, sizeof(memo));
		int a,b;
		std::cin>>a>>b>>k;
		std::cout<<"Case "<<t<<": ";
		if(k > 300)
		std::cout<<"0\n";
		else
		{
			int temp = a;
			int x = 10;
			while(temp)
			{
				A[x--] = (temp%10);
				temp /= 10;
			}
			x = 10;
			temp = b;
			while(temp)
			{
				B[x--] = (temp%10);
				temp /= 10;
			}
			int ans = fax(1, 0, 0, 0);
			std::cout<<ans<<"\n";
		}	
	}	
	return 0;
}