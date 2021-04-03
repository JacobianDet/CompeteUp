#include <bits/stdc++.h>

typedef long long ll;

std::pair<int, int> HW[3][2] =  {{{0, 1}, {2, 3}},
								{{0, 2}, {1, 3}},
							    {{0, 3}, {1, 2}}};


int main(void)
{
	int n;
	std::cin>>n;
	std::string s[4][n];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		std::cin>>s[i][j];	
	}	
	std::string soln[2][n];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!i)
			{	
				for(int k=0;k<n;k++)
				{		
					if((j+k) & 1)
					soln[i][j] += '1';
					else soln[i][j] += '0';
				}
			}
			else 
			{
				for(int k=0;k<n;k++)
				{		
					if((j+k) & 1)
					soln[i][j] += '0';
					else soln[i][j] += '1';
				}
			}			
		}	
	}
	/*for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		std::cout<<soln[i][j]<<"\n";
		std::cout<<"\n";	
	}*/	
	ll tv = 1000000;
	for(int i=0;i<3;i++)
	{
		int b_0 = HW[i][0].first;
		int b_1 = HW[i][0].second;
		int w_0 = HW[i][1].first;
		int w_1 = HW[i][1].second;
		ll cv1 = 0;
		ll cv2 = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[b_0][i][j] != soln[0][i][j])
				cv1++;
				if(s[b_1][i][j] != soln[0][i][j])
				cv1++;
				if(s[w_0][i][j] != soln[1][i][j])
				cv1++;
				if(s[w_1][i][j] != soln[1][i][j])
				cv1++;	
			}
			for(int j=0;j<n;j++)
			{
				if(s[b_0][i][j] != soln[1][i][j])
				cv2++;
				if(s[b_1][i][j] != soln[1][i][j])
				cv2++;
				if(s[w_0][i][j] != soln[0][i][j])
				cv2++;
				if(s[w_1][i][j] != soln[0][i][j])
				cv2++;	
			}		
		}	
		tv = std::min(tv, std::min(cv1, cv2));
	}
	std::cout<<tv<<"\n";
	return 0;	
}