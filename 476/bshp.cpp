#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::string rew[n];
	for(int i=0;i<n;i++)
	std::cin>>rew[i];
	int ctr[n][n];
	memset(ctr,0,sizeof(ctr));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(rew[i][j] == '.')
			{
				bool okc = 1;
				bool okr = 1;
				for(int m=0;m<k;m++)
				{
					int ni = i+m;
					if(ni == n || rew[ni][j] == '#')
					{	
						okc = 0;
						break;
					}		
				}
				for(int m=0;m<k;m++)
				{
					int nj = j+m;
					if(nj == n || rew[i][nj] == '#')
					{	
						okr = 0;
						break;
					}		
				}	
				if(okc)
				{
					for(int m=0;m<k;m++)
					ctr[i+m][j]++;	
				}	
				if(okr)
				{
					for(int m=0;m<k;m++)
					ctr[i][j+m]++;	
				}	
			}	
		}	
	}
	int r = 0;
	int c = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ctr[i][j] > ctr[r][c])
			{
				r = i;
				c = j;
			}	
		}	
	}	
	std::cout<<r+1<<" "<<c+1<<"\n";
	return 0;
}