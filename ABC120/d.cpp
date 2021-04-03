#include <bits/stdc++.h>
#define mp std::make_pair

typedef long long ll;

std::pair<int, int> E[100001];
int arr[100001], rank[100001];
ll sze[100001], ans[100001];

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
	if(rank[ry] > rank[rx])
	{
		int tmp = ry;
		ry = rx;
		rx = tmp;
	}	
	arr[ry] = rx;
	if(rank[rx] == rank[ry])
	rank[rx]++;	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m;
	std::cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		E[i] = mp(s, d);
	}
	dsu T;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		rank[i] = 0;
		sze[i] = 1;
	}
	ans[m-1] = ((1LL*n) * (n-1))/2LL;
	for(int i=m-1;i>0;i--)
	{
		int rx = T.root(E[i].first);
		int ry = T.root(E[i].second);
		T.find_union(E[i].first, E[i].second);
		if(rx != ry)
		{	
			ans[i-1] = ans[i] - (sze[rx] * sze[ry]);
			int rz = T.root(E[i].first);
			if(rz == rx)
			sze[rx] += sze[ry];
			else sze[ry] += sze[rx];	
		}
		else ans[i-1] = ans[i];	
	}
	for(int i=0;i<m;i++)
	std::cout<<ans[i]<<"\n";
	return 0;	
}