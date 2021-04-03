#include <bits/stdc++.h>

typedef std::map<std::string, int> msi;

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	msi ctr;
	for(int i=0;i<n-1;i++)
	{
		std::string z = s.substr(i,2);
		ctr[z]++;
	}	
	std::string z;
	int mv = 0;
	for(msi::iterator it = ctr.begin(); it != ctr.end(); it++)
	{
		if(mv < it->second)
		{
			z = it->first;
			mv = it->second;
		}	
	}	
	std::cout<<z<<"\n";
	return 0;
}