#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::string s[n];
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	std::vector<int> uni[m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[j][i] == '1')
			uni[i].pb(j);	
		}	
	}
	bool mark[n];
	memset(mark,0,sizeof(mark));
	int ctr = 0;
	for(int i=0;i<m;i++)
	{
		int k = (int)uni[i].size();
		if(k == 1)
		{	
			if(!mark[uni[i][0]])
			{	
				mark[uni[i][0]] = 1;
				ctr++;
			}	
		}		
	}	
	for(int i=0;i<m;i++)
	{
		int k = (int)uni[i].size();
		if(k != 1)
		{
			bool ok = 1;
			for(int j=0;j<k;j++)
			{
				if(mark[uni[i][j]])
				{
					ok = 0;
					break;
				}
			}
			if(ok)
			{
				mark[uni[i][0]] = 1;
				ctr++;
			}		
		}	
	}
	if(ctr != n)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}