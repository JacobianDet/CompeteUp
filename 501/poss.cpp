#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

std::pair<int, int> px[101];

bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
	return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int a,b;
		std::cin>>a>>b;
		px[i] = mp(a, b);
	}	
	std::sort(px, px+n, cmp);
	std::vector<int> res;
	for(int i=1;i<=m;i++)
	{
		bool ok = 0;
		for(int j=0;j<n;j++)
		{
			if(px[j].first <= i && px[j].second >= i)
			{
				ok = 1;
				break;
			}	
		}
		if(!ok)
		res.pb(i);	
	}	
	std::cout<<(int)res.size()<<"\n";
	if((int)res.size() > 0)
	{	
		for(int i=0,j=(int)res.size();i<j;i++)
		std::cout<<res[i]<<" ";
		std::cout<<"\n";
	}	
	return 0;	
}