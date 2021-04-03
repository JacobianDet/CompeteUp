#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

typedef long long ll;

std::vector<ll> G[CHOR];
ll lvl[CHOR], par[CHOR], sze[CHOR];
ll P[CHOR][20];

ll dfs_visit(ll s, ll p)
{
	if(p != -1)
	{
		lvl[s] = 1 + lvl[p];
		par[s] = p;
	}	
	sze[s] = 1;
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	{
		if(G[s][i] != p)
		sze[s] += dfs_visit(G[s][i], s);	
	}	
	return sze[s];
}

class ST
{
	public: void build(ll n);
			ll query(ll s, ll k);
};

void ST::build(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;(1<<j)<=n;j++)
		P[i][j] = -1;	
	}	
	for(ll i=1;i<=n;i++)
	P[i][0] = par[i];
	for(ll j=1;(1<<j)<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];	
		}	
	}
	return;	
}

ll ST::query(ll s, ll k)
{
	ll lx = 0;
	for(lx=1;(1<<lx)<=k;lx++);
	lx--;
	for(ll i=lx;i>=0;i--)
	{
		if((k - (1<<i)) >= 0)
		{
			s = P[s][i];
			k -= (1<<i);
		}	
	}
	return s;	
}

ll LCA_find(ll p, ll q)
{
	if(lvl[p] < lvl[q])
	{
		ll tmp = p;
		p = q;
		q = tmp;
	}	
	ll lx = 0;
	for(lx=1;(1<<lx)<=lvl[p];lx++);
	lx--;
	for(ll i=lx;i>=0;i--)
	{
		if((lvl[p] - (1<<i)) >= lvl[q])
		p = P[p][i];	
	}	
	if(p == q)
	return p;	
	for(ll i=lx;i>=0;i--)
	{
		if((P[p][i] != -1) && (P[p][i] != P[q][i]))
		{
			p = P[p][i];
			q = P[q][i];
		}	
	}
	return par[p];	
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=0;i<n-1;i++)
	{
		ll s,d;
		std::cin>>s>>d;
		G[s].pb(d);
		G[d].pb(s);
	}	
	sze[1] = dfs_visit(1, -1);
	ST T;
	T.build(n);
	ll q;
	std::cin>>q;
	while(q--)
	{
		ll a,b;
		std::cin>>a>>b;
		if(a == b)
		{	
			std::cout<<n<<"\n";
			continue;
		}
		ll lca = LCA_find(a, b);
		ll dx = lvl[a] + lvl[b] - 2*lvl[lca];
		if(dx & 1)
		std::cout<<"0\n";
		else
		{
			ll axe = 0;
			if((dx>>1) <= (lvl[a] - lvl[lca]))
			axe = T.query(a, (dx>>1));
			else axe = T.query(b, (dx>>1));
			if(axe == lca)
			{
				ll p_a = T.query(a, (dx>>1)-1);
				ll p_b = T.query(b, (dx>>1)-1);
				std::cout<<(n - sze[p_a] - sze[p_b])<<"\n";
			}	
			else
			{
				ll p = 0;
				if((dx>>1) <= (lvl[a] - lvl[lca]))
				p = T.query(a, (dx>>1)-1);
				else p = T.query(b, (dx>>1)-1);
				std::cout<<(sze[axe] - sze[p])<<"\n"; 
			}	
		}		
	}
	return 0;	

}