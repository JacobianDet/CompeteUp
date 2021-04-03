#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	int arr[n];
	std::multiset<int> X;
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i];
		X.insert(arr[i]);
	}
	int ctx = 0;
	for(int i=0;i<n;i++)
	{
		std::multiset<int>::iterator it = X.upper_bound(arr[i]);
		if(it != X.end())
		{
			ctx++;
			X.erase(it);
		}	
		else X.erase(X.begin());
	}	
	std::cout<<ctx<<"\n";
	return 0;
}