#include <bits/stdc++.h>
#define MOD 1000000007

int memo[2][200001];

int bs2(int rx, int gx)
{
	int lo = 1;
	int hi = 10001;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if((mid * (mid + 1)) <= 2*(rx + gx))
		lo = mid;
		else hi = mid - 1;
	}
	return lo;
}	

/*int DEEPU(int ht, int r)
{
	if(!ht)
	return 1;
	if(memo[ht][r] != -1)
	return memo[ht][r];
	int ans = 0;
	if(r >= ht)
	ans = ((ans%MOD) + (DEEPU(ht - 1, r - ht)%MOD))%MOD;
	if(sx - ((th * (th + 1))>>1) + ((ht * (ht + 1))>>1) - r >= ht)
	ans = ((ans%MOD) + (DEEPU(ht - 1, r)%MOD))%MOD;
	memo[ht][r] = ans;
	return ans;
}*/	

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, 0, sizeof(memo));
	int r,g;
	std::cin>>r>>g;
	int ht = bs2(r, g);
	int sx = r + g;	
	for(int i=0;i<=r;i++)
	memo[0][i] = 1;
	for(int i=1;i<=ht;i++)
	{
		for(int j=0;j<=r;j++)
		{
			if(j >= i)
			memo[1][j] = ((memo[1][j]%MOD) + (memo[0][j-i]%MOD))%MOD;
			if(sx - ((ht * (ht + 1))>>1) + ((i * (i + 1))>>1) - j >= i)
			memo[1][j] = ((memo[1][j]%MOD) + (memo[0][j]%MOD))%MOD;
		}
		for(int j=0;j<=r;j++)
		{
			memo[0][j] = memo[1][j];
			memo[1][j] = 0;
		}
	}
	std::cout<<memo[0][r]<<"\n";	
	return 0;
}	
