#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::map<ll, bool> vis;
std::map<ll, ll> memo;

void bfs_visit(ll n, ll d)
{
	std::queue<std::pair<ll, ll> > Q;
	memo[n] = 0;
	vis[n] = 1;
	Q.push(mp(n, 0));
	int dx = 0;
	while(!Q.empty())
	{
		dx++;
		for(int i=0,j=(int)Q.size();i<j;i++)
		{
			std::pair<ll, ll> p = Q.front();
			Q.pop();
			ll u = p.first;
			ll w = p.second;
			//std::cout<<u<<" "<<w<<"\n";
			if(dx < 12)
			{
				if(u < 10)
				{
					if(!vis[u + d])
					{
						//std::cout<<u+d<<" "<<w+1<<"\n";
						vis[u + d] = 1;
						memo[u + d] = w + 1;
						Q.push(mp(u + d, memo[u + d]));
					}
				}		
				else
				{
					if(!vis[u + d])
					{
						//std::cout<<u+d<<" "<<w+1<<"\n";
						vis[u + d] = 1;
						memo[u + d] = w + 1;
						Q.push(mp(u + d, memo[u + d]));
					}
					ll tmp = u;
					ll ds = 0;
					while(tmp)
					{
						ds += (tmp % 10);
						tmp /= 10;
					}
					if(!vis[ds])
					{
						//std::cout<<ds<<" "<<w+1<<"\n";
						vis[ds] = 1;
						memo[ds] = w + 1;
						Q.push(mp(ds, memo[ds]));
					}
				}	
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
		ll n,d;
		std::cin>>n>>d;
		bfs_visit(n, d);
		for(int i=1;i<=9;i++)
		{
			if(vis[i])
			{
				std::cout<<i<<" "<<memo[i]<<"\n";
				break;
			}	
		}
		memo.clear();
		vis.clear();	
	}
	return 0;
}