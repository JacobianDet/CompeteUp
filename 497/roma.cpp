#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	bool ok = 1;
	for(int i=0,j=(int)s.size();i<j;i++)
	{
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'n')
		{
			if(((i+1) >= j) || (((i+1) < j) && (s[i+1] != 'a' && s[i+1] != 'e' && s[i+1] != 'i' && s[i+1] != 'o' && s[i+1] != 'u')))
			{	
				ok = 0;
				break;
			}		
		}	
	}	
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}