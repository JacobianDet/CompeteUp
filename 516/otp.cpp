#include <bits/stdc++.h>

int ctx[26];

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	for(int i=0;i<n;i++)
	ctx[s[i] - 'a']++;
	for(int i=0;i<26;i++)
	{
		if(ctx[i])
		{
			for(int j=0;j<ctx[i];j++)
			std::cout<<(char)(i + 97);	
		}	
	}
	std::cout<<"\n";
	return 0;
}