#include <bits/stdc++.h>
#define mp std::make_pair

int b[200001];
std::map<int, int> ind;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	std::set<std::pair<int, int> > Z;	
	for(int i=1;i<=n;i++)
	{
		int x;
		std::cin>>x;
		ind[x] = i;
		Z.insert(mp(i, x));
	}
	for(int i=1;i<=n;i++)
	std::cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		std::set<std::pair<int, int> >::iterator it = Z.find(mp(ind[b[i]], b[i]));
		if(it != Z.end())
		{
			int ct = 1;
			while(Z.begin() != it)
			{
				ct++;
				Z.erase(Z.begin());
			}		
			Z.erase(it);	
			std::cout<<ct<<" ";
		}	
		else std::cout<<"0 ";
	}
	std::cout<<"\n";
	return 0;
}