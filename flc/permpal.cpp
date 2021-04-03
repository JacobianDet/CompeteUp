#include <bits/stdc++.h>

std::vector<std::vector<int> > arr(26);

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		std::string s;
		std::cin>>s;
		int z[n+1];
		memset(z, 0, sizeof(z));
		for(int i=1;i<=n;i++)
		arr[s[i-1]-'a'].pb(i);
		for (int i=1;i<n/2;i++)
		{
			for(int j=0;j<26;j++)
			{
				if(arr[j].size() >= 2)
				{	
					z[i] = arr[j][0];
					
					
			}	
		}
	}	
}