#include <bits/stdc++.h>
#define mp std::make_pair

bool compare(std::pair<int, int> a, std::pair<int, int> b)
{
	if(a.first < b.first)
	return true;
	else if(a.first == b.first && a.second < b.second)
	return true;
	else return false;	
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::pair<int, int> tx[n];
	for(int i=0;i<n;i++)
	{
		int a,b;
		std::cin>>a>>b;
		tx[i] = mp(a,b);
	}	
	std::sort(tx, tx+n, compare);
	int c=0,maxx = tx[0].second;
	if(tx[0].first)
	c++;
	for(int i=1;i<n;i++)
	{
		if(tx[i].first > maxx)
		c++;
		maxx = std::max(maxx, tx[i].second);	
	}
	if(maxx != m)
	c++;	
	if(c)
	std::cout<<"NO\n";
	else std::cout<<"YES\n";	
	return 0;
}