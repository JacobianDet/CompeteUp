#include <bits/stdc++.h>

int main(void)
{
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	int lln = 0;
	for(int i=0;i<n;i++)
	{
		bool ok = 1;
		for(int j=i;j<n;j++)
		{
			if(s[j] != 'A' && s[j] != 'G' && s[j] != 'C' && s[j] != 'T')
			{
				ok = 0;
				break;
			}
			else lln = std::max(lln, (j - i + 1));
		}	
	}
	std::cout<<lln<<"\n";
	return 0;
}