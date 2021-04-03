#include <bits/stdc++.h>

int main(void)
{
	int n;
	std::cin>>n;
	std::string s;
	std::cin>>s;
	std::string ans;
	bool ok = 0;
	for(int i=0;i<n;i++)
	{
		std::string x;
		int ctx[26];
		memset(ctx, 0, sizeof(ctx));
		for(int j=1;j<=n-i;j++)
		{
			x += s[i+j-1];
			ctx[s[i+j-1] - 97]++;
			bool iok = 1;
			for(int k=0;k<26;k++)
			{
				if(ctx[k] > j/2)
				{
					iok = 0;
					break;
				}
			}	
			if(iok)
			{
				ok = 1;
				ans = x;
				break;
			}	
		}	
		if(ok)
		break;	
	}
	if(ok)
	std::cout<<"YES\n"<<ans<<"\n";
	else std::cout<<"NO\n";
	return 0;	
}