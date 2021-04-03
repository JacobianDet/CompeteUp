#include <bits/stdc++.h>

/* d,f = LEFT
   j,k = RIGHT */

std::map<std::string, int> msi;
std::string s[101];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=0;i<n;i++)
		std::cin>>s[i];
		int tot = 0;
		for(int i=0;i<n;i++)
		{
			int ctz = 0;
			if(!msi[s[i]])
			{	
				for(int j=0,k=(int)s[i].size();j<k;j++)
				{
					if(!j)
					ctz += 2;
					else
					{
						if((((s[i][j] == 'd') || (s[i][j] == 'f')) && ((s[i][j-1] == 'j') || (s[i][j-1] == 'k')) || ((s[i][j] == 'j') || (s[i][j] == 'k')) && ((s[i][j-1] == 'd') || (s[i][j-1] == 'f'))))
						ctz += 2;
						else if((((s[i][j] == 'd') || (s[i][j] == 'f')) && ((s[i][j-1] == 'd') || (s[i][j-1] == 'f'))) || (((s[i][j] == 'j') || (s[i][j] == 'k')) && ((s[i][j-1] == 'j') || (s[i][j-1] == 'k'))))
					    ctz += 4;
					}
				}
				msi[s[i]] = ctz;
				tot += ctz;
			}		
			else tot += (msi[s[i]] >> 1);
		}
		std::cout<<tot<<"\n";
		msi.clear();	
	}
	return 0;
}