#include <bits/stdc++.h>
#define INF 100000001
#define pb push_back
#define mp std::make_pair

struct trx
{
	int s,d,w;
};

int WT[51][51], G[51][51], MST[51][51];
int arr[51], rank[51];
std::vector<trx> ZX;

bool cmpx(trx A, trx B)
{
	return (A.w < B.w);
}

class dsu
{
	public: int root(int x);
			void find_union(int x, int y);

};

int dsu::root(int x)
{
	return (x == arr[x]) ? x : (arr[x] = root(arr[x]));
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
	if(rank[rx] == rank[ry])
	rank[rx]++;
	return;	
}

int main(void)
{
	freopen("gas.in", "r", stdin);
	freopen("gas.txt", "w", stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<=T;t++)
	{
		ZX.clear();
		int n,m;
		std::cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i != j)
				{	
					WT[i][j] = INF;
					MST[i][j] = INF;
					G[i][j] = INF;
				}	
				else
				{
					WT[i][j] = 0;	
					MST[i][j] = 0;
					G[i][j] = 0;
				}	
			}	
		}
		for(int i=0;i<m;i++)
		{
			int s,d,w;
			std::cin>>s>>d>>w;
			ZX.pb({s, d, w});
			G[s][d] = w;
			G[d][s] = w;
			WT[s][d] = w;
			WT[d][s] = w;
		}
		std::sort(ZX.begin(), ZX.end(), cmpx);
		bool ok = 1;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				G[i][j] = std::min(G[i][j], G[i][k]+G[k][j]);
			}	
		}	
		for(int i=0;i<m;i++)
		{
			int s = ZX[i].s;
			int d = ZX[i].d;
			if((WT[s][d] != G[s][d]) || (WT[d][s] != G[d][s]))
			{
				ok = 0;
				break;
			}	
		}
		if(!ok)
		std::cout<<"Case #"<<t<<": Impossible\n";
		else
		{
			std::cout<<"Case #"<<t<<": "<<ZX.size()<<"\n";
			for(auto u : ZX)
			std::cout<<u.s<<" "<<u.d<<" "<<u.w<<"\n";
		}		
	}
	return 0;
}