#include <bits/stdc++.h>

int main(void)
{
	std::map<std::string, std::string> mss;
	mss["purple"] = "Power";
	mss["green"] = "Time";
	mss["blue"] = "Space";
	mss["orange"] = "Soul";
	mss["red"] = "Reality";
	mss["yellow"] = "Mind";
	int n;
	std::map<std::string, bool> msb;
	std::cin>>n; 
	for(int i=1;i<=n;i++)
	{
		std::string s;
		std::cin>>s;
		msb[s] = 1;
	}	
	std::cout<<(int)mss.size()-(int)msb.size()<<"\n";
	for(std::map<std::string, std::string>::iterator it = mss.begin();it != mss.end();it++)
	{
		if(!msb[it->first])
		std::cout<<it->second<<"\n";
	}	
	return 0;
}