#include <bits/stdc++.h>
#define pb push_back

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int r,c,h,v;
		std::cin>>r>>c>>h>>v;
		std::string grid[r];
		for(int i=0;i<r;i++)
		{
			std::string z;
			std::cin>>z;
			grid[i] = z;
		}	
		int cc = 0;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(grid[i][j] == '@')
				cc++;	
			}	
		}	
		if(cc%((h+1)*(v+1)))
		{
			std::cout<<"Case #"<<t<<": "<<"IMPOSSIBLE\n";
			continue;
		}
		else
		{
			std::vector<int> ptzr;
			std::vector<int> ptzc;
			bool f1 = 1, f2 = 1;
			int rctr = 0, cctr = 0;
			for(int i=0;i<r;i++)
			{	
				for(int j=0;j<c;j++)
				{
					if(grid[i][j] == '@')
					rctr++;	
				}
				if(rctr == cc/(h+1))
				{
					ptzr.pb(i+1);
					rctr = 0;
				}
				else if(rctr > cc/(h+1))
				{
					f1 = 0;
					break;
				}	
			}
			for(int j=0;j<c;j++)
			{
				for(int i=0;i<r;i++)
				{
					if(grid[i][j] == '@')
					cctr++;	
				}	
				if(cctr == cc/(v+1))
				{
					ptzc.pb(j+1);
					cctr = 0;
				}	
				else if(cctr > cc/(v+1))
				{
					f2 = 0;
					break;
				}	
			}	
			if(f1 & f2)
			{
				bool fa = 1;
				for(int i=0;i<h+1;i++)
				{
					for(int j=0;j<v+1;j++)
					{
						int rs = 0, re = 0, cs = 0, ce = 0, cnt = 0;
						if(!i)
						{
							rs = 0;
							re = ptzr[0];
						}	
						else 
						{
							rs = ptzr[i-1];
							re = ptzr[i];
						}	
						if(!j)
						{
							cs = 0;
							ce = ptzc[0];
						}	
						else 
						{
							cs = ptzc[j-1];
							ce = ptzc[j];
						}	
						for(int x=rs;x<re;x++)
						{
							for(int y=cs;y<ce;y++)
							{
								if(grid[x][y] == '@')
								cnt++;	
							}	
						}	
						if(cnt != cc/((h+1)*(v+1)))
						{
							fa = 0;
							break;
						}
					}	
				}
				if(fa)
				std::cout<<"Case #"<<t<<": "<<"POSSIBLE\n";
				else std::cout<<"Case #"<<t<<": "<<"IMPOSSIBLE\n";
			}
			else std::cout<<"Case #"<<t<<": "<<"IMPOSSIBLE\n";
		}	
	}
	return 0;	
}