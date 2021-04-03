#include <bits/stdc++.h>

typedef long long ll;

int A[20], B[20];
ll memo[20][20][3];

ll DPX(int i, int ct, int mask)
{
	if(i == 20)
	{
		if(ct <= 3)
		return 1;	
		else return 0;
	}
	if(memo[i][ct][mask] != -1)
	return memo[i][ct][mask];	
	ll ans = 0;
	if(!mask)
	{
		for(int j=A[i];j<=B[i];j++)
		{
			if(j > A[i] && j < B[i])
			{	
				if(j > 0)
				ans += DPX(i+1, ct+1, 3);
				else ans += DPX(i+1, ct, 3);
			}
			else if(j > A[i])
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, 2);
				else ans += DPX(i+1, ct, 2);	
			}		
			else if(j < B[i])
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, 1);
				else ans += DPX(i+1, ct, 1);
			}
			else
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, mask);
				else ans += DPX(i+1, ct, mask);
			}
		}	
	}
	else if(mask == 1)
	{
		for(int j=A[i];j<=9;j++)
		{
			if(j > A[i])
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, 3);
				else ans += DPX(i+1, ct, 3);
			}	
			else
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, mask);
				else ans += DPX(i+1, ct, mask);
			}
		}	
	}
	else if(mask == 2)
	{
		for(int j=0;j<=B[i];j++)
		{
			if(j < B[i])
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, 3);
				else ans += DPX(i+1, ct, 3);
			}
			else
			{
				if(j > 0)
				ans += DPX(i+1, ct+1, mask);
				else ans += DPX(i+1, ct, mask);
			}	
		}	
	}
	else
	{
		for(int j=0;j<=9;j++)
		{
			if(j > 0)
			ans += DPX(i+1, ct+1, mask);
			else ans += DPX(i+1, ct, mask);
		}
	}
	memo[i][ct][mask] = ans;
	return ans;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		memset(memo, -1, sizeof(memo));
		ll a,b;
		std::cin>>a>>b;
		ll tmp = a;
		int x = 19;
		while(tmp)
		{
			A[x] = (tmp%10);
			tmp /= 10;
			x--;
		}
		tmp = b;
		x = 19;
		while(tmp)
		{
			B[x] = (tmp%10);
			tmp /= 10;
			x--;
		}
		ll ans = DPX(0, 0, 0);
		std::cout<<ans<<"\n";
	}
	return 0;
}