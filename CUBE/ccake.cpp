#include <bits/stdc++.h>

int pref[41][41][41];
std::string s[2];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(pref, 0, sizeof(pref));
		int n,p;
		std::cin>>n>>p;
		for(int i=0;i<2;i++)
		std::cin>>s[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				pref[i][j][k] = (s[0][n*n*(i-1)+n*(j-1)+(k-1)] == s[1][n*n*(i-1)+n*(j-1)+(k-1)]) ? 1 + pref[i][j][k-1] : pref[i][j][k-1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				pref[i][k][j] += pref[i][k-1][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				pref[k][i][j] += pref[k-1][i][j];	
			}
		}
		bool ok = 0;
		int cx = 0, sx = 0;
		for(int sz=n;sz>0;sz--)
		{
			for(int i=n;i-sz+1>0;i--)
			{
				for(int j=n;j-sz+1>0;j--)
				{
					for(int k=n;k-sz+1>0;k--)
					{
						int ct = pref[i][j][k] - pref[i][j-sz][k] - pref[i][j][k-sz] - pref[i-sz][j][k] + pref[i-sz][j-sz][k] + pref[i-sz][j][k-sz] + pref[i][j-sz][k-sz] - pref[i-sz][j-sz][k-sz];
						if(100 * ct >= p * sz * sz * sz)
						{
							cx++;
							sx = sz;
						}
					}
				}
			}
			if(cx)
			{
				ok = 1;
				break;
			}	
		}
		if(!ok)
		std::cout<<"-1\n";
		else std::cout<<sx<<" "<<cx<<"\n";	
	}
}