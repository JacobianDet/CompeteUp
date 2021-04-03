#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	int n,t;
	std::cin>>n>>t;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int p1 = 0, p2 = 0;
	int maxi = 0, cntx = 0;
	while(p2 < n)
	{
		while((p1 < p2) && (cntx > t))
		{
			cntx -= arr[p1];
			p1++;
		}	
		if(cntx <= t)
		{
			maxi = std::max(maxi, p2-p1);
			cntx += arr[p2];
			p2++;
		}	
	}	
	while(p1 < n)
	{
		if(cntx <= t)
		maxi = std::max(maxi, p2-p1);
		cntx -= arr[p1];
		p1++;	
	}	
	std::cout<<maxi<<"\n";
	return 0;
}