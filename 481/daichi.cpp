#include <bits/stdc++.h>
#define pf push_front

int main(void)
{
	int n;
	std::cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::deque<int> D;
	for(int i=n-1;i>=0;i--)
	{
		if(std::find(D.begin(), D.end(), arr[i]) == D.end())
		D.pf(arr[i]);	
	}	
	std::cout<<D.size()<<"\n";
	for(std::deque<int>::iterator it = D.begin(); it != D.end(); it++)
	std::cout<<*it<<" ";
	std::cout<<"\n";	
}