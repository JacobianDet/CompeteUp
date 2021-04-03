#include <bits/stdc++.h>

int arr[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::stack<int> S;
	int ax = 0;
	for(int i=0;i<n;i++)
	{
		ax = std::max(ax, arr[i]);
		if(S.empty())
		S.push(arr[i]);
		else
		{
			int x = S.top();
			if(x == arr[i])
			{	
				S.pop();
				if(!S.empty() && S.top() < x)
				S.push(x);
			}		
			else S.push(arr[i]);	
		}
	}	
	if((int)S.size() == 0)
	std::cout<<"YES\n";
	else
	{
		if((int)S.size() == 1)
		{
			if(S.top() < ax)
			std::cout<<"NO\n";
			else std::cout<<"YES\n";	
		}
		else std::cout<<"NO\n";
	}	
	return 0;	
}