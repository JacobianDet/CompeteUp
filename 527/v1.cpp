#include <bits/stdc++.h>

int arr[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	std::stack<int> S;
	for(int i=0;i<n;i++)
	{
		if(S.empty())
		S.push(arr[i]);
		else
		{
			int x = S.top();
			if(!(abs(x - arr[i]) & 1))
			S.pop();
			else S.push(arr[i]);	
		}	
	}
	if((int)S.size() <= 1)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}