#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

std::vector<int> G[200001];
int colx[200001];
std::map<std::pair<int, int>, int> cord;
int D;

void dfs_visit(int s, int p, int pc)
{
	int cl = (pc + 1)%D;
	for(auto u : G[s])
	{
		if(u != p)
		{
			colx[cord[mp(s, u)]] = cl;
			dfs_visit(u, s, cl);
			cl = (cl + 1)%D;
		}
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		cord[mp(s, d)] = i;
		cord[mp(d, s)] = i;
	}	
	std::vector<int> degs;
	for(int i=1;i<=n;i++)
	degs.pb((int)G[i].size());
	std::sort(degs.rbegin(), degs.rend());
	D = degs[k];
	dfs_visit(1, -1, 0);
	std::cout<<D<<"\n";
	for(int i=0;i<n-1;i++)
	std::cout<<colx[i]+1<<" ";
	std::cout<<"\n";
	return 0;	
}