#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	int x[n+1];
	for(int i=0;i<n;i++)
	std::cin>>x[i];
	bool mark[10];
	memset(mark, 0, sizeof(mark));
	for(int i=0;i<m;i++)
	{
		int t;
		std::cin>>t;
		mark[t] = 1;
	}
	for(int i=0;i<n;i++)
	{
		if(mark[x[i]])
		std::cout<<x[i]<<" ";	
	}	
	std::cout<<"\n";
	return 0;
}