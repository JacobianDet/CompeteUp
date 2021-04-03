#include <bits/stdc++.h>
#define INF 1000001

/* 0 = ALPHA
   1 = DIGIT
   2 = SYMBOL*/

std::string s[51];
int mmov[51][3];
int memo[51][(1<<4)-1];
int n;

int AYE(int i, int mask)
{
	if(i == n)
	{
		if(__builtin_popcount(mask) != 3)
		return INF;
		else return 0;	
	}
	if(memo[i][mask] != -1)
	return memo[i][mask];
	int ans = 0;
	ans = std::min(mmov[i][0] + AYE(i+1, mask | (1<<0)), std::min(mmov[i][1] + AYE(i+1, mask | (1<<1)), mmov[i][2] + AYE(i+1, mask | (1<<2))));
	memo[i][mask] = ans;
	return ans;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	memset(memo, -1, sizeof(memo));
	int m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		mmov[i][j] = INF;	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(!j)
			{
				for(int k=0;k<m;k++)
				{
					if(s[i][k] >= 'a' && s[i][k] <= 'z')
					{
						mmov[i][j] = std::min(mmov[i][j], k);
						break;
					}	
				}	
				for(int k=m-1;k>=0;k--)
				{
					if(s[i][k] >= 'a' && s[i][k] <= 'z')
					{
						mmov[i][j] = std::min(mmov[i][j], m-k);
						break;
					}
				}
			}
			else if(j == 1)
			{
				for(int k=0;k<m;k++)
				{
					if(s[i][k] >= '0' && s[i][k] <= '9')
					{
						mmov[i][j] = std::min(mmov[i][j], k);
						break;
					}	
				}	
				for(int k=m-1;k>=0;k--)
				{
					if(s[i][k] >= '0' && s[i][k] <= '9')
					{
						mmov[i][j] = std::min(mmov[i][j], m-k);
						break;
					}
				}
			}
			else
			{
				for(int k=0;k<m;k++)
				{
					if(s[i][k] == '#' || s[i][k] == '*' || s[i][k] == '&')
					{
						mmov[i][j] = std::min(mmov[i][j], k);
						break;
					}	
				}	
				for(int k=m-1;k>=0;k--)
				{
					if(s[i][k] == '#' || s[i][k] == '*' || s[i][k] == '&')
					{
						mmov[i][j] = std::min(mmov[i][j], m-k);
						break;
					}
				}
			}
		}
	}
	int ans = AYE(0, 0);
	std::cout<<ans<<"\n";
	return 0;
}