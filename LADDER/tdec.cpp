#include <bits/stdc++.h>

//Solution Referred from -Morass-

typedef long long ll;

ll arr[3];

int main(void)
{
	for(int i=0;i<3;i++)
	std::cin>>arr[i];
	std::sort(arr, arr+3);
	arr[1] -= arr[0];
	arr[2] -= arr[0];
	if((arr[1] * 2) >= arr[2])
	std::cout<<(arr[0] + (arr[1] + arr[2])/3)<<"\n";
	else 
	{
		arr[2] -= 2*arr[1];
		std::cout<<(arr[0] + arr[1] + std::min(arr[0], arr[2]/3))<<"\n";
	}	
	return 0;	
}