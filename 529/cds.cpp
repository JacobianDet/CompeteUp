#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[200001];
int next[200001];

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		std::cin>>x>>y;
		arr[i] = mp(x, y);
	}
	int x = 1, px = -1;
	bool ok = 0;
	while(!ok || (x != 1))
	{
		ok = 1;
		if(((arr[arr[x].first].first == arr[x].second) || (arr[arr[x].first].second == arr[x].second)) && (px != arr[x].first))
		{	
			next[x] = arr[x].first;
			next[arr[x].first] = arr[x].second;
			px = arr[x].first;
			x = arr[x].second;
		}
		else if(((arr[arr[x].second].first == arr[x].first) || (arr[arr[x].second].second == arr[x].first)) && (px != arr[x].second))
		{
			next[x] = arr[x].second;
			next[arr[x].second] = arr[x].first;
			px = arr[x].second;
			x = arr[x].first;
		}		
	}
	ok = 0;
	while(!ok || (x != 1))
	{
		ok = 1;
		std::cout<<x<<" ";
		x = next[x];
	}	
	std::cout<<"\n";
}