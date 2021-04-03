#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[101];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int l,r;
		std::cin>>l>>r;
		arr[i] = mp(l, r);
	}	
	int mk, ps = 0;
	std::cin>>mk;
	for(int i=0;i<n;i++)
	{
		if(arr[i].first <= mk && arr[i].second >= mk)
		{
			ps = i;
			break;
		}	
	}	
	std::cout<<(n - ps)<<"\n";
	return 0;
}