#include <bits/stdc++.h>
#define pb push_back
#define mp std::make_pair

typedef long long ll;

ll arr[500001], sze[500001], pop[500001], inpop[500001];
bool des[500001];
std::pair<int, int> E[500001];
ll ans[500001];

struct tr3
{
	char c;
	ll a,b;
}Q[500001];

class dsu
{
	public: ll root(int x);
			void find_union(int x, int y);
};

ll dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(sze[ry] > sze[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	sze[rx] += sze[ry];
	pop[rx] += pop[ry];
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,m,q;
	std::cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	std::cin>>inpop[i];
	for(int i=1;i<=m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		E[i] = mp(s, d);
	}	
	for(int i=1;i<=q;i++)
	{
		char x;
		std::cin>>x;
		ll a = 0, b = 0;
		if(x == 'D')
		{	
			std::cin>>a;
			des[a] = 1;
		}	
		else 
		{
			std::cin>>a>>b;
			int tx = inpop[a];
			inpop[a] = b;
			b = (tx - b);
		}	
		Q[i] = {x, a, b};
	}	
	dsu T;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
		pop[i] = inpop[i];
	}	
	for(int i=1;i<=m;i++)
	{
		if(!des[i])
		T.find_union(E[i].first, E[i].second);
	}	
	std::set<std::pair<ll, int> > LD;
	for(int i=1;i<=n;i++)
	LD.insert(mp(pop[T.root(i)], T.root(i)));
	for(int i=q;i>0;i--)
	{
		std::pair<ll, int> p = *LD.rbegin();
		ans[i] = p.first;
		tr3 z = Q[i];
		if(z.c == 'D')
		{
			int s = E[z.a].first;
			int d = E[z.a].second;
			LD.erase(mp(pop[T.root(s)], T.root(s)));
			LD.erase(mp(pop[T.root(d)], T.root(d)));
			T.find_union(s, d);
			LD.insert(mp(pop[T.root(s)], T.root(s)));
		}
		else
		{
			int ind = z.a;
			ll df = z.b;
			LD.erase(mp(pop[T.root(ind)], T.root(ind)));
			pop[T.root(ind)] += df;
			LD.insert(mp(pop[T.root(ind)], T.root(ind)));
		}
	}	
	for(int i=1;i<=q;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}