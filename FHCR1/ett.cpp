#include <bits/stdc++.h>
#define pb push_back
#define CHOR 2001

std::vector<int> G1[CHOR];
std::vector<int> G2[CHOR];
int lab[CHOR];
std::vector<int> pre;
std::vector<int> post;

void dfs_vis1(int s)
{
	pre.pb(s);
	for(int i=0,j=(int)G1[s].size();i<j;i++)
	dfs_vis1(G1[s][i]);
	post.pb(s);
	return;	
}

void dfs_vis2(int s, int x)
{
	lab[s] = x;
	for(int i=0,j=(int)G2[s].size();i<j;i++)
	{
		if(!lab[G2[s][i]])
		dfs_vis2(G2[s][i], x);	
	}	
	return;
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		int n,k;
		std::cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			std::cin>>a>>b;
			if(a && b)
			{
				G1[i].pb(a);
				G1[i].pb(b);
			}	
			else if(a)
			G1[i].pb(a);
			else if(b)
			G1[i].pb(b);	
		}	
		dfs_vis1(1);
		for(int i=0;i<n;i++)
		{
			int a1 = pre[i], a2 = post[i];
			if(a1 != a2)
			{
				G2[a1].pb(a2);
				G2[a2].pb(a1);
			}	
		}	
		int x = 0;
		bool ok = 0;
		for(int i=1;i<=n;i++)
		{
			if(!lab[i])
			{
				x++;
				if(x > k)
				{	
					ok = 1;
					x = 1;
				}		
				dfs_vis2(i, x);		
			}	
		}
		std::cout<<"Case #"<<t<<": ";
		if(!ok && (x < k))
		std::cout<<"Impossible\n";
		else
		{
			for(int i=1;i<=n;i++)
			std::cout<<lab[i]<<" ";
			std::cout<<"\n";	
		}
		for(int i=1;i<=n;i++)
		{
			G1[i].clear();
			G2[i].clear();
			lab[i] = 0;
		}
		pre.clear();
		post.clear();	
	}
	return 0;	
}