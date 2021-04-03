#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s1,s2;
	std::cin>>s1>>s2;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		if(s1[i] != s2[i])
		{
			if((i<n) && (s1[i+1] != s2[i+1]) && (s1[i+1] != s1[i]))
			{
				ans++;
				i++;
			}	
			else ans++;
		}
	}
	std::cout<<ans<<"\n";
	return 0;
}