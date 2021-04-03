#include <bits/stdc++.h>
#define pb push_back

int NE[2] = {-1, 1};
int lvl[201];
int n,k;

void bfs_visit(int s)
{
	lvl[s] = 1;
	std::queue<int> Q;
	Q.push(s);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for(int i=0;i<2;i++)
		{
			int cx = x + NE[i];
			if(0 < cx && cx <= n && lvl[cx] > lvl[x] + 1)
			{
				lvl[cx] = lvl[x] + 1;
				Q.push(cx);
			}	
		}	
	}
	return;	
}

int main(void)
{
	int t;
	std::cin>>t;
	while(t--)
	{
		for(int i=1;i<=200;i++)
		lvl[i] = 5000;	
		std::cin>>n>>k;
		std::vector<int> Z;
		for(int i=0;i<k;i++)
		{
			int m;
			std::cin>>m;
			Z.pb(m);
		}	
		for(int i=0,j=(int)Z.size();i<j;i++)
		bfs_visit(Z[i]);
		int maxx = 0;
		for(int i=1;i<=n;i++)
		maxx = std::max(maxx, lvl[i]);	
		std::cout<<maxx<<"\n";
	}	
	return 0;
}