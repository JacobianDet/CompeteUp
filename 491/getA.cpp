#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int arr[n];
	int tot = 0;
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
		tot += arr[i];
	}
	std::sort(arr, arr+n);
	int v = 0;
	if(n & 1)
	v = 4*n + n/2 +1;	
	else v = 4*n + n/2;
	int mc = 0;	
	for(int i=0;i<n;i++)
	{
		if(tot >= v)
		break;	
		if(arr[i] < 5)
		{	
			tot += (5 - arr[i]);
			mc++;
		}	 	
	}
	std::cout<<mc<<"\n";
	return 0;	
}