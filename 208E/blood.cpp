#include <bits/stdc++.h>
#define CHOR 100001
#define pb push_back

typedef long long ll;

std::vector<ll> G[CHOR];
ll par[CHOR], lvl[CHOR], ct[CHOR], sze[CHOR];
ll P[CHOR][20];
std::vector<std::vector<ll> > lev;
ll tz;

ll dfs_visit(ll s)
{
	tz++;
	ct[s] = tz;
	sze[s] = 1;
	if(par[s])
	lvl[s] = 1 + lvl[par[s]];
	for(ll i=0,j=(ll)G[s].size();i<j;i++)
	sze[s] += dfs_visit(G[s][i]);
	return sze[s];
}

ll bs1(ll v, ll x)
{
	ll lo = 0;
	ll hi = (ll)lev[lvl[v]].size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo)/2;
		if(lev[lvl[v]][mid] < x)
		lo = mid + 1;
		else hi = mid;	
	}	
	return lo;
}

ll bs2(ll v, ll y)
{
	ll lo = 0;
	ll hi = (ll)lev[lvl[v]].size()-1;
	while(lo < hi)
	{
		ll mid = lo + (hi -lo + 1)/2;
		if(lev[lvl[v]][mid] > y)
		hi = mid - 1;
		else lo = mid;	
	}	
	return lo;
}

class ST
{
	public: void build(ll n);
			ll query(ll v, ll p);
};

void ST::build(ll n)
{
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;(1LL<<j)<=n;j++)
		P[i][j] = -1;	
	}	
	for(ll i=1;i<=n;i++)
	P[i][0] = par[i];
	for(ll j=1;(1LL<<j)<=n;j++)
	{
		for(ll i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			P[i][j] = P[P[i][j-1]][j-1];	
		}	
	}
	return;	
}

ll ST::query(ll v, ll p)
{
	ll lx = 0;
	for(lx=1;(1LL<<lx)<=p;lx++);
	lx--;
	ll vx = v;
	for(ll i=lx;i>=0;i--)
	{
		if(((p - (1LL<<i)) >= 0) && (P[v][i] != -1))
		{ 
			v = P[v][i];
			p -= (1LL<<i);
		}		
	}	
	if(!p)
	return v;
	else return vx;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;i++)
	{	
		std::cin>>par[i];
		G[par[i]].pb(i);
	}
	tz = 0;
	for(ll i=1;i<=n;i++)
	{
		if(!par[i])
		sze[i] = dfs_visit(i);	
	}	
	ll mlev = 0;
	for(ll i=1;i<=n;i++)
	{
		if(lvl[i] > mlev)
		mlev = lvl[i];	
	}	
	lev.resize(mlev+1);
	for(ll i=1;i<=n;i++)
	lev[lvl[i]].pb(ct[i]);
	for(int i=0;i<=mlev;i++)
	{
		if(lev[i].size())
		std::sort(lev[i].begin(), lev[i].end());	
	}
	ST Z;
	Z.build(n);
	ll q;
	std::cin>>q;
	while(q--)
	{
		ll v,p;
		std::cin>>v>>p;
		ll z = Z.query(v, p);
		if(z == v)
		std::cout<<"0 ";
		else
		{
			ll a = bs1(v, ct[z]);
			ll b = bs2(v, ct[z] + sze[z] - 1);
			std::cout<<(b-a)<<" ";
		}	
	}	
	std::cout<<"\n";
	return 0;
}