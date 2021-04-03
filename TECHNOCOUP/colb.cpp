#include <bits/stdc++.h>
#define pb push_back
#define CHOR 200001

std::vector<std::vector<int> > G(CHOR);
std::vector<int> col(CHOR);
int degx = 0;

void dfs_visit(int s, int p)
{
	bool cx[degx+1];
	memset(cx,0,sizeof(cx));
	cx[col[s]] = 1;
	cx[col[p]] = 1;
	for(int i=0,c=1,j=G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		{
			if(cx[c])
			{
				if(col[s] > col[p])
				{
					if(cx[col[p]+1])
					c = col[s] + 1;
					else c = col[p]+1;	
				}	
				else 
				{
					if(cx[col[s]+1])
				    c = col[p] + 1;	
					else c = col[s] + 1;
				}	
			}	
			col[G[s][i]] = c;
			cx[c] = 1;
			dfs_visit(G[s][i], s);
			c++;
		}			
	}	
	return;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	for(int i=1;i<=n;i++)
	degx = std::max(degx, (int)G[i].size());
	degx++;	
	std::cout<<degx<<"\n";
	col[1] = 1;
	dfs_visit(1, 0);
	for(int i=1;i<=n;i++)
	std::cout<<col[i]<<" ";
	std::cout<<"\n";	
	return 0;
}