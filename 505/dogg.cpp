#include <bits/stdc++.h>

int ctx[26];

int main(void)
{
	int n;
	std::string s;
	std::cin>>n>>s;
	for(int i=0;i<n;i++)
	ctx[s[i] - 'a']++;
	bool ok = 0;
	for(int i=0;i<26;i++)
	{
		if(ctx[i] >= 2)
		{
			ok = 1;
			break;
		}	
	}	
	if(ok || (n == 1))
	std::cout<<"Yes\n";
	else std::cout<<"No\n";
	return 0;	
}