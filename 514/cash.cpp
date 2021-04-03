#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[100001];

int main(void)
{
	int n,l,a;
	std::cin>>n>>l>>a;
	for(int i=0;i<n;i++)
	{
		int x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}
	if(n)
	{
		int tb = arr[0].first/a;
		int tx = arr[0].first;
		for(int i=0;i<n-1;i++)
		{
			tb += (arr[i+1].first - tx - arr[i].second)/a;
			tx = arr[i+1].first;
		}	
		tb += (l - tx - arr[n-1].second)/a;
		std::cout<<tb<<"\n";
	}	
	else std::cout<<l/a<<"\n";
	return 0;
}