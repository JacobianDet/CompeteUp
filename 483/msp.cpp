#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back

std::pair<int, int> NE[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	std::string s[n];
	for(int i=0;i<n;i++)
	std::cin>>s[i];
	bool ok = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i][j] != '*')
			{
				int ctr = 0;
				for(int t=0;t<8;t++)
				{
					int u = i + NE[t].first;
					int v = j + NE[t].second;
					if(0 <= u && u < n && 0 <= v && v < m && s[u][v] == '*')
					ctr++;	
				}
				if(s[i][j] == '.')
				{
					if(ctr)
					{
						ok = 0;
						break;
					}	
				}	
				else if((s[i][j] - '0') != ctr)
				{
					ok = 0;
					break;
				}	
			}	
		}
		if(!ok)
		break;	
	}	
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}