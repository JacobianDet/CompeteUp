#include <bits/stdc++.h>
#define mp std::make_pair

std::pair<int, int> arr[5001];

bool cmpx(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}

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
	std::sort(arr, arr+n, cmpx);
	int lv1 = arr[0].first;
	for(int i=1;i<n;i++)
	{
		if(arr[i].second >= lv1)
		lv1 = arr[i].second;
		else lv1 = arr[i].first;	
	}
	int lv2 = arr[0].second;
	for(int i=1;i<n;i++)
	{
		if(arr[i].second >= lv2)
		lv2 = arr[i].second;
		else lv2 = arr[i].first;	
	}	
	std::cout<<std::min(lv1, lv2)<<"\n";
	return 0;
}