#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	int col[n+1];
	memset(col,0,sizeof(col));
	int ctr = 5000;
	for(int i=0;i<m;i++)
	{
		int x;
		std::cin>>x;
		col[x]++;
	}
	/*for(int i=1;i<=n;i++)
	std::cout<<col[i]<<"\n";*/	
	for(int i=1;i<=n;i++)
	{
		if(col[i] < ctr)
		ctr = col[i];	
	}	
	std::cout<<ctr<<"\n";
	return 0;
}