#include <bits/stdc++.h>

int a[101], b[101];
bool c[101][101];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,h;
	std::cin>>n>>m>>h;
	for(int i=0;i<m;i++)
	std::cin>>a[i];
	for(int i=0;i<n;i++)
	std::cin>>b[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		std::cin>>c[i][j];	
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i][j])
			std::cout<<std::min(a[j], b[i])<<" ";	
			else std::cout<<"0 ";
		}
		std::cout<<"\n";	
	}	
	return 0;
}