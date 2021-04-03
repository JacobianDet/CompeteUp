#include <bits/stdc++.h>
#define CHOR 10000000

int main(void)
{
	int n,l,r,x;
	std::cin>>n>>l>>r>>x;
	int c[n];
	for(int i=0;i<n;i++)
	std::cin>>c[i];
	int ctr = 0; 
	for(int i=0;i<(1 << n);i++)
	{
		int maxx = 0;
		int minx = CHOR;
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			if(i & (1 << j))
			{
				maxx = std::max(maxx, c[j]);
				minx = std::min(minx, c[j]);
				sum += c[j];
			}	
		}
		if(sum >= l && sum <= r && (maxx - minx) >= x)
		ctr++;	
	}	
	std::cout<<ctr<<"\n";
	return 0;
}