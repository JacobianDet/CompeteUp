#include <bits/stdc++.h>

int arr[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int ld = 0, rd = 0;
	for(int i=0;i<n;i++)
	{
		if(!arr[i])
		ld++;
		else rd++;	
	}	
	int px = -1;
	for(int i=0;i<n;i++)
	{
		if(!arr[i])
		ld--;
		else rd--;
		if(!ld || !rd)
		{
			px = i;
			break;
		}	
	}
	std::cout<<px+1<<"\n";
	return 0;
}