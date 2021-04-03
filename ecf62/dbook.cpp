#include <bits/stdc++.h>

int arr[10001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	int dy = 0, mpg = 0;
	for(int i=0;i<n;i++)
	{
		mpg = std::max(mpg, arr[i]);
		if(mpg <= i+1)
		{
			mpg = 0;
			dy++;
		}	
	}
	std::cout<<dy<<"\n";
	return 0;
}