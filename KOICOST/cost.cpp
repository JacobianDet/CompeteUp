#include <bits/stdc++.h>
#define mp std::make_pair
#define ll long long
#define MOD 1000000000

int arr[100001];
int sze[100001];

class dsu
{
	public: int root(int x)
			{
				while(x != arr[x])
				x = arr[arr[x]];
				return x;	
			}

			void find_union(int x, int y)
			{
				int rx = root(x);
				int ry = root(y);
				if(rx == ry)
				return;
				if(sze[rx] > sze[ry])
				{
					arr[ry] = rx;
					sze[rx] += sze[ry];
				}	
				else
				{
					arr[rx] = ry;
					sze[ry] += sze[rx];
				}
				return;	
			}
};

std::pair<int, int> W[100001];

int main(void)
{
	memset(arr,0,sizeof(arr));
	memset(sze,0,sizeof(sze));
	for(int i=0;i<100001;i++)
	W[i] = mp(0,0);	
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		sze[i] = 1;
	}	
	dsu T;
	ll path = 0, pv = 0;
	int mw = 0;
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		std::cin>>u>>v>>w;
		W[w] = mp(u,v);
		mw = std::max(mw, w);
	}	
	for(int i=mw;i>0;i--)
	{
		if(W[i] == mp(0,0))
		continue;	
		int u = W[i].first;
		int v = W[i].second;
		int ru = T.root(u);
		int rv = T.root(v);
		if(ru != rv)
		pv = (pv%MOD + ((ll)sze[ru]%MOD * (ll)sze[rv]%MOD)%MOD)%MOD;
		path = (path%MOD + ((ll)i%MOD * (ll)pv%MOD)%MOD)%MOD; 
		T.find_union(u, v);	
	}
	std::cout<<path<<"\n";
	return 0;	
}