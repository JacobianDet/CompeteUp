#include <bits/stdc++.h>

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::map<std::string, std::string> mss;
	for(int i=0;i<n;i++)
	{
		std::string s1,s2;
		std::cin>>s1>>s2;
		mss[s2] = s1;
	}	
	for(int i=0;i<m;i++)
	{
		std::string s1,s2;
		std::cin>>s1>>s2;
		std::size_t pos = s2.find(';');
		std::string z = s2.substr(0, pos);
		std::cout<<s1<<" "<<s2<<" #"<<mss[z]<<"\n";
	}
	return 0;
}