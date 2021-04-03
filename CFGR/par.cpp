#include <bits/stdc++.h>

int arr[100001];

int main(void)
{
	int b,k;
	std::cin>>b>>k;
	for(int i=0;i<k;i++)
	std::cin>>arr[i];
	int bs = (b & 1);
	int obs = 0;
	for(int i=0;i<k-1;i++)
	{
		if((arr[i] & 1) && bs)
		obs ^= 1;
	}	
	if(arr[k-1] & 1)
	obs ^= 1;
	if(obs)
	std::cout<<"odd\n";
	else std::cout<<"even\n";
	return 0;	
}