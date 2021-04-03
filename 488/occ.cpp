#include <bits/stdc++.h>
#define mp std::make_pair

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::pair<int, int> p1[12];
	std::pair<int, int> p2[12];
	for(int i=0;i<n;i++)
	{
		int x,y;
		std::cin>>x>>y;
		if(x > y)
		p1[i] = mp(y, x);
		else p1[i] = mp(x, y);	
	}	
	for(int i=0;i<m;i++)
	{
		int x,y;
		std::cin>>x>>y;
		if(x > y)
		p2[i] = mp(y, x);
		else p2[i] = mp(x, y);	
	}	
	std::set<int> s;
	for(int i=0;i<n;i++)
	{
		std::set<int> p;
		for(int j=0;j<m;j++)
		{
			if(p1[i] == p2[j])
			continue;
			if((p1[i].first == p2[j].first) || (p1[i].first == p2[j].second))
			p.insert(p1[i].first);
			else if((p1[i].second == p2[j].first) || (p1[i].second == p2[j].second))
			p.insert(p1[i].second);	
		}	
		if(p.size() == 2)
		{
			std::cout<<"-1\n";
			return 0;
		}
		else if(p.size() == 1)	
		s.insert(*p.begin());
	}
	for(int i=0;i<m;i++)
	{
		std::set<int> p;
		for(int j=0;j<n;j++)
		{
			if(p2[i] == p1[j])
			continue;
			if((p2[i].first == p1[j].first) || (p2[i].first == p1[j].second))
			p.insert(p2[i].first);
			else if((p2[i].second == p1[j].first) || (p2[i].second == p1[j].second))
			p.insert(p2[i].second);	
		}	
		if(p.size() == 2)
		{
			std::cout<<"-1\n";
			return 0;
		}	
		else if(p.size() == 1)
		s.insert(*p.begin());
	}	
	if(s.size() == 1)
	std::cout<<(*s.begin())<<"\n";
	else std::cout<<"0\n";
	return 0;	
}