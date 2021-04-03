#include <bits/stdc++.h>

int main(void)
{
	int arr[3];
	for(int i=0;i<3;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+3);
	if(arr[0] + arr[1] > arr[2])
	std::cout<<"0\n";
	else std::cout<<(arr[2] + 1 - arr[0] - arr[1])<<"\n";
	return 0;	
}