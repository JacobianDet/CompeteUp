#include <bits/stdc++.h>

int arr[1001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int gcx = arr[0];
	for(int i=0;i<n;i++)
	(gcx > arr[i]) ? (gcx = arr[i]) : 1;
	bool ok = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] % gcx)
		{
			ok = 1;
			break;
		}
	}	
	if(ok)
	std::cout<<"-1\n";
	else
	{
		std::cout<<2*n-1<<"\n"<<arr[0]<<" ";
		for(int i=1;i<n;i++)
		std::cout<<gcx<<" "<<arr[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}