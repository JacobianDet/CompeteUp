#include <bits/stdc++.h>

int main(void)
{
	std::string s,t;
	std::cin>>s>>t;
	if((int)s.size() != (int)t.size())
	std::cout<<"No\n";
	else
	{
		bool ok = 0;
		for(int i=0,j=(int)s.size();i<j;i++)
		{
			if((((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')) && ((t[i] != 'a') && (t[i] != 'e') && (t[i]!= 'i') && (t[i] != 'o') && (t[i] != 'u'))) || (((t[i] == 'a') || (t[i] == 'e') || (t[i] == 'i') || (t[i] == 'o') || (t[i] == 'u')) && ((s[i] != 'a') && (s[i] != 'e') && (s[i]!= 'i') && (s[i] != 'o') && (s[i] != 'u'))))
			{
				ok = 1;
				break;
			}	
		}
		if(ok)
		std::cout<<"No\n";
		else std::cout<<"Yes\n";
	}	
	return 0;
}