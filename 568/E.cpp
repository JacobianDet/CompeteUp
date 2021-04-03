#include <bits/stdc++.h>
#define mp std::make_pair

std::string G[2000];
std::pair<int, int> fx[26], rx[26];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	while(T--)
	{
		int n,m;
		std::cin>>n>>m;
		for(int i=0;i<n;i++)
		std::cin>>G[i];
		for(int i=0;i<26;i++)
		{
			rx[i] = mp(-1, -1);
			fx[i] = mp(-1, -1);
		}	
		int x = 0;
		bool ok = 1;
		for(int k=0;k<26;k++)
		{	
			bool yor = 0, yoc = 0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(G[i][j] - 'a' == k)
					{
						if(rx[k] == mp(-1, -1))
						{
							rx[k] = mp(i, j);
							fx[k] = mp(i, j);
						}	
						else if(!yor && !yoc)
						{
							if(rx[k].first == i)
							{
								yor = 1;
								rx[k] = mp(i, j);
							}	
							else if(rx[k].second == j)
							{
								yoc = 1;
								rx[k] = mp(i, j);
							}
							else 
							{
								ok = 0;
								break;
							}	
						}
						else
						{
							if(yor && rx[k].first != i)
							{
								ok = 0;
								break;
							}
							else if(yoc && rx[k].second != j)
							{
								ok = 0;
								break;
							}
							else rx[k] = mp(i, j);	
						}
					}		
				}
				if(!ok)
				break;	
			}
			if(!ok)
			break;
		}
		if(!ok)
		std::cout<<"NO\n";
		else
		{
			for(int i=0;i<26;i++)
			{
				if(fx[i] != mp(-1, -1))
				{
					if(fx[i].first == rx[i].first)
					{
						for(int j=fx[i].second;j<=rx[i].second;j++)
						{
							if(G[fx[i].first][j] - 'a' < i)
							{
								ok = 0;
								break;
							}	
						}	
					}
					else
					{
						for(int j=fx[i].first;j<=rx[i].first;j++)
						{
							if(G[j][fx[i].second] - 'a' < i)
							{
								ok = 0;
								break;
							}	
						}	
					}	
				}
				if(!ok)
				break;	
			}
			if(!ok)
			std::cout<<"NO\n";
			else
			{
				std::cout<<"YES\n";
				std::pair<int, int> nf = mp(-1, -1), nl = mp(-1, -1);
				for(int i=25;i>=0;i--)
				{
					if(fx[i] != mp(-1, -1))
					{	
						x = std::max(x, i+1);
						nf = fx[i];
						nl = rx[i];	
					}
					else 	
					{
						fx[i] = nf;
						rx[i] = nl;
					}
				}
				std::cout<<x<<"\n";
				for(int i=0;i<x;i++)
				std::cout<<fx[i].first+1<<" "<<fx[i].second+1<<" "<<rx[i].first+1<<" "<<rx[i].second+1<<"\n";	
			}	
		}				
	}
	return 0;
}