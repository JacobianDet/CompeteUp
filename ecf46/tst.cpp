#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::map<std::string, int> msi1;
	std::map<std::string, int> msi2;
	for(int i=0;i<n;i++)
	{
		std::string s;
		std::cin>>s;
		msi1[s]++;
	}	
	for(int i=0;i<n;i++)
	{
		std::string s;
		std::cin>>s;
		if(msi1[s] > 0)
		msi1[s]--;	
		else msi2[s]++;
	}	
	int ct = 0;
	for(std::map<std::string, int>::iterator it1 = msi1.begin();it1 != msi1.end();it1++)
	{
		for(std::map<std::string, int>::iterator it2 = msi2.begin();it2 != msi2.end();it2++)
		{
			std::string s1 = it1->first;
			std::string s2 = it2->first;
			if(((int)s1.size() == (int)s2.size()) && ((msi1[s1] > 0) && (msi2[s2] > 0)))
			{	
				int d = std::min(msi1[s1], msi2[s2]);
				msi1[s1] -= d;
				msi2[s2] -= d;
				ct += d;	
			}	
		}	
	}	
	std::cout<<ct<<"\n";
	return 0;	
}