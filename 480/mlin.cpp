#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::string arr[4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		arr[i] += '.';	
	}	
	std::cout<<"YES\n";
	if(!(k & 1))
	{
		int ctr = k;
		int z = 1;
		while(ctr > 0 && z < 3)
		{	
			for(int i=n/2+1,j=n/2-1;((i<n-1) && (j>0) && (ctr > 0));i++,j--)
			{
				arr[z][i] = '#';
				arr[z][j] = '#';
				ctr -= 2;
			}
			z++;
		}		
		if(k == 2*(n-2))
		{	
			arr[1][n/2] = '#';
			arr[2][n/2] = '#';
		}	
		for(int i=0;i<4;i++)
		std::cout<<arr[i]<<"\n";
	}	
	else 
	{
		int ctr = k;
		int z = 1;
		arr[1][n/2] = '#';
		ctr--;
		while(ctr > 0 && z < 3)
		{
			for(int i=n/2+1,j=n/2-1;((i<n-1) && (j>0) && (ctr > 0));i++,j--)
			{
				arr[z][i] = '#';
				arr[z][j] = '#';
				ctr -= 2;
			}
			z++;
		}	
		for(int i=0;i<4;i++)
		std::cout<<arr[i]<<"\n";
	}	
	return 0;
}