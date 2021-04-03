#include <bits/stdc++.h>
#define mp std::make_pair

std::set<std::pair<int, int> > Z;

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		Z.clear();
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			std::cin>>x;
			Z.insert(mp(x, i));
		}
		int pp = 0;
		while(!Z.empty())
		{
			std::pair<int, int> px = *Z.begin();
			Z.erase(Z.begin());
			if(pp >= px.first)
			pp++;	
		}	
		std::cout<<pp<<"\n";
	}
	return 0;
}