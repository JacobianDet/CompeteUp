#include <bits/stdc++.h>

typedef long long ll;

ll A[11], B[11];
ll memo[11][2][4];

ll MPR(int i, bool zm, int mask)
{
	if(i == 10)
	return 1;
	if(memo[i][zm][mask] != -1)
	return memo[i][zm][mask];
	ll ans = 0;
	if(!mask)
	{
		for(int j=A[i];j<=B[i];j++)
		{
			if(j == A[i] && j == B[i])
			{	
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 0));	
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 0));
			}	
			else if(j == A[i])
			{	
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 1));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 1));
			}	
			else if(j == B[i])
			{	
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 2));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 2));
			}	
			else 
			{
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 3));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 3));
			}		
		}
	}
	else if(mask == 1)
	{
		for(int j=A[i];j<=9;j++)
		{
			if(j == A[i])
			{	
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 1));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 1));
			}	
			else 
			{
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 3));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 3));
			}	
		}
	}
	else if(mask == 2)
	{
		for(int j=0;j<=B[i];j++)
		{
			if(j == B[i])
			{	
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 2));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 2));
			}	
			else 
			{
				if(!zm && !j)
				ans = std::max(ans, MPR(i+1, 0, 3));
				else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 3));
			}	
		}
	}
	else
	{
		for(int j=0;j<=9;j++)
		{
			if(!zm && !j)
			ans = std::max(ans, MPR(i+1, 0, 3));
			else ans = std::max(ans, (1LL * j) * MPR(i+1, 1, 3));
		}		
	}	
	memo[i][zm][mask] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int n;
	std::cin>>n;
	A[9] = 1;
	int ct = 9;
	while(n)
	{
		B[ct] = n%10;
		n /= 10;
		ct--;
	}	
	ll ax = MPR(0, 0, 0);
	std::cout<<ax<<"\n";
	return 0;
}