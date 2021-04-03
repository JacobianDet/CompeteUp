#include <bits/stdc++.h>

struct cmp
{
	bool operator()(const std::string& str1, const std::string& str2)
	{
		return str1 < str2;
	}
};

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string s;
	int k;
	std::cin>>s>>k;
	std::set<std::string, cmp> Z;
	for(int i=1,j=(int)s.size();i<=j;i++)
	{
		for(int t=0;t<j-i+1;t++)
		Z.insert(s.substr(t, i));
	}	
	int ctr = 0;
	for(std::set<std::string, cmp>::iterator it = Z.begin();it != Z.end();it++)
	{
		ctr++;
		if(ctr == k)
		{
			std::cout<<*it<<"\n";
			break;
		}	
	}
	return 0;
}
