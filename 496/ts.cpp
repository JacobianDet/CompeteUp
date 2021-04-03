#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::vector<int> Z;
	for(int i=1;i<n;i++)
	{
		if(arr[i] == 1)
		Z.pb(arr[i-1]);	
	}	
	Z.pb(arr[n-1]);
	std::cout<<(int)Z.size()<<"\n";
	for(int i=0,j=(int)Z.size();i<j;i++)
	std::cout<<Z[i]<<" ";
	std::cout<<"\n";
	return 0;	
}