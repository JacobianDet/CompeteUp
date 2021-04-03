#include <bits/stdc++.h>
#define mp std::make_pair

std::string w[301];
int memo[301][301];
int n;

int abbx(int i, int j)
{
	if(i == n+1 || j == n+1)
	return 0;
	if(memo[i][j] != -1)
	return memo[i][j];
	int ans = 0;
	if(w[i] == w[j])
	ans = 1 + abbx(i+1, j+1);
	memo[i][j] = ans;
	return ans;		
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	std::cin>>n;
	int tot = 0;
	for(int i=1;i<=n;i++)
	{
		std::cin>>w[i];
		tot += (int)w[i].size();
	}
	tot += (n-1);	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		memo[i][j] = abbx(i, j);	
	}
	int ans = tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int sl = 0, cnt = 1, sc = 0;
			for(int k=i;k<j;k++)
			sl += (int)w[k].size();
			sl += (j-i-1);
			sc = (j-i);
			int pos = j;
			while(pos <= n)
			{
				if(memo[i][pos] >= sc)
				{
					pos += sc;
					cnt++;
				}
				else pos++;
			}	
			if(cnt > 1)
			ans = std::min(ans, tot - sl*cnt + sc*cnt);
		}	
	}	
	std::cout<<ans<<"\n";
	return 0;
}