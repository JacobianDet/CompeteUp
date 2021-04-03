#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

struct x3
{
	int s, d;
	ll w;
}E[200001];

int arr[200001], rank[200001];
ll vx[200001];

bool cmpx(x3 W, x3 X)
{
	return (W.w < X.w);
}

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);
};

int dsu::root(int x)
{
	return ((x == arr[x]) ? x : (arr[x] = root(arr[x])));
}

void dsu::find_union(int x, int y)
{
	int rx = root(x);
	int ry = root(y);
	if(rx == ry)
	return;
	if(rank[rx] < rank[ry])
	{
		int tmp = rx;
		rx = ry;
		ry = tmp;
	}
	arr[ry] = rx;
	if(rank[ry] == rank[rx])
	rank[rx]++;
	if(vx[rx] > vx[ry])
	vx[rx] = vx[ry];
	return;	
}

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	ll mc = 1000000000000000;
	for(int i=1;i<=n;i++)
	{
		std::cin>>vx[i];
		arr[i] = i;
		rank[i] = 0;
		mc = std::min(mc, vx[i]);
	}
	for(int i=0;i<m;i++)
	std::cin>>E[i].s>>E[i].d>>E[i].w;
	std::sort(E, E+m, cmpx);
	dsu T;
	ll ans = 0;
	for(int i=0;i<m;i++)
	{
		if(T.root(E[i].s) != T.root(E[i].d))
		{
			ll xc = std::max(vx[T.root(E[i].s)], vx[T.root(E[i].d)]);
			if(E[i].w < mc + xc)
			{
				ans += E[i].w;
				T.find_union(E[i].s, E[i].d);
			}	
		}
	}
	std::set<std::pair<ll, int> > S;
	for(int i=1;i<=n;i++)
	S.insert(mp(vx[T.root(i)], T.root(i)));
	while((int)S.size() > 1)
	{
		std::pair<ll, int> p1 = *S.begin();
		S.erase(S.begin());
		std::pair<ll, int> p2 = *S.begin();
		S.erase(S.begin());
		ans += (p1.first + p2.first);
		T.find_union(p1.second, p2.second);
		S.insert(mp(vx[T.root(p1.second)], T.root(p1.second)));
	}	
	std::cout<<ans<<"\n";
	return 0;
}