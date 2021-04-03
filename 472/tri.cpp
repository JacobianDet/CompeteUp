#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	std::vector<int> Z;
	int ct = 0;
	for(int i=0;i<n-1;i++)
	{
		if((s[i] != '?') && (s[i] == s[i+1]))
		ct++;	
	}	
	for(int i=0;i<n;i++)
	{
		if(s[i] == '?')
		Z.pb(i);	
	}	
	if(ct || !((int)Z.size()))
	std::cout<<"No\n";
	else 
	{
		int ans = 1;
		for(int i=0,j=(int)Z.size();i<j;i++)
		{
			int u = Z[i];
			if(u > 0 && u < n-1)
			{
				if(s[u-1] == '?' || s[u+1] == '?')
				{
					ans = 2;
					//std::cout<<"a\n";
					break;
				}
				else if(s[u-1] == s[u+1])
				{
					ans = 2;
					//std::cout<<"b\n";
					break;
				}
				else ans *= 1;	
			}	
			else 
			{
				ans = 2;
				//std::cout<<"c\n";
				break;
			}
			//std::cout<<ans<<"\n";	
		}	
		if(ans == 2)
		std::cout<<"Yes\n";
		else std::cout<<"No\n";
	}	
	return 0;	
}