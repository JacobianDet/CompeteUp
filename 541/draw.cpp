#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[10001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	int ct = 0, cn = 0;
	for(int i=0;i<n;i++)
	{
		int x,y;
		std::cin>>x>>y;
		if(!ct || arr[ct-1] != mp(x, y))
		{		
			arr[ct] = mp(x, y);
			ct++;
		}	
	}	
	for(int i=ct-1;i>0;i--)
	{
		int l1 = std::min(arr[i].first, arr[i-1].first);
		int r1 = std::max(arr[i].first, arr[i-1].first);
		int l2 = std::min(arr[i].second, arr[i-1].second);
		int r2 = std::max(arr[i].second, arr[i-1].second);
		int l = std::max(l1, l2);
		int r = std::min(r1, r2);
		if(l <= r)
		cn += (r - l + 1);
	}
	for(int i=1;i<ct-1;i++)
	{
		if(arr[i].first == arr[i].second)
		cn--;	
	}	
	if((arr[0].first != arr[0].second) || ct == 1)
	cn += 1 + std::min(arr[0].first, arr[0].second);
	else cn += std::min(arr[0].first, arr[0].second);
	std::cout<<cn<<"\n";
	return 0;	
}