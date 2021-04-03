#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	int c = 0;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || ((s[i]-'0') >= 0 && (s[i]-'0') <= 9 && (s[i]-'0') & 1))
		c++;	
	}	
	std::cout<<c<<"\n";
	return 0;
}