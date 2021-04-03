#include <bits/stdc++.h>

bool checkpal(std::string& s)
{
	bool ok = 1;
	int n = (int)s.size();
	for(int i=0;i<n/2;i++)
	{
		if(s[i] != s[n-1-i])
		{
			ok = 0;
			break;
		}	
	}
	return ok;
}

int main(void)
{
	std::string s;
	std::cin>>s;
	int n = (int)s.size();
	bool lock = 0;
	if(!(n & 1))
	{
		int cx[26];
		memset(cx, 0, sizeof(cx));
		for(int i=0;i<n;i++)
		cx[s[i] - 'a']++;
		for(int i=0;i<26;i++)
		{
			if(cx[i] == n)
			{
				lock = 1;
				break;
			}
		}
	}	
	else
	{
		if(n == 1)
		lock = 1;	
		else
		{
			int cx[26];
			memset(cx, 0, sizeof(cx));
			for(int i=0;i<n/2;i++)
			cx[s[i] - 'a']++;
			for(int i=0;i<26;i++)
			{
				if(cx[i] == n/2)
				{
					lock = 1;
					break;
				}
			}
		}	
	}
	if(lock)
	std::cout<<"Impossible\n";	
	else
	{
		bool ok = 0;
		for(int i=0;i<n-1;i++)
		{
			std::string s1 = s.substr(0, i+1);
			std::string s2 = s.substr(i+1);
			std::string u = s2 + s1;
			if(u != s && checkpal(u))
			{
				ok = 1;
				break;
			}
		}	
		if(ok)
		std::cout<<"1\n";
		else std::cout<<"2\n";	
	}
	return 0;
}