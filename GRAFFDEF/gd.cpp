#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

std::vector<int> G[100001];
int lt[100001], dsc[100001];
bool vis[100001];
int tx;

struct t3
{
	ll f,s,t;
};

t3 dfs_visit(int s, int p, int pbr, int n)
{
	vis[s] = 1;
	dsc[s] = lt[s] = ++tx;
	ll ctz = 0, br = 0, lbr = 0;
	for(auto u : G[s])
	{
		if(!vis[u])
		{
			t3 f = dfs_visit(u, s, lbr + pbr, n);
			lt[s] = std::min(lt[s], lt[u]);
			ctz += f.s;
			br += f.f;
			if(lt[u] > dsc[s])
			{	
				br += ((f.s - f.t) * (1LL*n - f.s - pbr - lbr));
				lbr += f.s;
			}		
			else lbr += f.t;
		}
		else if(u != p)
		lt[s] = std::min(lt[s], dsc[u]);	
	}	
	ctz++;
	return {br, ctz, lbr};
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m;
	std::cin>>n>>m;
	memset(dsc, 0, sizeof(dsc));
	memset(lt, 0, sizeof(lt));
	memset(vis, 0, sizeof(vis));
	tx = 0;
	if(n != 1)
	{	
		for(int i=0;i<m;i++)
		{
			int s,d;
			std::cin>>s>>d;
			G[s].pb(d);
			G[d].pb(s);
		}
		t3 p = dfs_visit(1, -1, 0, n);
		long double ans = (1.0 * p.f)/(1.0 * ((1LL*n * 1LL*(n-1))/2));
		std::cout.setf(std::ios_base::fixed);
		std::cout<<std::setprecision(5)<<ans<<"\n";
	}	
	else std::cout<<"0.00000\n";
	return 0;
}