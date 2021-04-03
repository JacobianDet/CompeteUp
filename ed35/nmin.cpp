#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	int minx=1e9;
	std::vector<int> pos;
	for(int i=0;i<n;i++)
	{
		if(a[i] < minx)
		minx = a[i];	
	}
	for(int i=0;i<n;i++)
	{
		if(a[i] == minx)
		pos.pb(i);
	}
	minx = 1e9;
	for(int i=0,j=(int)pos.size();i<j-1;i++)
	minx = std::min(minx, pos[i+1]-pos[i]);
	std::cout<<minx<<"\n";
	return 0;
}