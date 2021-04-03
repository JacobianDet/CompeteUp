#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	bool ok = 0;
	for(int i=0,j=(int)s.size();i<j-2;i++)
	{
		std::string t = s.substr(i, 3);
		if(t == "ABC" || t == "ACB" || t == "BAC" || t == "BCA" || t == "CBA" || t == "CAB")
		ok = 1;	
	}	
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}