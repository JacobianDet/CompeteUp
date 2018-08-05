#include <bits/stdc++.h>
#define mp std::make_pair
#define pb push_back
#define INF 200001

std::string s[10001];
std::vector<std::pair<int, int> > G[10001];
int d[10001];

void dijkstra_find(int x)
{
	for(int i=1;i<10001;i++)
	d[i] = INF;	
	d[x] = 0;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > P;
	P.push(mp(0, x));
	while(!P.empty())
	{
		std::pair<int, int> f = P.top();
		P.pop();
		int u = f.second;
		if(d[u] == INF)
		break;
		for(int i=0,j=G[u].size();i<j;i++)
		{
			int v = G[u][i].first;
			if(d[v] > d[u] + G[u][i].second)
			{
				d[v] = d[u] + G[u][i].second;
				P.push(mp(d[v], v));
			}	
		}	
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
	while(T--)
	{
		int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			std::cin>>s[i];
			int p;
			std::cin>>p;
			for(int j=0;j<p;j++)
			{
				int v,w;
				std::cin>>v>>w;
				G[i].pb(mp(v,w));
			}	
		}	
		int r;
		std::cin>>r;
		for(int j=0;j<r;j++)
		{
			std::string s1,s2;
			std::cin>>s1>>s2;
			int sr,de;
			for(int i=1;i<=n;i++)
			{
				if(s[i] == s1)
				sr = i;
				else if(s[i] == s2)
				de = i;	
			}	
			dijkstra_find(sr);
			std::cout<<d[de]<<"\n";
		}	
		for(int i=0;i<10001;i++)			
		G[i].clear();
	}
	return 0;	
}