#include <bits/stdc++.h>

bool comp(std::pair<int, int> a, std::pair<int, int> b)
{
	if(a.first < b.first)
	return 1;
	else if((a.first == b.first) && (a.second < b.second))
	return 1;
	else return 0;	
}

int main(void)
{
	int n;
	std::cin>>n;
	std::pair<int, int> arr[n];
	for(int i=0;i<n;i++)
	{	
		std::cin>>arr[i].first;
		arr[i].second = i;
	}
	std::sort(arr, arr+n, comp);	
	std::string s;
	std::cin>>s;
	std::priority_queue<std::pair<int, int> > ext;
	int itc = 0;
	int ans[n];
	memset(ans, 0, sizeof(ans));
	for(int i=0;i<2*n;i++)
	{
		if(s[i] == '0')
		{
			ans[i] = arr[itc].second + 1;
			ext.push(arr[itc]);
			itc++;
		}
		else
		{
			std::pair<int, int> p = ext.top();
			ext.pop();
			ans[i] = p.second + 1;
		}	
	}
	for(int i=0;i<2*n;i++)
	std::cout<<ans[i]<<" ";
	std::cout<<"\n";
	return 0;
}