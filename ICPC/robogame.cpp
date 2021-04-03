#include <bits/stdc++.h>

int pref[100];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(pref, 0, sizeof(pref));
		std::string s;
		std::cin>>s;
		for(int i=0,j=(int)s.size();i<j;i++)
		{
			if(s[i] != '.')
			{
				int lb = std::max(0, i - (s[i] - '0'));
				int rb = std::min(j-1, i + (s[i] - '0'));
				pref[lb]++;
				pref[rb+1]--;
			}	
		}	
		bool ok = 1;
		for(int i=0,j=(int)s.size();i<j;i++)
		{
			if(i > 0)
			pref[i] += pref[i-1];
			if(pref[i] > 1)
			{
				ok = 0;
				break;
			}
		}
		if(ok)
		std::cout<<"safe\n";
		else std::cout<<"unsafe\n";	
	}
	return 0;
}