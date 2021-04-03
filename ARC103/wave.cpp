#include <bits/stdc++.h>

int arr[100001];
std::map<int, int> mx1, mx2;
std::set<int> od, ev;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	for(int i=0;i<n;i+=2)
	mx1[arr[i]]++;
	for(int i=1;i<n;i+=2)
	mx2[arr[i]]++;	
	int mval1 = 0, mval2 = 0, tc = 0;
	for(std::map<int, int>::iterator it = mx1.begin();it != mx1.end();it++)
	{
		if(mval1 < it->second)
		{
			ev.clear();
			ev.insert(it->first);
			mval1 = it->second;
		}	
		else if(mval1 == it->second)
		ev.insert(it->first);
		tc += (it->second);	
	}
	for(std::map<int, int>::iterator it = mx2.begin();it != mx2.end();it++)
	{
		if(mval2 < it->second)
		{
			od.clear();
			od.insert(it->first);
			mval2 = it->second;
		}
		else if(mval2 == it->second)
		od.insert(it->first);
		tc += (it->second);	
	}	
	if((int)od.size() > (int)ev.size())
	{	
		int x = *ev.begin();
		int y = 0;
		for(std::set<int>::iterator it = od.begin();it != od.end();it++)
		{
			if(x != *it)
			{
				y = *it;
				break;
			}
		}
	}	
	else
	{
		int x = *od.begin();
		int y = 0;
		for(std::set<int>::iterator it = ev.begin();it != ev.end();it++)
		{
			if(x != *it)
			{
				y = *it;
				break;
			}	
		}	
		if(!y)
		{
			int smval1 = 0, smval2 = 0;
			for(std::map<int, int>::iterator it = mx1.begin();it != mx1.end();it++)
			{
				if((it->second < mval1) && (it->second > smval1))
				smval1 = it->second;	
			}
			for(std::map<int, int>::iterator it = mx2.begin();it != mx2.end();it++)
			{
				if((it->second < mval2) && (it->second > smval2))
				smval2 = it->second;	
			}		
			if(smval1 > smval2)
			mval1 = smval1;
			else mval2 = smval2;
		}	
	}
	std::cout<<(tc - mval1 - mval2)<<"\n";
	return 0;
}