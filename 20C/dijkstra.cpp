#include <bits/stdc++.h>
#define ll long long
#define mp std::make_pair
#define pb push_back
#define INF 1e18

std::vector<std::pair<int, ll> > G[100001];
ll del[100001];
int p[100001];

void dijkstra_find(int s, int d)
{
	for(int i=s;i<=d;i++)
	{
		del[i] = INF;
		p[i] = 0;
	}	
	del[s] = 0;
	std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int> >, std::greater<std::pair<ll, int> > > P;
	P.push(mp(0, s));
	while(!P.empty())
	{
		std::pair<int, ll> f = P.top();
		P.pop();
		int u = f.second;
		if(del[u] == INF)
		break;
		for(int i=0,j=(int)G[u].size();i<j;i++)
		{
			int v = G[u][i].first;
			if(del[v] > del[u] + G[u][i].second)
			{
				del[v] = del[u] + G[u][i].second;
				p[v] = u;
				P.push(mp(del[v], v));
			}	
		}	
	}
	return;	
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		ll w;
		std::cin>>s>>d>>w;
		G[s].pb(mp(d, w));
		G[d].pb(mp(s, w));
	}	
	dijkstra_find(1, n);
	if(del[n] == INF)
	{
		std::cout<<"-1\n";
		return 0;
	}
	int t = n;
	std::vector<int> Z;
	while(t != 0)
	{
		Z.pb(t);
		t = p[t];
	}	
	std::reverse(Z.begin(), Z.end());
	for(int i=0,j=(int)Z.size();i<j;i++)
	std::cout<<Z[i]<<" ";
	std::cout<<"\n";
	return 0;	
}