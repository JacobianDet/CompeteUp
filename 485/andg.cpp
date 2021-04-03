#include <bits/stdc++.h>
#define CHOR (1<<22)

bool vis1[CHOR];
bool vis2[CHOR];
bool inG[CHOR];
int n;

void dfs_visit(int s)
{
	vis2[s] = 1;
	if(inG[(1<<n)-1-s] && !vis1[(1<<n)-1-s])
	{	
		vis1[(1<<n)-1-s] = 1;
		dfs_visit((1<<n)-1-s);	
	}		
	for(int i=0;i<n;i++)
	{
		if(!(s & (1<<i)))
		{	
			int t = (s | (1<<i));
			if(!vis2[t])
			dfs_visit(t);
		}			
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int t;
		std::cin>>t;
		inG[t] = 1;
	}	
	int ctr = 0;
	for(int i=0;i<(1<<n);i++)
	{
		if(inG[i] && !vis1[i])
		{	
			vis1[i] = 1;
			dfs_visit(i);
			ctr++;
		}		
	}
	std::cout<<ctr<<"\n";
	return 0;	
}