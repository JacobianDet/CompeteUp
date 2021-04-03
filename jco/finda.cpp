#include <bits/stdc++.h>

int B[1000][1000];
int A[1000][1000];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			std::cin>>B[i][j];	
		}
		bool flag = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(i == j)
				{
					if(B[i][i] == -1)
					{
						flag = 1;
						break;
					}
				}	
				else
				{
					if(B[i][j] != B[j][i])
					{
						flag = 1;
						break;
					}	
				}
			}
			if(flag)
			break;	
		}
		if(flag)
		{
			std:;cout<<"-1\n";
			continue;
		}	
		

	}	
}