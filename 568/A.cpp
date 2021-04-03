#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int arr[3];
	for(int i=0;i<3;i++)
	std::cin>>arr[i];
	int d;
	std::cin>>d;
	std::sort(arr, arr+3);
	std::cout<<std::max(0, (d - arr[1] + arr[0])) + std::max(0, (d - arr[2] + arr[1]))<<"\n";
	return 0;
}