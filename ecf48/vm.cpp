#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define CHOR 101

typedef long long ll;
typedef long double ld;
typedef double d;

int vmx[CHOR][CHOR];
int a[CHOR], b[CHOR];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	int rx = 0, cx = 0;
	for(int i=0;i<n;i++)
	{
		std::cin>>a[i];
		rx ^= a[i];
	}	
	for(int i=0;i<m;i++)
	{
		std::cin>>b[i];
		cx ^= b[i];
	}	
	if(rx != cx)
	std::cout<<"NO\n";
	else
	{
		for(int i=0;i<n-1;i++)
		vmx[i][m-1] = a[i];
		for(int i=0;i<m-1;i++)
		vmx[n-1][i] = b[i];
		vmx[n-1][m-1] = (rx ^ a[n-1]) ^ b[m-1];
		std::cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			std::cout<<vmx[i][j]<<" ";
			std::cout<<"\n";	
		}	
	}	
	return 0;
}