#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair
#define CHOR 200001

std::vector<int> G[CHOR];
std::pair<int, int> E[CHOR];
std::vector<int> res;
int deg[CHOR];
std::map<std::pair<int, int>, bool> mark;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,k;
	std::cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
		deg[s]++;
		deg[d]++;
		E[i] = mp(s, d);
		mark[mp(s, d)] = 1;
		mark[mp(d, s)] = 1;
	}	
	std::set<std::pair<int, int> > S;
	for(int i=1;i<=n;i++)
	{
		if(deg[i])
		S.insert(mp(deg[i], i));
	}
	for(int i=m-1;i>=0;i--)
	{
		while((!S.empty()) && ((*S.begin()).first < k))
		{
			std::pair<int, int> p = *S.begin();
			S.erase(p);
			int s = p.second;
			deg[s] = 0;
			for(auto u : G[s])
			{
				if(mark[mp(s, u)] && (S.find(mp(deg[u], u)) != S.end()))
				{
					S.erase(mp(deg[u], u));
					deg[u]--;
					if(deg[u])
					S.insert(mp(deg[u], u));
					mark[mp(s, u)] = 0;
					mark[mp(u, s)] = 0;	
				}	
			}	
		}	
		res.pb((int)S.size());
		int s = E[i].first;
		int d = E[i].second;
		if(deg[s] && deg[d])
		{
			S.erase(mp(deg[s], s));
			S.erase(mp(deg[d], d));
			deg[s]--;
			deg[d]--;
			if(deg[s])
			S.insert(mp(deg[s], s));
			if(deg[d])
			S.insert(mp(deg[d], d));
			mark[mp(s, d)] = 0;
			mark[mp(d, s)] = 0;
		}	
	}
	std::reverse(res.begin(), res.end());
	for(int i=0;i<m;i++)
	std::cout<<res[i]<<"\n";
	return 0;	
}