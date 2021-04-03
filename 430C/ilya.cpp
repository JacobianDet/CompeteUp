#include <bits/stdc++.h>
#define CHOR 200001
#define pb push_back

int arr[CHOR], b1[CHOR], b2[CHOR], db[CHOR];
std::vector<int> dzero;
std::vector<std::vector<int> > G(CHOR);

void dfs_vis1(int s, int ctr, int p)
{
	ctr++;
	for(int i=0,j=(int)dzero.size();i<j;i++)
	{
		if(!(arr[s] % dzero[i]))
		db[dzero[i]]++;
	}
	for(int i=(int)dzero.size()-1;i>=0;i--)
	{
		if(db[dzero[i]] >= ctr-1)
		{	
			b1[s] = dzero[i];
			break;
		}		
	}	
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{	
		if(G[s][i] != p)
		dfs_vis1(G[s][i], ctr, s);
	}
	for(int i=0,j=(int)dzero.size();i<j;i++)
	{
		if(!(arr[s] % dzero[i]))
		db[dzero[i]]--;
	}
	return;
}

void dfs_vis2(int s, int p)
{
	for(int i=0,j=(int)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		{	
			b2[G[s][i]] = std::__gcd(b2[s], arr[G[s][i]]);
			dfs_vis2(G[s][i], s);
		}	
	}	
	return;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	b1[1] = arr[1];
	b2[1] = 0;
	for(int i=1;i*i<=arr[1];i++)
	{
		if(i*i == arr[1])
		dzero.pb(i);
		else if(!(arr[1]%i))
		{
			dzero.pb(i);
			dzero.pb(arr[1]/i);
		}	
	}
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	std::sort(dzero.begin(), dzero.end());
	dfs_vis1(1, 0, 0);
	dfs_vis2(1, 0);
	for(int i=1;i<=n;i++)
	std::cout<<std::max(b1[i], b2[i])<<" ";
	std::cout<<"\n";	
	return 0;
}