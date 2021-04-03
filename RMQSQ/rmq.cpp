#include <bits/stdc++.h>
#define MV 100001

int arr[MV];
int dp[MV][20];

class ST
{
	public: void build(int n);
			int query(int l, int r);
};

void ST::build(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;(1<<j)<=n;j++)
		dp[i][j] = -1;	
	}	
	for(int i=1;i<=n;i++)
	dp[i][0] = arr[i];
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i + (1<<j) <= n+1)
			dp[i][j] = std::min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]); 	
		}	
	}
	return;	
}

int ST::query(int l, int r)
{
	int lx = 0;
	int ans = 1000000000;
	for(lx=1;(1<<lx)<=(r-l+1);lx++);
	lx--;
	for(int i=lx;i>=0;i--)
	{
		if((1<<i) <= (r-l+1))
		{
			ans = std::min(ans, dp[l][i]);
			l += (1<<i);
		}	
	}
	return ans;	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	ST T;
	T.build(n);
	int q;
	std::cin>>q;
	while(q--)
	{
		int l,r;
		std::cin>>l>>r;
		l++;
		r++;
		std::cout<<T.query(l, r)<<"\n";
	}	
	return 0;
}