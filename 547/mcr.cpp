#include <bits/stdc++.h>

int arr[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int mcx = 0, icx = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i])
		icx++;
		else icx = 0;
		mcx = std::max(mcx, icx);
	}	
	int pcx = 0, scx = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i])
		pcx++;
		else break;	
	}	
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i])
		scx++;
		else break;	
	}
	mcx = std::max(mcx, pcx + scx);
	std::cout<<mcx<<"\n";
	return 0;
}