#include <bits/stdc++.h>
#define pb push_back

int arr[150001], rank[150001], lb[150001], rb[150001], next[150001];

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
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	{
		arr[i] = i;
		lb[i] = i;
		rb[i] = i;
		rank[i] = 0;
		next[i] = i;
	}
	dsu T;	
	for(int i=0;i<n-1;i++)
	{
		int s,d;
		std::cin>>s>>d;
		int rx = T.root(s);
		int ry = T.root(d);
		T.find_union(s, d);
		int rz = T.root(s);
		if(rz == rx)
		{
			next[rb[rx]] = lb[ry];
			rb[rx] = rb[ry];
		}
		else
		{
			next[rb[rx]] = lb[ry];
			lb[ry] = lb[rx];
		}
	}
	int x = lb[T.root(1)];
	while(x != rb[T.root(1)])
	{
		std::cout<<x<<" ";
		x = next[x];
	}	
	std::cout<<x<<"\n";	
	return 0;
}