#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[100001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}	
	bool ok = 1;
	int mv = 1000000001;
	for(int i=0;i<n;i++)
	{
		int mx = std::max(arr[i].first, arr[i].second);
		int mn = std::min(arr[i].first, arr[i].second);
		if(mv >= mx)
		mv = mx;
		else if(mv >= mn)
		mv = mn;
		else
		{
			ok = 0;
			break;
		}	
	}
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}