#include <bits/stdc++.h>

std::string s[5205];
int G[5205][5205], pref[5205][5205];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n/4;j++)
		{
			if(s[i][j] == '0')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == '1')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == '2')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == '3')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == '4')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == '5')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == '6')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == '7')
			{
				G[i][4*j+1] = 0;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == '8')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == '9')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == 'A')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == 'B')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 0;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == 'C')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == 'D')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 0;
				G[i][4*j+4] = 1;
			}
			else if(s[i][j] == 'E')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 0;
			}
			else if(s[i][j] == 'F')
			{
				G[i][4*j+1] = 1;
				G[i][4*j+2] = 1;
				G[i][4*j+3] = 1;
				G[i][4*j+4] = 1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		pref[i][j] = pref[i][j-1] + G[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		pref[j][i] += pref[j-1][i];	
	}
	int ans = 1;
	for(int i=1;i*i<=n;i++)
	{
		if(!(n % i))
		{
			bool ok = 1;
			for(int j=1;j<=n;j+=i)
			{
				for(int k=1;k<=n;k+=i)
				{
					int sx = pref[j+i-1][k+i-1] - pref[j-1][k+i-1] - pref[j+i-1][k-1] + pref[j-1][k-1];
					if(!sx || sx == i*i)
					continue;
					else 
					{
						ok = 0;
						break;
					}	
				}
				if(!ok)
				break;	
			}
			if(ok)
			ans = std::max(ans, i);
			ok = 1;
			for(int j=1;j<=n;j+=n/i)
			{
				for(int k=1;k<=n;k+=n/i)
				{
					int sx = pref[j+n/i-1][k+n/i-1] - pref[j-1][k+n/i-1] - pref[j+n/i-1][k-1] + pref[j-1][k-1];
					if(!sx || sx == (n/i)*(n/i))
					continue;
					else 
					{
						ok = 0;
						break;
					}	
				}
				if(!ok)
				break;	
			}
			if(ok)
			ans = std::max(ans, n/i);	
		}
	}
	std::cout<<ans<<"\n";
	return 0;
}	